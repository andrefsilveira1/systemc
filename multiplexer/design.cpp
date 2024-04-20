#include <systemc.h>

SC_MODULE(MUX) {
    sc_in<sc_uint<32>> operand1;
    sc_in<sc_uint<32>> operand2;
    sc_in<sc_uint<32>> operand3;
    sc_in<sc_uint<2>> mux_control; // Changed to sc_uint<2> for 2-bit control
    sc_out<sc_uint<32>> result;
    sc_out<bool> zero;

    void mux_process() {
        sc_uint<32> a = operand1.read();
        sc_uint<32> b = operand2.read();
        sc_uint<32> s = operand3.read();
        sc_uint<32> output;

        switch (operand3.read()) {
            case 0:  
                output = a;
                break;
            case 1: 
                output = b;
                break;
            default:
                output = 0;
                break;
        }

        result.write(output);
        zero.write(output == 0);
    }

    SC_CTOR(MUX) {
        SC_METHOD(mux_process);
        sensitive << operand1 << operand2 << operand3 << mux_control;
    }
};
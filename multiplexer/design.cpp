#include <systemc.h>

SC_MODULE(MUX) {
    sc_in<sc_uint<32>> operand1;
    sc_in<sc_uint<32>> operand2;
    sc_in<sc_uint<32>> operand3;
    sc_in<sc_uint<3>> mux_control; // -> Check
    sc_out<sc_uint<32>> result;
    sc_out<bool> zero;

    void mux_process() {
        sc_uint<32> a = operand1.read();
        sc_uint<32> b = operand2.read();
        sc_uint<32> s = operand3.read();
        sc_uint<32> output;

        switch (mux_control.read()) {
            case 0:  
                output = a + b;
                break;
            case 1: 
                output = a - b;
                break;
            case 2:  
                output = a & b; // and
                break;
            case 3:
                output = a | b; // or
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
        sensitive << operand1 << operand2 << mux_control;
    }
};

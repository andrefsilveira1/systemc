#include <systemc.h>

SC_MODULE(Register) {
public:
    sc_in<bool> clock;      
    sc_in<bool> reset;      
    sc_in<bool> enable;     
    sc_in<sc_uint<32>> data_in;  
    sc_out<sc_uint<32>> data_out; 

    sc_uint<32> reg_data;   

    SC_CTOR(Register) : reg_data(0) {
        SC_METHOD(registerProcess);
        sensitive << clock.pos();
    }

    void registerProcess() {
        if (reset.read()) {
            reg_data = 0;
        } else if (enable.read()) {
            reg_data = data_in.read();
        }
        data_out.write(reg_data);
    }
};

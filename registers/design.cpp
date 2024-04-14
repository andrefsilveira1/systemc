#include <systemc.h>

SC_MODULE(Register) {
    sc_in<bool> clock;  
    sc_in<bool> reset;  
    sc_in<bool> enable; // operações de escrita
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


SC_MODULE(RegisterInterface) {
    std::vector<Register*> registers;

    SC_CTOR(RegisterInterface) {
        // Quantos registradores tem que ser ?
        for (int i = 0; i < 8; ++i) {
            Register* reg = new Register("register_" + std::to_string(i));
            registers.push_back(reg);
        }
    }

    sc_uint<32> readRegister(int address) {
        if (address >= 0 && address < 8) {
            return registers[address]->data_out.read();
        }
        return 0;
    }

    void writeRegister(int address, sc_uint<32> data) {
        if (address >= 0 && address < 8) {
            registers[address]->data_in.write(data);
            registers[address]->enable.write(true);
            wait();
            registers[address]->enable.write(false);
        }
    }
};

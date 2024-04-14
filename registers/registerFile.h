#include <systemc.h>
#include "Register.h" // Include Register module header

SC_MODULE(RegisterFile) {
public:
    std::vector<Register*> registers; // Vector of register instances

    // Constructor
    SC_CTOR(RegisterFile) {
        // Instantiate 32 registers (0 to 31)
        for (int i = 0; i < 32; ++i) {
            Register* reg = new Register(("register_" + std::to_string(i)).c_str());
            registers.push_back(reg);
        }
    }

    // Method to read from a specific register
    sc_uint<32> readRegister(int address) {
        if (address >= 0 && address < 32) {
            return registers[address]->data_out.read();
        }
        // Handle invalid address (e.g., return an error value)
        return 0;
    }

    // Method to write to a specific register
    void writeRegister(int address, sc_uint<32> data) {
        if (address >= 0 && address < 32) {
            registers[address]->data_in.write(data);
            registers[address]->enable.write(true);
            wait(); // Wait for one clock cycle for write operation
            registers[address]->enable.write(false);
        }
        // Handle invalid address (e.g., do nothing or log an error)
    }
};

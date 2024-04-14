#include <systemc.h>

int sc_main(int argc, char* argv[]) {
    Register regFile("register_file");

    regFile.reset = 1;

    sc_start(1, SC_NS);

    regFile.reset = 0;

    regFile.writeRegister(5, 0xABCD); 
    regFile.writeRegister(10, 0x1234);

    sc_start(10, SC_NS);

    sc_uint<32> data_5 = regFile.readRegister(5);
    sc_uint<32> data_10 = regFile.readRegister(10);

    std::cout << "Data read from register 5: " << data_5 << std::endl;
    std::cout << "Data read from register 10: " << data_10 << std::endl;

    sc_stop();

    return 0;
}

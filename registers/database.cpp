#include <systemc.h>

SC_MODULE(RegisterBank) {
public:
  sc_in<sc_uint> reg_id;
  sc_in<sc_uint> data_in;
  sc_out<sc_uint> data_out;

  sc_uint registers[MAX_REGISTERS];

  SC_CTOR(RegisterBank) {
    SC_METHOD(registerBankProcess);
    sensitive << reg_id.pos();
  }
}
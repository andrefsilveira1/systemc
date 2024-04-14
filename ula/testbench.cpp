#include <systemc.h>
#include <iostream>
#include "design.cpp"

int sc_main(int argc, char* argv[]) {
    sc_signal<sc_uint<32>> operand1;
    sc_signal<sc_uint<32>> operand2;
    sc_signal<sc_uint<3>> alu_control;

    sc_signal<sc_uint<32>> result;
    sc_signal<bool> zero;

    ALU alu("alu");
    alu.operand1(operand1);
    alu.operand2(operand2);
    alu.alu_control(alu_control);
    alu.result(result);
    alu.zero(zero);

    sc_trace_file *wf = sc_create_vcd_trace_file("alu_waveforms");
    sc_trace(wf, operand1, "operand1");
    sc_trace(wf, operand2, "operand2");
    sc_trace(wf, alu_control, "alu_control");
    sc_trace(wf, result, "result");
    sc_trace(wf, zero, "zero");

    operand1 = 15;
    operand2 = 10;
    alu_control = 0;


    sc_start(1, SC_NS);  // init

    std::cout << "@" << sc_time_stamp() << " Starting...\n";
    std::cout << "Operand1: " << operand1 << std::endl;
    std::cout << "Operand2: " << operand2 << std::endl;
    std::cout << "Signal Control: " << alu_control << std::endl;

    sc_start(1, SC_NS);
    std::cout << "@" << sc_time_stamp() << " Operation terminated \n";

    std::cout << "ALU Result: " << result << std::endl;
    std::cout << "Zero Flag: " << zero << std::endl;

    // Close VCD trace file
    sc_close_vcd_trace_file(wf);

    return 0;
}

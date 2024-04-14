#include <systemc.h>
#include <iostream>
#include "design.cpp"

int sc_main(int argc, char* argv[]) {
    // Signals for ALU inputs and control
    sc_signal<sc_uint<32>> operand1;
    sc_signal<sc_uint<32>> operand2;
    sc_signal<sc_uint<3>> alu_control;
    // Signals for ALU outputs
    sc_signal<sc_uint<32>> result;
    sc_signal<bool> zero;

    // Instantiate the ALU
    ALU my_alu("my_alu");
    my_alu.operand1(operand1);
    my_alu.operand2(operand2);
    my_alu.alu_control(alu_control);
    my_alu.result(result);
    my_alu.zero(zero);

    // Open VCD file for tracing
    sc_trace_file *wf = sc_create_vcd_trace_file("alu_waveforms");
    sc_trace(wf, operand1, "operand1");
    sc_trace(wf, operand2, "operand2");
    sc_trace(wf, alu_control, "alu_control");
    sc_trace(wf, result, "result");
    sc_trace(wf, zero, "zero");

    // Initialize input values
    operand1 = 15;
    operand2 = 10;
    alu_control = 0;  // Set ALU control to 0 (addition)

    // Run the simulation
    sc_start(1, SC_NS);  // Initialize simulation

    // Display initial values
    std::cout << "@" << sc_time_stamp() << " Starting ALU simulation\n";
    std::cout << "Operand1: " << operand1 << std::endl;
    std::cout << "Operand2: " << operand2 << std::endl;
    std::cout << "ALU Control: " << alu_control << std::endl;

    // Perform ALU operation
    sc_start(1, SC_NS);  // Execute one time step
    std::cout << "@" << sc_time_stamp() << " ALU operation completed\n";

    // Display result
    std::cout << "ALU Result: " << result << std::endl;
    std::cout << "Zero Flag: " << zero << std::endl;

    // Close VCD trace file
    sc_close_vcd_trace_file(wf);
  
  
   	operand1 = 15;
    operand2 = 10;
    alu_control = 1;


    sc_start(1, SC_NS);  // init

    std::cout << "@" << sc_time_stamp() << " Starting...\n";
    std::cout << "Operand1: " << operand1 << std::endl;
    std::cout << "Operand2: " << operand2 << std::endl;
    std::cout << "Signal Control: " << alu_control << std::endl;

    sc_start(1, SC_NS);
    std::cout << "@" << sc_time_stamp() << " Operation terminated \n";

    std::cout << "ALU Result: " << result << std::endl;
    std::cout << "Zero Flag: " << zero << std::endl;
  
  
   	operand1 = 1;
    operand2 = 0;
    alu_control = 2;


    sc_start(1, SC_NS);  // init

    std::cout << "@" << sc_time_stamp() << " Starting...\n";
    std::cout << "Operand1: " << operand1 << std::endl;
    std::cout << "Operand2: " << operand2 << std::endl;
    std::cout << "Signal Control: " << alu_control << std::endl;

    sc_start(1, SC_NS);
    std::cout << "@" << sc_time_stamp() << " Operation terminated \n";

    std::cout << "ALU Result: " << result << std::endl;
    std::cout << "Zero Flag: " << zero << std::endl;
  
  	operand1 = 0;
    operand2 = 1;
    alu_control = 2;


    sc_start(1, SC_NS);  // init

    std::cout << "@" << sc_time_stamp() << " Starting...\n";
    std::cout << "Operand1: " << operand1 << std::endl;
    std::cout << "Operand2: " << operand2 << std::endl;
    std::cout << "Signal Control: " << alu_control << std::endl;

    sc_start(1, SC_NS);
    std::cout << "@" << sc_time_stamp() << " Operation terminated \n";

    std::cout << "ALU Result: " << result << std::endl;
    std::cout << "Zero Flag: " << zero << std::endl;
  
   	operand1 = 0;
    operand2 = 1;
    alu_control = 3;


    sc_start(1, SC_NS);  // init

    std::cout << "@" << sc_time_stamp() << " Starting...\n";
    std::cout << "Operand1: " << operand1 << std::endl;
    std::cout << "Operand2: " << operand2 << std::endl;
    std::cout << "Signal Control: " << alu_control << std::endl;

    sc_start(1, SC_NS);
    std::cout << "@" << sc_time_stamp() << " Operation terminated \n";

    std::cout << "ALU Result: " << result << std::endl;
    std::cout << "Zero Flag: " << zero << std::endl;

    return 0;
}

#include <iostream>
#include <cassert>
#include "constants.hpp"
#include "instruction.hpp"

using namespace std;


int main() {
    // Initialize an instruction to all 1's, and
    // test each field. Then, print instruction.
    Instruction i(0xffffffff);
    cout << i.dump() << endl;
    cout << i.opcode().to_ulong() << "\t"
         << i.opcode().to_string() << endl;
    assert (i.opcode().to_ulong() == 0x3f);
    cout <<"op checked" << endl;
    // Asserts for the other fields
    // You can insert more debug statements if any of
    // these fail.
    assert (i.rs().to_ulong() == 0x1f);
    cout << "rs checked" << endl;
    assert (i.rt().to_ulong() == 0x1f);
    cout << "rt checked" << endl;
    assert (i.rd().to_ulong() == 0x1f);
    cout << "rd checked" << endl;
    assert (i.shamt().to_ulong() == 0x1f);
    cout << "shift checked" << endl;
    assert (i.funct().to_ulong() == 0x3f);
    cout << "function checked" << endl;
    assert (i.imm().to_ulong() == 0xffff);
    cout << "immediate checked" << endl;
    assert (i.jmp_offset().to_ulong() == 0x3ffffff);
    cout << "jmp checked" << endl;
    
    cout << endl << "print begin" << endl;
    // Print instruction
    cout << i.to_string() << endl;
    cout << "testing";
    assert (i.to_string() == "INVALID OPCODE");
    cout << "-> tested" << endl;
    cout << "print end" << endl;

    // 32 bits of 0 = SLL $zero, $zero, 0
    Instruction i2(0);
    cout << endl << "created i2" << endl;
    cout << i2.to_string() << endl;
    assert(i2.to_string() == "SLL $zero, $zero, 0");

    // How to build a general-purpose instruction
    // This one is ADDI $s0, $s1, -1
    Instruction i3(0x08 << 26 | 17 << 21 | 16 << 16 | 0xffff);
    cout << endl << "created i3" << endl;
    cout << i3.to_string() << endl;
    assert(i3.to_string() == "ADDI $s0, $s1, -1");

    cout << "All asserts OK" << endl;
    return 0;
}

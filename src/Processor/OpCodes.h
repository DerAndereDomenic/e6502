#ifndef __E6502_PROCESSOR_OPCODES_H
#define __E6502_PROCESSOR_OPCODES_H

#include <Core/Defines.h>

namespace E6502
{
    enum AddressingModes
    {
        //Opcodes cc=01
        ZERO_PAGE_X_INDIRECT_01 = 0b000,
        ZERO_PAGE_01 = 0b001,
        IMMEDIATE_01 = 0b010,
        ABSOLUTE_01 = 0b011,
        ZERO_PAGE_Y_INDIRECT_01 = 0b100,
        ZERO_PAGE_X_01 = 0b101,
        ABSOLUTE_Y_01 = 0b110,
        ABSOLUTE_X_01 = 0b111,

        //Opcodes cc=10
        IMMEDIATE_10 = 0b000,
        ZERO_PAGE_10 = 0b001,
        ACCUMULATOR_10 = 0b010,
        ABSOLUTE_10 = 0b011,
        ZERO_PAGE_X_10 = 0b101,
        ABSOLUE_X_10 = 0b111,

        //Opcodes cc=00
        IMMEDIATE_00 = 0b000,
        ZERO_PAGE_00 = 0b001,
        ABSOLUTE_00 = 0b011,
        ZERO_PAGE_X_00 = 0b101,
        ABSOLUTE_X_00 = 0b111,
    };

    /*enum OpCodes
    {
        //ADC (ADd with Carry)
        ADC = 0x61,

        //AND (bitwise AND with accumulator)
        AND = 0x21,

        //ASL (Arithmetic Shift Left)
        ASL = 0x02,

        //BIT (test BITs)
        BIT = 0x20,

        //CMP (CoMPare accumulator)
        CMP = 0xC1,

        //CPX (ComPare X register)
        CPX = 0xE0,

        //CPY (ComPare Y register)
        CPY = 0xC0,

        //DEC (DECrement memory)
        DEC = 0xC2,

        //EOR (bitwise Exclusive OR)
        EOR = 0x41,

        //INC (INCrement memory)
        INC = 0xE2,

        //JMP (JuMP)
        JMP = 0x40,

        //JSR (Jump to SubRoutine)
        JSR = 0x20,

        //LDA (LoaD Accumulator)
        LDA = 0xA1,

        //LDX (LoaD X register)
        LDX = 0xA2,

        //LDY (LoaD Y register)
        LDY = 0xA0,

        //LSR (Logical Shit Right)
        LSR = 0x42,

        //ORA (bitwise OR with Accumulator)
        ORA = 0x01,

        //ROL (ROtate Left)
        ROL = 0x22,

        //ROR (ROtate Right)
        ROR = 0x62,

        //SBC (SuBtract with Carry)
        SBC = 0xE1,

        //STA (STore Accumulator)
        STA = 0x81,

        //STX (STore X register)
        STX = 0x82,

        //STY (STore Y register)
        STY = 0x80,

    };*/

    /// An enum storing the opcodes of the 6502 instruction set
    /// For naming convention:
    /// XXX_AC    - Operation XXX Accumulator
    /// XXX_I  - Operation XXX Intermediate
    /// XXX_Z  - Operation XXX from Zero page
    /// XXX_ZX - Operation XXX from Zero page, X
    /// XXX_A  - Operation XXX Absolute
    /// XXX_AX - Operation XXX Absolute, X
    /// XXX_AY - Operation XXX Absolute, Y
    /// XXX_IX - Operation XXX Indirect, X
    /// XXX_IY - Operation XXX Indirect, Y
    enum OpCodesAdressed
    {
        //ADC (ADd with Carry)
        ADC_I = 0x69,
        ADC_Z = 0x65,
        ADC_ZX = 0x75,
        ADC_A = 0x6D,
        ADC_AX = 0x7D,
        ADC_AY = 0x79,
        ADC_IX = 0x61,
        ADC_IY = 0x71,

        //AND (bitwise AND with accumulator)
        AND_I = 0x29,
        AND_Z = 0x25,
        AND_ZX = 0x35,
        AND_A = 0x2D,
        AND_AX = 0x3D,
        AND_AY = 0x39,
        AND_IX = 0x21,
        AND_IY = 0x31,

        //ASL (Arithmetic Shift Left)
        ASL_AC = 0x0A,
        ASL_Z = 0x06,
        ASL_ZX = 0x16,
        ASL_A = 0x0E,
        ASL_AX = 0x1E,

        //BIT (test BITs)
        BIT_Z = 0x24,
        BIT_A = 0x2C,

        //Branch instructions
        BPL = 0x10,
        BMI = 0x30,
        BVC = 0x50,
        BVS = 0x70,
        BCC = 0x90,
        BCS = 0xB0,
        BNE = 0xD0,
        BEQ = 0XF0,

        //BRK
        BRK = 0x00,

        //CMP (CoMPare accumulator)
        CMP_I = 0xC9,
        CMP_Z = 0xC5,
        CMP_ZX = 0xD5,
        CMP_A = 0xCD,
        CMP_AX = 0xDD,
        CMP_AY = 0xD9,
        CMP_IX = 0xC1,
        CMP_IY = 0xD1,

        //CPX (ComPare X register)
        CPX_I = 0xE0,
        CPX_Z = 0xE4,
        CPX_A = 0xEC,

        //CPY (ComPare Y register)
        CPY_I = 0xC0,
        CPY_Z = 0xC4,
        CPY_A = 0xCC,

        //DEC (DECrement memory)
        DEC_Z = 0xC6,
        DEC_ZX = 0xD6,
        DEC_A = 0xCE,
        DEC_AX = 0xDE,

        //EOR (bitwise Exclusive OR)
        EOR_I = 0x49,
        EOR_Z = 0x45,
        EOR_ZX = 0x55,
        EOR_A = 0x4D,
        EOR_AX = 0x5D,
        EOR_AY = 0x59,
        EOR_IX = 0x41,
        EOR_IY = 0x51,

        //Flag (Processor Status) Instructions
        CLC = 0x18,
        SEC = 0x38,
        CLI = 0x58,
        SEI = 0x78,
        CLV = 0xB8,
        CLD = 0xD8,
        SED = 0xF8,

        //INC (INCrement memory)
        INC_Z = 0xE6,
        INC_ZX = 0xF6,
        INC_A = 0xEE,
        INC_AX = 0xFE,

        //JMP (JuMP)
        JMP_A = 0x4C,
        JMP_I = 0x6C,

        //JSR (Jump to SubRoutine)
        JSR_A = 0x20,

        //LDA (LoaD Accumulator)
        LDA_I = 0xA9,
        LDA_Z = 0xA5,
        LDA_ZX = 0xB5,
        LDA_A = 0xAD,
        LDA_AX = 0xBD,
        LDA_AY = 0xB9,
        LDA_IX = 0xA1,
        LDA_IY = 0xB1,

        //LDX (LoaD X register)
        LDX_I = 0xA2,
        LDX_Z = 0xA6,
        LDX_ZY = 0xB6,
        LDX_A = 0xAE,
        LDX_AY = 0xBE,

        //LDY (LoaD Y register)
        LDY_I = 0xA0,
        LDY_Z = 0xA4,
        LDY_ZX = 0xB4,
        LDY_A = 0xAC,
        LDY_AX = 0xBC,

        //LSR (Logical Shit Right)
        LSR_AC = 0x4A,
        LSR_Z = 0x46,
        LSR_ZX = 0x56,
        LSR_A = 0x4E,
        LSR_AX = 0x5E,

        //NOP (No OPeration)
        NOP = 0xEA,

        //ORA (bitwise OR with Accumulator)
        ORA_I = 0x09,
        ORA_Z = 0x05,
        ORA_ZX = 0x15,
        ORA_A = 0x0D,
        ORA_AX = 0x1D,
        ORA_AY = 0x19,
        ORA_IX = 0x01,
        ORA_IY = 0x11,

        //Register Instructions
        TAX = 0xAA,
        TXA = 0x8A,
        DEX = 0xCA,
        INX = 0xE8,
        TAY = 0xA8,
        TYA = 0x98,
        DEY = 0x88,
        INY = 0xC8,

        //ROL (ROtate Left)
        ROL_AC = 0x2A,
        ROL_Z = 0x26,
        ROL_ZX = 0x36,
        ROL_A = 0x2E,
        ROL_AX = 0x3E,

        //ROR (ROtate Right)
        ROR_AC = 0x6A,
        ROR_Z = 0x66,
        ROR_ZX = 0x76,
        ROR_A = 0x6E,
        ROR_AX = 0x7E,

        //RTI (ReTurn from Interrupt)
        RTI = 0x40,

        //RTS (ReTurn from Subroutine)
        RTS = 0x60,

        //SBC (SuBtract with Carry)
        SBC_I = 0xE9,
        SBC_Z = 0xE5,
        SBC_ZX = 0xF5,
        SBC_A = 0xED,
        SBC_AX = 0xFD,
        SBC_AY = 0xF9,
        SBC_IX = 0xE1,
        SBC_IY = 0xF1,

        //STA (STore Accumulator)
        STA_Z = 0x85,
        STA_ZX = 0x95,
        STA_A = 0x8D,
        STA_AX = 0x9D,
        STA_AY = 0x99,
        STA_IX = 0x81,
        STA_IY = 0x91,

        //Stack Instructions
        TXS = 0x9A,
        TSX = 0xBA,
        PHA = 0x48,
        PLA = 0x68,
        PHP = 0x08,
        PLP = 0x28,

        //STX (STore X register)
        STX_Z = 0x86,
        STX_ZY = 0x96,
        STX_A = 0x8E,

        //STY (STore Y register)
        STY_Z = 0x84,
        STY_ZX = 0x94,
        STY_A = 0x8C,

    };
}

#endif
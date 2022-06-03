//8-bit Registers

#define MMODE_8 0xE700 //ACCMODE, (R/W) Default: 0x1C, Unsigned, Measurement mode register
#define ACCMODE_8 0xE701 //ACCMODE, (R/W) Default: 0x80, Unsigned, Accumulation Mode
#define LCYCMODE_8 0xE702 //LCYCMODE_8, (R/W) Default: 0x78, Unsigned, Line Accumulation Mode
#define PEAKCYC_8 0xE703 //PEAKCYC_8, (R/W) Default: 0x00, Unsigned, Peak detection half line cycles
#define SAGCYC_8 0xE704 //SAGCYC, (R/W) Default: 0x00, Unsigned, Sag lines Cycle 
#define CFCYC_8 0xE705 //CFCYC, (R/W) Default: 0x01, Unsigned, Number of CF pulses between two consecutive energy latches. 
#define HSDC_CFG_8 0xE706 //HSDC_CFG, (R/W) Default: 0x00, Unsigned, HSDC configuration register. 
#define Version_8 0xE707 //Version, (R), Unsigned, Version of die. 
#define Reserved _8 0xE7E4 //Reserved, (R) Default: 0x08, Unsigned, Checksum register. 
#define LAST_RWDATA8_8 0xE7FD //LAST_RWDATA8, (R), Unsigned, Data from the last successful 8-bit register communication. 
#define CONFIG3_8 0xEA00 //CONFIG3, (R/W) Default: 0x01, Unsigned, Configuration register. 
#define LAST_OP_8 0xEA01 //LAST_OP, (R), Unsigned, Type, read or write, of the last successful read/write operation 
#define WTHR_8 0xEA02 //WTHR, (R/W) Default: 0x03, Unsigned, Threshold used in phase total/fundamental active power data path. 
#define VARTHR_8 0xEA03 //VARTHR, (R/W) Default: 0x03, Unsigned, Threshold used in phase total/fundamental reactive power data path
#define VATHR_8 0xEA04 //VATHR, (R/W) Default: 0x03, Unsigned, Threshold used in phase apparent power data path.
#define HX_8 0xEA08 //HX, (R/W) Default: 3, Unsigned, Selects an index of the harmonic monitored by the harmonic computations.
#define HY_8 0xEA09 //HY, (R/W) Default: 5, Unsigned, Selects an index of the harmonic monitored by the harmonic computations.
#define HZ_8 0xEA0A //HZ, (R/W) Default: 7, Unsigned, Selects an index of the harmonic monitored by the harmonic computations.
#define SPI_SEL_8 0xEBFF // REGISTRO SELECCIÓN DE SPI
#define LPOILVL_8 0xEC00 //LPOILVL, (R/W) Default: 0x07, Unsigned, Overcurrent threshold used during PSM2 mode.
#define CONFIG2_8 0xEC01 //CONFIG2, (R/W) Default: 0x00, Unsigned, Configuration register used during PSM1 mode.

//16-bit Registers
#define RUN_16 0xE228 //RUN, (R/W) Default: 0x0008, Unsigned, Run register starts and stops the DSP.
#define PHSTATUS_16 0xE600 //PHSTATUS, (R), Unsigned, Phase peak register.
#define ANGLE0_16 0xE601 //ANGLE0, (R), Unsigned, Time Delay 0.
#define ANGLE1_16 0xE602 //ANGLE1, (R), Unsigned, Time Delay 1.
#define ANGLE2_16 0xE603 //ANGLE2, (R), Unsigned, Time Delay 2.
#define PHNOLOAD_16 0xE608 //PHNOLOAD, (R), Unsigned, Phase no load register.
#define LINECYC_16 0xE60C //LINECYC, (R/W) Default: 0xFFFF, Unsigned, Line cycle accumulation mode count.
#define ZXTOUT_16 0xE60D //ZXTOUT, (R/W) Default: 0xFFFF, Unsigned, Zero-crossing timeout count. 
#define COMPMODE_16 0xE60E //COMPMODE, (R/W) Default: 0x0000, Unsigned, PGA gains at ADC inputs.
#define Gain_16 0xE60F //Gain, (R/W) Default: 0x01FF, Unsigned, Computation-mode register.
#define CFMODE_16 0xE610 //CFMODE, (R/W) Default: 0x0EA0, Unsigned, CFx configuration register.
#define CF1DEN_16 0xE611 //CF1DEN, (R/W) Default: 0x0000, Unsigned, CF1 denominator.
#define CF2DEN_16 0xE612 //CF2DEN, (R/W) Default: 0x0000, Unsigned, CF2 denominator.
#define CF3DEN_16 0xE613 //CF3DEN, (R/W) Default: 0x0000, Unsigned, CF3 denominator.
#define APHCAL_16 0xE614 //APHCAL, (R/W) Default: 0x0000, Signed, Phase calibration of Phase A.
#define BPHCAL_16 0xE615 //BPHCAL, (R/W) Default: 0x0000, Signed, Phase calibration of Phase B.
#define CPHCAL_16 0xE616 //CPHCAL, (R/W) Default: 0x0000, Signed, Phase calibration of Phase C.
#define PHSIGN_16 0xE617 //PHSIGN, (R), Unsigned, Power sign register.
#define CONFIG_16 0xE618 //CONFIG, (R/W) Default: 0x0002, Unsigned, ADE7880 configuration register.
#define HCONFIG_16 0xE900 //HCONFIG, (R/W) Default: 0x0008, Unsigned, Harmonic Calculations Configuration register. .
#define APF_16 0xE902 //APF, (R), Signed, Phase A power factor.
#define BPF_16 0xE903 //BPF, (R), Signed, Phase B power factor.
#define CPF_16 0xE904 //CPF, (R), Signed, Phase C power factor.
#define APERIOD_16 0xE905 //APERIOD, (R), Unsigned, Line period on Phase A voltage.
#define BPERIOD_16 0xE906 //BPERIOD, (R), Unsigned, Line period on Phase B voltage.
#define CPERIOD_16 0xE907 //CPERIOD, (R), Unsigned, Line period on Phase C voltage.
#define APNOLOAD_16 0xE908 //APNOLOAD, (R/W) Default: 0x0000, Unsigned, No load threshold in the total/fundamental active power data path.
#define VARNOLOAD_16 0xE909 //VARNOLOAD, (R/W) Default: 0x0000, Unsigned, No load threshold in the total/fundamental reactive power data path. 
#define VANOLOAD_16 0xE90A //VANOLOAD, (R/W) Default: 0x0000, Unsigned, No load threshold in the apparent power data path.
#define LAST_ADD_16 0xE9FE //LAST_ADD, (R), Unsigned, The address of the register successfully accessed during the last read/write operation.
#define LAST_RWDATA16_16 0xE9FF //LAST_RWDATA16, (R), Unsigned, Contains the data from the last successful 16-bit register communication.

//24-bit Registers
#define AIGAIN_24 0x4380 //AIGAIN, (R/W) Default: 0x000000, Signed, Phase A current gain adjust.
#define AVGAIN_24 0x4381 //AVGAIN, (R/W) Default: 0x000000, Signed, Phase A voltage gain adjust.
#define BIGAIN_24 0x4382 //BIGAIN, (R/W) Default: 0x000000, Signed, Phase B current gain adjust.
#define BVGAIN_24 0x4383 //BVGAIN, (R/W) Default: 0x000000, Signed, Phase B voltage gain adjust.
#define CIGAIN_24 0x4384 //CIGAIN, (R/W) Default: 0x000000, Signed, Phase C current gain adjust.
#define CVGAIN_24 0x4385 //CVGAIN, (R/W) Default: 0x000000, Signed, Phase C voltage gain adjust.
#define NIGAIN_24 0x4386 //NIGAIN, (R/W) Default: 0x000000, Signed, Neutral current gain adjust.
#define DICOEFF_24 0x4388 //DICOEFF, (R/W) Default: 0x0000000, Signed, Register used in the digital integrator algorithm.
#define APGAIN_24 0x4389 //APGAIN, (R/W) Default: 0x000000, Signed, Phase A power gain adjust.
#define AWATTOS_24 0x438A //AWATTOS, (R/W) Default: 0x000000, Signed, Phase A total active power offset adjust.
#define BPGAIN_24 0x438B //BPGAIN, (R/W) Default: 0x000000, Signed, Phase B power gain adjust.
#define BWATTOS_24 0x438C //BWATTOS, (R/W) Default: 0x000000, Signed, Phase B total active power offset adjust.
#define CPGAIN_24 0x438D //CPGAIN, (R/W) Default: 0x000000, Signed, Phase C power gain adjust.
#define CWATTOS_24 0x438E //CWATTOS, (R/W) Default: 0x000000, Signed, Phase C total active power offset adjust.
#define AIRMSOS_24 0x438F //AIRMSOS, (R/W) Default: 0x000000, Signed, Phase A current rms offset.
#define AVRMSOS_24 0x4390 //AVRMSOS, (R/W) Default: 0x000000, Signed, Phase A voltage rms offset.
#define BIRMSOS_24 0x4391 //BIRMSOS, (R/W) Default: 0x000000, Signed, Phase B current rms offset.
#define BVRMSOS_24 0x4392 //BVRMSOS, (R/W) Default: 0x000000, Signed, Phase B voltage rms offset.
#define CIRMSOS_24 0x4393 //CIRMSOS, (R/W) Default: 0x000000, Signed, Phase C current rms offset.
#define CVRMSOS_24 0x4394 //CVRMSOS, (R/W) Default: 0x000000, Signed, Phase C voltage rms offset.
#define NIRMSOS_24 0x4395 //NIRMSOS, (R/W) Default: 0x000000, Signed, Neutral current rms offset.
#define HPGAIN_24 0x4398 //HPGAIN, (R/W) Default: 0x000000, Signed, Harmonic powers gain adjust.
#define ISUMLVL_24 0x4399 //ISUMLVL, (R/W) Default: 0x000000, Signed, Threshold used in comparison between the sum.
#define VLEVEL_24 0x439F //VLEVEL, (R/W) Default: 0x0000000, Signed, Register used in the algorithm that computes the fundamental active and reactive powers. 28-bit register
#define AFWATTOS_24 0x43A2 //AFWATTOS, (R/W) Default: 0x000000, Signed, Phase A fundamental active power offset adjust.
#define BFWATTOS_24 0x43A3 //BFWATTOS, (R/W) Default: 0x000000, Signed, Phase B fundamental active power offset adjust.
#define CFWATTOS_24 0x43A4 //CFWATTOS, (R/W) Default: 0x000000, Signed, Phase C fundamental active power offset adjust.
#define AFVAROS_24 0x43A5 //AFVAROS, (R/W) Default: 0x000000, Signed, Phase A fundamental reactive power offset adjust.
#define BFVAROS_24 0x43A6 //BFVAROS, (R/W) Default: 0x000000, Signed, Phase B fundamental reactive power offset adjust.
#define CFVAROS_24 0x43A7 //CFVAROS, (R/W) Default: 0x000000, Signed, Phase C fundamental reactive power offset adjust.
#define AFIRMSOS_24 0x43A8 //AFIRMSOS, (R/W) Default: 0x000000, Signed, Phase A fundamental current rms offset.
#define BFIRMSOS_24 0x43A9 //BFIRMSOS, (R/W) Default: 0x000000, Signed, Phase B fundamental current rms offset.
#define CFIRMSOS_24 0x43AA //CFIRMSOS, (R/W) Default: 0x000000, Signed, Phase C fundamental current rms offset.
#define AFVRMSOS_24 0x43AB //AFVRMSOS, (R/W) Default: 0x000000, Signed, Phase A fundamental voltage rms offset.
#define BFVRMSOS_24 0x43AC //BFVRMSOS, (R/W) Default: 0x000000, Signed, Phase B fundamental voltage rms offset.
#define CFVRMSOS_24 0x43AD //CFVRMSOS, (R/W) Default: 0x000000, Signed, Phase C fundamental voltage rms offset.
#define HXWATTOS_24 0x43AE //HXWATTOS, (R/W) Default: 0x000000, Signed, Active power offset adjust on harmonic X.
#define HYWATTOS_24 0x43AF //HYWATTOS, (R/W) Default: 0x000000, Signed, Active power offset adjust on harmonic Y.
#define HZWATTOS_24 0x43B0 //HZWATTOS, (R/W) Default: 0x000000, Signed, Active power offset adjust on harmonic Z.
#define HXVAROS_24 0x43B1 //HXVAROS, (R/W) Default: 0x000000, Signed, Active power offset adjust on harmonic X.
#define HYVAROS_24 0x43B2 //HYVAROS, (R/W) Default: 0x000000, Signed, Active power offset adjust on harmonic Y.
#define HZVAROS_24 0x43B3 //HZVAROS, (R/W) Default: 0x000000, Signed, Active power offset adjust on harmonic Z.
#define HXIRMSOS_24 0x43B4 //HXIRMSOS, (R/W) Default: 0x000000, Signed, Current rms offset on harmonic X.
#define HYIRMSOS_24 0x43B5 //HYIRMSOS, (R/W) Default: 0x000000, Signed, Current rms offset on harmonic Y.
#define HZIRMSOS_24 0x43B6 //HZIRMSOS, (R/W) Default: 0x000000, Signed, Current rms offset on harmonic Z.
#define HXVRMSOS_24 0x43B7 //HXVRMSOS, (R/W) Default: 0x000000, Signed, Voltage rms offset on harmonic X.
#define HYVRMSOS_24 0x43B8 //HYVRMSOS, (R/W) Default: 0x000000, Signed, Voltage rms offset on harmonic Y.
#define HZVRMSOS_24 0x43B9 //HZVRMSOS, (R/W) Default: 0x000000, Signed, Voltage rms offset on harmonic Z.
#define AIRMS_24 0x43C0 //AIRMS, (R), Signed, Phase A current rms value.
#define AVRMS_24 0x43C1 //AVRMS, (R), Signed, Phase A voltage rms value.
#define BIRMS_24 0x43C2 //BIRMS, (R), Signed, Phase B current rms value.
#define BVRMS_24 0x43C3 //BVRMS, (R), Signed, Phase B voltage rms value.
#define CIRMS_24 0x43C4 //CIRMS, (R), Signed, Phase C current rms value.
#define CVRMS_24 0x43C5 //CVRMS, (R), Signed, Phase C voltage rms value.
#define NIRMS_24 0x43C6 //NIRMS, (R), Signed, Neutral current rms value.
#define ISUM_24 0x43C7 //ISUM, (R), Signed, Sum of IAWV, IBWV and ICWV registers. 28-bit register
#define HZVRMSOS_24 0x43B9 //HZVRMSOS, (R/W) Default: 0x000000, Signed, Voltage rms offset on harmonic Z.
#define OILVL_24 0xE507 //OILVL, (R/W) Default: 0xFFFFFF, Unsigned, Overcurrent threshold.
#define OVLVL_24 0xE508 //OVLVL, (R/W) Default: 0xFFFFFF, Unsigned, Overvoltage threshold.
#define SAGLVL_24 0xE509 //SAGLVL, (R/W) Default: 0x000000, Unsigned, Voltage SAG level threshold.
#define MASK0_32 0xE50A //MASK0, (R/W), Default: 0x000000, Unsigned, IRQ0 MASK.
#define MASK1_32 0xE50B //MASK1, (R/W), Default: 0x000000, Unsigned, IRQ1 MASK.
#define IAWV_24 0xE50C //IAWV, (R), Signed, Instantaneous value of Phase A current.
#define IBWV_24 0xE50D //IBWV, (R), Signed, Instantaneous value of Phase B current.
#define ICWV_24 0xE50E //ICWV, (R), Signed, Instantaneous value of Phase C current.
#define INWV_24 0xE50F //INWV, (R), Signed, Instantaneous value of neutral current.
#define VAWV_24 0xE510 //VAWV, (R), Signed, Instantaneous value of Phase A voltage.
#define VBWV_24 0xE511 //VBWV, (R), Signed, Instantaneous value of Phase B voltage.
#define VCWV_24 0xE512 //VCWV, (R), Signed, Instantaneous value of Phase C voltage.
#define AWATT_24 0xE513 //AWATT, (R), Signed, Instantaneous value of Phase A total active power.
#define BWATT_24 0xE514 //BWATT, (R), Signed, Instantaneous value of Phase B total active power.
#define CWATT_24 0xE515 //CWATT, (R), Signed, Instantaneous value of Phase C total active power.
#define AVA_24 0xE519 //AVA, (R), Signed, Instantaneous value of Phase A apparent power.
#define BVA_24 0xE51A //BVA, (R), Signed, Instantaneous value of Phase B apparent power.
#define CVA_24 0xE51B //CVA, (R), Signed, Instantaneous value of Phase C apparent power.
#define VNOM_24 0xE520 //VNOM, (R/W) Default: 0x000000, Unsigned, Nominal phase voltage rms used in the alternative computation of the apparent power.
#define FVRMS_24 0xE880 //FVRMS, (R), Signed, The rms value of the fundamental component of the phase voltage.
#define FIRMS_24 0xE881 //FIRMS, (R), Signed, The rms value of the fundamental component of the phase current.
#define FWATT_24 0xE882 //FWATT, (R), Signed, The active power of the fundamental component.
#define FVAR_24 0xE883 //FVAR, (R), Signed, The reactive power of the fundamental component.
#define FVA_24 0xE884 //FVA, (R), Signed, The apparent power of the fundamental component.
#define FPF_24 0xE885 //FPF, (R), Signed, The power factor of the fundamental component.
#define VTHD_24 0xE886 //VTHD, (R), Signed, Total harmonic distortion of the phase voltage.
#define ITHD_24 0xE887 //ITHD, (R), Signed, Total harmonic distortion of the phase current.
#define HXVRMS_24 0xE888 //HXVRMS, (R), Signed, The rms value of the phase voltage harmonic X.
#define HXIRMS_24 0xE889 //HXIRMS, (R), Signed, The rms value of the phase current harmonic X.
#define HXWATT_24 0xE88A //HXWATT, (R), Signed, The active power of the harmonic X.
#define HXVAR_24 0xE88B //HXVAR, (R), Signed, The reactive power of the harmonic X.
#define HXVA_24 0xE88C //HXVA, (R), Signed, The apparent power of the harmonic X.
#define HXPF_24 0xE88D //HXPF, (R), Signed, The power factor of the harmonic X.
#define HXVHD_24 0xE88E //HXVHD, (R), Signed, Harmonic distortion of the phase voltage.
#define HXIHD_24 0xE88F //HXIHD, (R), Signed, Harmonic distortion of the phase current harmonic X relative to the fundamental.
#define HYVRMS_24 0xE890 //HYVRMS, (R), Signed, The rms value of the phase voltage harmonic Y.
#define HYIRMS_24 0xE891 //HYIRMS, (R), Signed, The rms value of the phase current harmonic Y.
#define HYWATT_24 0xE892 //HYWATT, (R), Signed, The active power of the harmonic Y.
#define HYVAR_24 0xE893 //HYVAR, (R), Signed, The reactive power of the harmonic Y.
#define HYVA_24 0xE894 //HYVA, (R), Signed, The apparent power of the harmonic Y.
#define HYPF_24 0xE895 //HYPF, (R), Signed, The power factor of the harmonic Y.
#define HYVHD_24 0xE896 //HYVHD, (R), Signed, Harmonic distortion of the phase voltage harmonic Y relative to the fundamental.
#define HYIHD_24 0xE897 //HYIHD, (R), Signed, Harmonic distortion of the phase current harmonic Y relative to the fundamental.
#define HZVRMS_24 0xE898 //HZVRMS, (R), Signed, The rms value of the phase voltage harmonic Z.
#define HZIRMS_24 0xE899 //HZIRMS, (R), Signed, The rms value of the phase current harmonic Z.
#define HZWATT_24 0xE89A //HZWATT, (R), Signed, The active power of the harmonic Z.
#define HZVAR_24 0xE89B //HZVAR, (R), Signed, The reactive power of the harmonic Z.
#define HZVA_24 0xE89C //HZVA, (R), Signed, The apparent power of the harmonic Z.
#define HZPF_24 0xE89D //HZPF, (R), Signed, The power factor of the harmonic Z.
#define HZVHD_24 0xE89E //HZVHD, (R), Signed, Harmonic distortion of the phase voltage harmonic Z relative to the fundamental.
#define HZIHD_24 0xE89F //HZIHD, (R), Signed, Harmonic distortion of the phase current harmonic Z relative to the fundamental. .

//20-bit Registers
#define AIMAV_20 0xE504 //AIMAV, (R), Unsigned, Phase A current mean absolute value computed during PSM0 and PSM1 modes.
#define BIMAV_20 0xE505 //BIMAV, (R), Unsigned, Phase B current mean absolute value computed during PSM0 and PSM1 modes.
#define CIMAV_20 0xE506 //CIMAV, (R), Unsigned, Phase C current mean absolute value computed during PSM0 and PSM1 modes.

#define STATUS1_32 0xE503 //STATUS1, (R/W) Default: N/A, Unsigned, interrupts status register.

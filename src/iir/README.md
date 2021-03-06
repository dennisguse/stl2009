       =============================================================
       COPYRIGHT NOTE: This source code, and all of its derivations,
       is subject to the "ITU-T General Public License". Please have
       it  read  in    the  distribution  disk,   or  in  the  ITU-T
       Recommendation G.191 on "SOFTWARE TOOLS FOR SPEECH AND  AUDIO
       CODING STANDARDS".
       =============================================================


The ITU-T/UGST IIR Up/Downsampling and Filtering Module (IIR, for short) is
built of the following files:

# Source code
### Main files
```
 iirflt.h: ...... IIR module definitions and prototypes.
 iir-lib.c: ..... sub-unit of the IIR module with basic filtering functions
 iir-g712.c: .... sub-unit of the IIR module with the standard PCM filter
                  initialization functions
 iir-dir.c: ..... sub-unit of the IIR module with a DC-removal filter using
                  a direct-form IIR structure.
 iir-flat.c: .... sub-unit of the IIR module with a 3:1 and 1:3 cascade-form
                  flat low-pass filter.
 iir-irs.c: ..... sub-unit of the IIR module with 8kHz 1:1 IRS-weighting
                  initialization functions
 iirflt.c: ...... dummy program that calls all the sub-units. Equivalent to
                  the old PCMFLT.C file
 cascg712.c: .... sub-unit of the IIR module w/the cascade G.712 init.functions
```

### Interface
```
 ugst-utl.c: .... UGST utility routines: scaling, conversion of formats:
                  serial<=>parallel (ie, normal samples<=>bit-streams,
                  short<=>float). (*)
 ugst-utl.h: .... UGST utilities definitions and prototypes. (*)
 ugstdemo.h: .... Definitions for UGST demo programs. (*)
```

### Demos
```
 pcmdemo.c: ..... Demo program for the G.712 parallel-form filters.
 c712demo.c: .... Demo program for the cascade-form IIR 1:1 G.712 filtering
 cirsdemo.c: .... Demo program for IIR 8kHz 1:1 cascad-forme IIR IRS filter
```

```
 +-----------------------------------------------------------------------+
 | OBS:                                                                  |
 | (*):  In other directory                                              |
 +-----------------------------------------------------------------------+
```

# Makefiles

Makefiles have been provided for automatic build-up of the executable program
and to process the test files:
```
make-vms.com: ... DCL for VAX/VMS Vax-cc compiler or the VMS port of gcc
makefile.tcc: ... makefile for MSDOS Borland tcc
makefile.cl: .... makefile for MS Visual C Compiler
makefile.djc: ... makefile for MSDOS port of gcc
makefile.unx: ... makefile for Unix, using either cc (Sun), acc (Sun), or gcc
pcmdemo.prj: .... Borland tc/bc project file for compiling within the  
                  integrated environment
```

# Testing

The provided makefiles can run a portability test on the demo program. They
need the archive `test-iir.zip` (`[pk]zip` compatible archive) and `[pk]unzip` to
extract the proper source and reference processed files.

```
test-iir.zip: ... ZIP-compatible archive with the test files in the Unix
		  byte orientation (high-byte first). Also with a
		  readme file (test-iir.rme) and a statistics file
		  (test-iir.sta).  
		  [NOTE: for VMS and PC users, byte-swapping of the samples
		         is needed. Please see tool sb.c in the directory
		         ../utl of this distribution]
```

The statistics and CRCs for the test files are as follows:
```
-------+------+------+-------+--------+------+-----+------+--------------
Samples    Min   Max       DC       AC    CRC   CRC    CRC  File name
                                        CCITT   ARC XMODEM
-------+------+------+-------+--------+------+-----+------+--------------
   7680 -29069  32767 -124.46  7728.87   F4C2  632B   1926 test.src
   7680 -23254  27881  -23.00  6797.38   9851  2032   0084 cascg712.ref
   7680 -24528  25266    0.27  6785.07   7265  F639   0BF8 iir-irs.ref
   7680 -15513  18670   -1.96  5046.66   7905  30D0   0B93 testpcm1.ref
   3840 -15395  17645   -1.83  5045.89   8A8A  2968   19C8 testpcmd.ref
  15360 -28479  26073    0.95  7126.48   7981  4219   0926 testpcmu.ref
-------+------+------+-------+--------+------+-----+------+--------------
```

-- <simao@ctd.comsat.com> --

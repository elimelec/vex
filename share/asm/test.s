 ## Target: VEX 1 cluster (big endian)
.comment "Copyright (C) 1990-2004 Hewlett-Packard Company"
.comment ""
.comment "VEX C compiler version 3.35 20041014 (release)"
.comment "-dir /opt/vex -o test.s -O -S"
.sversion 3.35
.rta 2
.section .bss
.align 32
.section .data
.align 32
 ## Begin yydestruct
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:u32)
yydestruct:
.trace 1
	      ## auto_size == 0
;;								## 0
.return ret()
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 1045,  t3,  ?2.1?2auto_size(I32),  t2
;;								## 1
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.1?2auto_size, 0x0
 ## End yydestruct
.equ _?1TEMPLATEPACKET.21, 0x0
.equ _?1TEMPLATEPACKET.24, 0x0
.equ _?1TEMPLATEPACKET.10, 0x0
 ## Begin yyparse
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-2112, arg()
yyparse::
.trace 37
	c0    add $r0.1 = $r0.1, (-0x840)
	c0    mov $r0.11 = 200   ## bblock 0, line 1130,  t497,  200(SI32)
	c0    mov $r0.2 = -2   ## -2(SI32)
;;								## 0
	c0    add $r0.13 = $r0.1, 0x10   ## bblock 0, line 1122,  t498,  t479,  offset(yyvsa?1.5)=0x10(P32)
	c0    stw 0x7e0[$r0.1] = $l0.0  ## spill ## t478
;;								## 1
	c0    add $r0.3 = $r0.1, 0x650   ## bblock 0, line 1117,  t2,  t479,  offset(yyssa?1.5)=0x650(P32)
	c0    stw 0x824[$r0.1] = $r0.57  ## spill ## t482
;;								## 2
	c0    mov $r0.57 = $r0.0   ## bblock 0, line 1106,  t0,  0(SI32)
	c0    stw 0x820[$r0.1] = $r0.58  ## spill ## t483
;;								## 3
	c0    mov $r0.58 = $r0.3   ## bblock 0, line 1117,  t499,  t2
	c0    stw 0x81c[$r0.1] = $r0.59  ## spill ## t484
;;								## 4
	c0    stw 0x818[$r0.1] = $r0.60  ## spill ## t485
;;								## 5
	c0    mov $r0.60 = $r0.3   ## bblock 0, line 1117,  t3,  t2
	c0    stw 0x814[$r0.1] = $r0.61  ## spill ## t486
;;								## 6
	c0    mov $r0.61 = $r0.0   ## bblock 0, line 1106,  t501,  0(SI32)
	c0    stw 0x810[$r0.1] = $r0.62  ## spill ## t487
;;								## 7
	c0    mov $r0.62 = $r0.0   ## bblock 0, line 1106,  t500,  0(SI32)
	c0    stw 0x80c[$r0.1] = $r0.63  ## spill ## t488
;;								## 8
	c0    mov $r0.63 = $r0.13   ## bblock 0, line 1122,  t12,  t498
	c0    stw 0x7f0[$r0.1] = $r0.13  ## spill ## t498
;;								## 9
	c0    stw 0x800[$r0.1] = $r0.3  ## spill ## t2
;;								## 10
	c0    stw ((yynerrs + 0) + 0)[$r0.0] = $r0.0   ## bblock 0, line 1145, 0(I32), 0(SI32)
;;								## 11
	c0    stw ((yychar + 0) + 0)[$r0.0] = $r0.2   ## bblock 0, line 1146, 0(I32), -2(SI32)
;;								## 12
.trace 7
L0?3:
	c0    sth 0[$r0.60] = $r0.57   ## bblock 1, line 1168, t3, t0
	c0    add $r0.12 = $r0.11, -1   ## bblock 1, line 1170,  t21,  t497,  -1(SI32)
	c0    sub $r0.10 = $r0.60, $r0.58   ## [spec] bblock 217, line 1173,  t26,  t3,  t499
	c0    shl $r0.13 = $r0.11, 1   ## [spec] bblock 218, line 1204,  t542,  t497,  1(I32)
;;								## 0
	c0    sh1add $r0.12 = $r0.12, $r0.58   ## bblock 1, line 1170,  t24,  t21,  t499
	c0    cmplt $b0.0 = $r0.10, $r0.0   ## [spec] bblock 217, line 1173,  t809,  t26,  0(I32)
	c0    add $r0.14 = $r0.10, 1   ## [spec] bblock 217, line 1173,  t810,  t26,  1(I32)
;;								## 1
	c0    cmpleu $b0.0 = $r0.12, $r0.60   ## bblock 1, line 1170,  t767(I1),  t24,  t3
	c0    slct $r0.14 = $b0.0, $r0.14, $r0.10   ## [spec] bblock 217, line 1173,  t811,  t809,  t810,  t26
	c0    cmpgeu $b0.1 = $r0.11, 10000   ## [spec] bblock 217, line 1202,  t812(I1),  t497,  10000(SI32)
;;								## 2
	c0    shr $r0.59 = $r0.14, 1   ## [spec] bblock 217, line 1173,  t27,  t811,  1(I32)
	c0    mov $r0.10 = $r0.58   ## [spec] bblock 218, line 1209,  t492,  t499
;;								## 3
	c0    add $r0.5 = $r0.59, 1   ## [spec] bblock 217, line 1173,  t493,  t27,  1(SI32)
	c0    stw 0x7e4[$r0.1] = $r0.10  ## spill ## [spec] t492
	c0    brf $b0.0, L1?3   ## bblock 1, line 1170,  t767(I1)
;;								## 4
	c0    minu $r0.11 = $r0.13, 10000   ## [spec] bblock 218, line 1206,  t497,  t542,  10000(SI32)
	c0    stw 0x7e8[$r0.1] = $r0.5  ## spill ## [spec] t493
;;								## 5
	c0    mpylu $r0.10 = $r0.11, 10   ## [spec] bblock 218, line 1211,  t36,  t497,  10(I32)
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## [spec] t497
	c0    br $b0.1, L2?3   ## bblock 217, line 1202,  t812(I1)
;;								## 6
;;								## 7
.call malloc, caller, arg($r0.3:u32), ret($r0.3:u32)
	c0    add $r0.3 = $r0.10, 7   ## bblock 218, line 1211,  t37,  t36,  7(I32)
	c0    call $l0.0 = malloc   ## bblock 218, line 1211,  raddr(malloc)(P32),  t37
;;								## 8
	c0    cmpeq $b0.0 = $r0.3, $r0.0   ## bblock 220, line 1212,  t813(I1),  t34,  0x0(P32)
	c0    mov $r0.8 = 2   ## [spec] bblock 221, line 0,  t676,  2(I32)
	c0    mov $r0.9 = 3   ## [spec] bblock 221, line 0,  t687,  3(I32)
	c0    mov $r0.7 = 1   ## [spec] bblock 221, line 0,  t680,  1(I32)
;;								## 9
	c0    mov $r0.2 = $r0.58   ## [spec] bblock 221, line 1209,  t686,  t499
	c0    mov $r0.4 = $r0.0   ## [spec] bblock 221, line 1214,  t39,  0(SI32)
	c0    mov $r0.6 = $r0.3   ## [spec] bblock 221, line 1211,  t685,  t34
	c0    mov $r0.12 = $r0.3   ## t34
;;								## 10
	c0    ldw $r0.5 = 0x7e8[$r0.1]  ## restore ## [spec] t493
	c0    br $b0.0, L3?3   ## bblock 220, line 1212,  t813(I1)
;;								## 11
	c0    ldw $r0.10 = 0x7e4[$r0.1]  ## restore ## [spec] t492
;;								## 12
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## [spec] t497
	      xnop 1
;;								## 14
;;								## 15
.trace 1
L4?3:
	c0    cmpltu $b0.0 = $r0.4, $r0.5   ## bblock 222, line 1214,  t814(I1),  t39,  t493
	c0    ldh.d $r0.3 = 0[$r0.2]   ## [spec] bblock 229, line 1214, t46(SI16), t686
	c0    cmpltu $b0.1 = $r0.7, $r0.5   ## [spec] bblock 229, line 1214-1,  t819(I1),  t680,  t493
	c0    cmpltu $b0.2 = $r0.8, $r0.5   ## [spec] bblock 239, line 1214-2,  t820(I1),  t676,  t493
;;								## 0
	c0    cmpltu $b0.3 = $r0.9, $r0.5   ## [spec] bblock 199, line 1214-3,  t805(I1),  t687,  t493
	c0    add $r0.7 = $r0.7, 4   ## [spec] bblock 213, line 0,  t680,  t680,  4(I32)
	c0    add $r0.8 = $r0.8, 4   ## [spec] bblock 213, line 0,  t676,  t676,  4(I32)
	c0    add $r0.4 = $r0.4, 4   ## [spec] bblock 213, line 1214-3,  t39,  t39,  4(SI32)
;;								## 1
	c0    add $r0.9 = $r0.9, 4   ## [spec] bblock 213, line 0,  t687,  t687,  4(I32)
	c0    brf $b0.0, L5?3   ## bblock 222, line 1214,  t814(I1)
;;								## 2
	c0    sth 0[$r0.6] = $r0.3   ## bblock 229, line 1214, t685, t46(SI16)
	c0    brf $b0.1, L5?3   ## bblock 229, line 1214-1,  t819(I1)
;;								## 3
	c0    ldh $r0.3 = 2[$r0.2]   ## bblock 239, line 1214-1, t582(SI16), t686
	      xnop 2
;;								## 6
	c0    sth 2[$r0.6] = $r0.3   ## bblock 239, line 1214-1, t685, t582(SI16)
	c0    brf $b0.2, L5?3   ## bblock 239, line 1214-2,  t820(I1)
;;								## 7
	c0    ldh $r0.3 = 4[$r0.2]   ## bblock 199, line 1214-2, t548(SI16), t686
	      xnop 2
;;								## 10
	c0    sth 4[$r0.6] = $r0.3   ## bblock 199, line 1214-2, t685, t548(SI16)
	c0    brf $b0.3, L5?3   ## bblock 199, line 1214-3,  t805(I1)
;;								## 11
	c0    ldh $r0.3 = 6[$r0.2]   ## bblock 213, line 1214-3, t571(SI16), t686
	c0    add $r0.2 = $r0.2, 8   ## bblock 213, line 0,  t686,  t686,  8(I32)
	      xnop 2
;;								## 14
	c0    sth 6[$r0.6] = $r0.3   ## bblock 213, line 1214-3, t685, t571(SI16)
	c0    add $r0.6 = $r0.6, 8   ## bblock 213, line 0,  t685,  t685,  8(I32)
	c0    goto L4?3 ## goto
;;								## 15
.trace 11
L5?3:
	c0    mov $r0.7 = 1   ## bblock 223, line 0,  t596,  1(I32)
	c0    sh1add $r0.3 = $r0.11, 7   ## bblock 223, line 1214,  t57,  t497,  7(I32)
	c0    mov $r0.9 = 3   ## bblock 223, line 0,  t592,  3(I32)
	c0    mov $r0.8 = 2   ## bblock 223, line 0,  t588,  2(I32)
;;								## 0
	c0    mov $r0.14 = $r0.12   ## bblock 223, line 1214,  t499,  t34
	c0    shru $r0.3 = $r0.3, 3   ## bblock 223, line 1214,  t58(I29),  t57,  3(I32)
	c0    ldw $r0.13 = 0x7f0[$r0.1]  ## restore ## t498
;;								## 1
	c0    sh3add $r0.3 = $r0.3, $r0.12   ## bblock 223, line 1214,  t491,  t58(I29),  t34
	c0    mov $r0.4 = $r0.0   ## bblock 223, line 1215,  t61,  0(SI32)
;;								## 2
	c0    mov $r0.6 = $r0.3   ## bblock 223, line 1214,  t601,  t491
	c0    mov $r0.15 = $r0.3   ## t491
;;								## 3
	c0    mov $r0.2 = $r0.13   ## bblock 223, line 0,  t602,  t498
;;								## 4
	c0    mov $r0.13 = $r0.12   ## t34
;;								## 5
	c0    mov $r0.12 = $r0.11   ## t497
;;								## 6
	c0    mov $r0.11 = $r0.10   ## t492
;;								## 7
.trace 2
L6?3:
	c0    cmpltu $b0.0 = $r0.4, $r0.5   ## bblock 224, line 1215,  t815(I1),  t61,  t493
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 228, line 1215, t68, t602
	c0    cmpltu $b0.1 = $r0.7, $r0.5   ## [spec] bblock 228, line 1215-1,  t818(I1),  t596,  t493
	c0    cmpltu $b0.2 = $r0.8, $r0.5   ## [spec] bblock 243, line 1215-2,  t822(I1),  t588,  t493
;;								## 0
	c0    ldw.d $r0.10 = 4[$r0.2]   ## [spec] bblock 228, line 1215, t69, t602
	c0    cmpltu $b0.3 = $r0.9, $r0.5   ## [spec] bblock 240, line 1215-3,  t821(I1),  t592,  t493
	c0    add $r0.8 = $r0.8, 4   ## [spec] bblock 235, line 0,  t588,  t588,  4(I32)
	c0    add $r0.4 = $r0.4, 4   ## [spec] bblock 235, line 1215-3,  t61,  t61,  4(SI32)
;;								## 1
	c0    add $r0.7 = $r0.7, 4   ## [spec] bblock 235, line 0,  t596,  t596,  4(I32)
	c0    add $r0.9 = $r0.9, 4   ## [spec] bblock 235, line 0,  t592,  t592,  4(I32)
	c0    brf $b0.0, L7?3   ## bblock 224, line 1215,  t815(I1)
;;								## 2
	c0    stw 0[$r0.6] = $r0.3   ## bblock 228, line 1215, t601, t68
;;								## 3
	c0    stw 4[$r0.6] = $r0.10   ## bblock 228, line 1215, t601, t69
	c0    brf $b0.1, L8?3   ## bblock 228, line 1215-1,  t818(I1)
;;								## 4
	c0    ldw $r0.3 = 8[$r0.2]   ## bblock 243, line 1215-1, t555, t602
;;								## 5
	c0    ldw $r0.10 = 12[$r0.2]   ## bblock 243, line 1215-1, t554, t602
	      xnop 1
;;								## 7
	c0    stw 8[$r0.6] = $r0.3   ## bblock 243, line 1215-1, t601, t555
;;								## 8
	c0    stw 12[$r0.6] = $r0.10   ## bblock 243, line 1215-1, t601, t554
	c0    brf $b0.2, L9?3   ## bblock 243, line 1215-2,  t822(I1)
;;								## 9
	c0    ldw $r0.3 = 16[$r0.2]   ## bblock 240, line 1215-2, t562, t602
;;								## 10
	c0    ldw $r0.10 = 20[$r0.2]   ## bblock 240, line 1215-2, t561, t602
	      xnop 1
;;								## 12
	c0    stw 16[$r0.6] = $r0.3   ## bblock 240, line 1215-2, t601, t562
;;								## 13
	c0    stw 20[$r0.6] = $r0.10   ## bblock 240, line 1215-2, t601, t561
	c0    brf $b0.3, L10?3   ## bblock 240, line 1215-3,  t821(I1)
;;								## 14
	c0    ldw $r0.3 = 24[$r0.2]   ## bblock 235, line 1215-3, t575, t602
;;								## 15
	c0    ldw $r0.10 = 28[$r0.2]   ## bblock 235, line 1215-3, t574, t602
	c0    add $r0.2 = $r0.2, 32   ## bblock 235, line 0,  t602,  t602,  32(I32)
	      xnop 1
;;								## 17
	c0    stw 24[$r0.6] = $r0.3   ## bblock 235, line 1215-3, t601, t575
;;								## 18
	c0    stw 28[$r0.6] = $r0.10   ## bblock 235, line 1215-3, t601, t574
	c0    add $r0.6 = $r0.6, 32   ## bblock 235, line 0,  t601,  t601,  32(I32)
	c0    goto L6?3 ## goto
;;								## 19
.trace 30
L10?3:
	c0    mov $r0.58 = $r0.15   ## bblock 225, line 1215,  t498,  t491
	c0    stw 0x7f4[$r0.1] = $r0.14  ## spill ## t499
	c0    mov $r0.3 = $r0.11   ## t492
	      ## goto
;;
	c0    goto L11?3 ## goto
;;								## 0
.trace 8
L1?3:
	c0    sh1add $r0.2 = $r0.57, (_?1PACKET.9 + 0)   ## bblock 2, line 1250,  t768,  t0,  addr(yypact?1.0)(P32)
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 0
	c0    ldh $r0.2 = 0[$r0.2]   ## bblock 2, line 1250, t1, t768
	c0    cmpeq $b0.0 = $r0.61, $r0.0   ## [spec] bblock 191, line 1846,  t795(I1),  t501,  0(SI32)
	c0    mov $r0.3 = (_?1STRINGPACKET.40 + 0)   ## addr(_?1STRINGVAR.40)(P32)
;;								## 1
	c0    ldbu.d $r0.4 = (_?1PACKET.7 + 0)[$r0.57]   ## [spec] bblock 212, line 1314, t512, t0
;;								## 2
	c0    ldw.d $r0.5 = ((yynerrs + 0) + 0)[$r0.0]   ## [spec] bblock 211, line 1848, t433, 0(I32)
;;								## 3
	c0    cmpeq $b0.1 = $r0.2, -192   ## bblock 2, line 1251,  t769(I1),  t1,  -192(SI32)
;;								## 4
	c0    cmpeq $b0.2 = $r0.4, $r0.0   ## [spec] bblock 212, line 1315,  t808(I1),  t512,  0(SI32)
;;								## 5
	c0    add $r0.5 = $r0.5, 1   ## [spec] bblock 211, line 1848,  t434,  t433,  1(SI32)
	c0    brf $b0.1, L12?3   ## bblock 2, line 1251,  t769(I1)
;;								## 6
L13?3:
	c0    brf $b0.2, L14?3   ## bblock 212, line 1315,  t808(I1)
;;								## 7
L15?3:
	c0    brf $b0.0, L16?3   ## bblock 191, line 1846,  t795(I1)
;;								## 8
.call yyerror, caller, arg($r0.3:u32), ret()
	c0    stw ((yynerrs + 0) + 0)[$r0.0] = $r0.5   ## bblock 211, line 1848, 0(I32), t434
	c0    call $l0.0 = yyerror   ## bblock 211, line 1896,  raddr(yyerror)(P32),  addr(_?1STRINGVAR.40)(P32)
;;								## 9
L16?3:
	c0    cmpeq $b0.0 = $r0.61, 3   ## bblock 192, line 1901,  t796(I1),  t501,  3(SI32)
	c0    ldw.d $r0.2 = ((yychar + 0) + 0)[$r0.0]   ## [spec] bblock 204, line 1907, t438, 0(I32)
	c0    mov $r0.3 = $r0.62   ## t500
;;								## 10
	c0    mov $r0.4 = (yylval + 0)   ## addr(yylval?1.0)(P32)
;;								## 11
	c0    brf $b0.0, L17?3   ## bblock 192, line 1901,  t796(I1)
;;								## 12
	c0    cmpeq $b0.0 = $r0.2, $r0.0   ## bblock 204, line 1907,  t806(I1),  t438,  0(SI32)
	      xnop 1
;;								## 14
	c0    br $b0.0, L18?3   ## bblock 204, line 1907,  t806(I1)
;;								## 15
.call yydestruct, caller, arg($r0.3:s32,$r0.4:u32), ret()
	c0    call $l0.0 = yydestruct   ## bblock 205, line 1922,  raddr(yydestruct)(P32),  t500,  addr(yylval?1.0)(P32)
;;								## 16
	c0    mov $r0.2 = -2   ## -2(SI32)
;;								## 17
	c0    stw ((yychar + 0) + 0)[$r0.0] = $r0.2   ## bblock 206, line 1923, 0(I32), -2(SI32)
;;								## 18
.trace 14
L17?3:
	c0    sub $r0.2 = $r0.0, $r0.58   ## bblock 193, line 0,  t584,  0(I32),  t499
	c0    mov $r0.61 = $r0.58   ## t499
	c0    mov $r0.59 = $r0.63   ## t12
;;								## 0
	c0    mov $r0.63 = 3   ## bblock 193, line 1936,  t501,  3(SI32)
	c0    add $r0.58 = $r0.2, $r0.60   ## bblock 193, line 0,  t583,  t584,  t3
;;								## 1
.trace 5
L19?3:
	c0    sh1add $r0.2 = $r0.57, (_?1PACKET.9 + 0)   ## bblock 194, line 1940,  t797,  t0,  addr(yypact?1.0)(P32)
	c0    cmpeq $b0.0 = $r0.58, $r0.0   ## [spec] bblock 195, line 1953,  t804(I1),  t583,  0(SI32)
	c0    mov $r0.4 = $r0.59   ## t12
;;								## 0
	c0    ldh $r0.2 = 0[$r0.2]   ## bblock 194, line 1940, t517, t797
;;								## 1
	c0    ldbu.d $r0.3 = (_?1PACKET.13 + 0)[$r0.57]   ## [spec] bblock 196, line 1957, t464(I8), t0
	      xnop 1
;;								## 3
	c0    add $r0.6 = $r0.2, 1   ## bblock 194, line 1943,  t518,  t517,  1(SI32)
	c0    cmpne $r0.7 = $r0.2, -192   ## bblock 194, line 1941,  t524(I1),  t517,  -192(SI32)
	c0    sh1add $r0.5 = $r0.2, ((_?1PACKET.11 + 0) + 2)   ## bblock 194, line 1946,  t798,  t517,  (addr(yytable?1.0)(P32) + 0x2(I32))(P32)
;;								## 4
	c0    cmpge $r0.8 = $r0.6, $r0.0   ## bblock 194, line 1944,  t456,  t518,  0(SI32)
	c0    cmple $r0.6 = $r0.6, 288   ## bblock 194, line 1944,  t457,  t518,  288(SI32)
	c0    ldh.d $r0.5 = 0[$r0.5]   ## [spec] bblock 194, line 1946, t578, t798
;;								## 5
	c0    ldbu.d $r0.2 = ((_?1PACKET.12 + 0) + 1)[$r0.2]   ## [spec] bblock 194, line 1944, t459(I8), t517
	      xnop 1
;;								## 7
	c0    cmpgt $r0.9 = $r0.5, $r0.0   ## bblock 194, line 1947,  t800,  t578,  0(SI32)
;;								## 8
	c0    cmpeq $r0.2 = $r0.2, 1   ## bblock 194, line 1944,  t526(I1),  t459(I8),  1(SI32)
	c0    andl $r0.8 = $r0.8, $r0.9   ## bblock 194, line 1941,  t799,  t456,  t800
;;								## 9
	c0    andl $r0.7 = $r0.7, $r0.2   ## bblock 194, line 1941,  t801,  t524(I1),  t526(I1)
	c0    andl $r0.8 = $r0.8, $r0.6   ## bblock 194, line 1941,  t802,  t799,  t457
;;								## 10
	c0    andl $b0.1 = $r0.8, $r0.7   ## bblock 194, line 1941,  t803(I1),  t802,  t801
	      xnop 1
;;								## 12
	c0    br $b0.1, L20?3   ## bblock 194, line 1941,  t803(I1)
;;								## 13
	c0    br $b0.0, L21?3   ## bblock 195, line 1953,  t804(I1)
;;								## 14
.call yydestruct, caller, arg($r0.3:s32,$r0.4:u32), ret()
	c0    call $l0.0 = yydestruct   ## bblock 196, line 1957,  raddr(yydestruct)(P32),  t464(I8),  t12
;;								## 15
	c0    ldh $r0.57 = (~0x1)[$r0.60]   ## bblock 197, line 1959, t0, t3
	c0    add $r0.59 = $r0.59, -8   ## bblock 197, line 1958,  t12,  t12,  -8(SI32)
	c0    add $r0.58 = $r0.58, (~0x1)   ## bblock 197, line 0,  t583,  t583,  (~0x1)(I32)
	c0    add $r0.60 = $r0.60, -2   ## bblock 197, line 1959,  t3,  t3,  -2(SI32)
	      xnop 1
;;								## 17
	c0    goto L19?3 ## goto
;;								## 18
.trace 23
L21?3:
	c0    mov $r0.2 = $r0.61   ## t499
	c0    ldw $r0.4 = 0x800[$r0.1]  ## restore ## t2
;;								## 0
	c0    ldw $r0.63 = 0x80c[$r0.1]  ## restore ## t488
;;								## 1
	c0    ldw $r0.62 = 0x810[$r0.1]  ## restore ## t487
;;								## 2
	c0    ldw $r0.61 = 0x814[$r0.1]  ## restore ## t486
;;								## 3
	c0    ldw $r0.60 = 0x818[$r0.1]  ## restore ## t485
;;								## 4
	c0    ldw $r0.59 = 0x81c[$r0.1]  ## restore ## t484
;;								## 5
	c0    ldw $r0.58 = 0x820[$r0.1]  ## restore ## t483
;;								## 6
	c0    ldw $r0.57 = 0x824[$r0.1]  ## restore ## t482
	      xnop 1
;;								## 8
;;								## 9
.trace 19
L22?3:
	c0    mov $r0.3 = 1   ## bblock 198, line 1987,  t502,  1(SI32)
	c0    cmpne $b0.0 = $r0.2, $r0.4   ## bblock 19, line 2002,  t779(I1),  t499,  t2
;;								## 0
L23?3:
	c0    stw 0x808[$r0.1] = $r0.3  ## spill ## t502
;;								## 1
	c0    mov $r0.3 = $r0.2   ## t499
	c0    brf $b0.0, L24?3   ## bblock 19, line 2002,  t779(I1)
;;								## 2
.call free, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = free   ## bblock 21, line 2003,  raddr(free)(P32),  t499
;;								## 3
L24?3:
	c0    ldw $l0.0 = 0x7e0[$r0.1]  ## restore ## t478
;;								## 4
	c0    ldw $r0.3 = 0x808[$r0.1]  ## restore ## t502
	      xnop 2
;;								## 7
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x840), $l0.0   ## bblock 20, line 2005,  t479,  ?2.2?2auto_size(I32),  t478
;;								## 8
.trace 21
L20?3:
	c0    cmpeq $b0.0 = $r0.5, 19   ## bblock 246, line 1964,  t823(I1),  t578,  19(SI32)
	c0    ldw.d $r0.3 = ((yylval + 0) + 0)[$r0.0]   ## [spec] bblock 203, line 1969, t469, 0(I32)
	c0    mov $r0.57 = $r0.5   ## [spec] bblock 203, line 1946,  t0,  t578
;;								## 0
	c0    ldw.d $r0.4 = ((yylval + 4) + 0)[$r0.0]   ## [spec] bblock 203, line 1969, t470, 0(I32)
	c0    add $r0.60 = $r0.60, 2   ## [spec] bblock 15, line 1165,  t3,  t3,  2(SI32)
	c0    mov $r0.58 = $r0.61   ## t499
;;								## 1
	c0    mov $r0.61 = $r0.63   ## t501
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	c0    br $b0.0, L25?3   ## bblock 246, line 1964,  t823(I1)
;;								## 2
	c0    stw 8[$r0.59] = $r0.3   ## bblock 203, line 1969, t12, t469
;;								## 3
	c0    stw 12[$r0.59] = $r0.4   ## bblock 203, line 1969, t12, t470
	c0    add $r0.63 = $r0.59, 8   ## bblock 203, line 1969,  t12,  t12,  8(SI32)
	c0    goto L0?3 ## goto
;;								## 4
.trace 120
L25?3:
	c0    mov $r0.3 = $r0.0   ## bblock 18, line 1980,  t502,  0(SI32)
	c0    mov $r0.2 = $r0.58   ## t499
	c0    ldw $r0.57 = 0x824[$r0.1]  ## restore ## t482
;;								## 0
	c0    ldw $r0.4 = 0x800[$r0.1]  ## restore ## t2
;;								## 1
L26?3:
	c0    ldw $r0.58 = 0x820[$r0.1]  ## restore ## t483
;;								## 2
	c0    ldw $r0.59 = 0x81c[$r0.1]  ## restore ## t484
;;								## 3
	c0    ldw $r0.60 = 0x818[$r0.1]  ## restore ## t485
;;								## 4
	c0    ldw $r0.61 = 0x814[$r0.1]  ## restore ## t486
;;								## 5
	c0    ldw $r0.62 = 0x810[$r0.1]  ## restore ## t487
;;								## 6
	c0    ldw $r0.63 = 0x80c[$r0.1]  ## restore ## t488
	      xnop 1
;;								## 8
	c0    cmpne $b0.0 = $r0.2, $r0.4   ## bblock 19, line 2002,  t779(I1),  t499,  t2
	c0    goto L23?3 ## goto
;;								## 9
.trace 122
L18?3:
	c0    add $r0.57 = $r0.60, -2   ## bblock 207, line 1910,  t516,  t3,  -2(SI32)
	c0    add $r0.59 = $r0.63, -8   ## bblock 207, line 1910,  t515,  t12,  -8(SI32)
	c0    ldw $r0.60 = 0x818[$r0.1]  ## restore ## t485
;;								## 0
	c0    ldw $r0.61 = 0x814[$r0.1]  ## restore ## t486
;;								## 1
	c0    ldw $r0.62 = 0x810[$r0.1]  ## restore ## t487
;;								## 2
	c0    ldw $r0.63 = 0x80c[$r0.1]  ## restore ## t488
	      xnop 1
;;								## 4
;;								## 5
.trace 33
L27?3:
	c0    cmpltu $b0.0 = $r0.58, $r0.57   ## bblock 208, line 1912,  t807(I1),  t499,  t516
	c0    ldh.d $r0.5 = 0[$r0.57]   ## [spec] bblock 209, line 1915, t445(SI16), t516
	c0    mov $r0.4 = $r0.59   ## t515
	      xnop 1
;;								## 1
	c0    brf $b0.0, L28?3   ## bblock 208, line 1912,  t807(I1)
;;								## 2
	c0    ldbu $r0.3 = (_?1PACKET.13 + 0)[$r0.5]   ## bblock 209, line 1915, t446(I8), t445(SI16)
	      xnop 1
;;								## 4
.call yydestruct, caller, arg($r0.3:s32,$r0.4:u32), ret()
	c0    call $l0.0 = yydestruct   ## bblock 209, line 1915,  raddr(yydestruct)(P32),  t446(I8),  t515
;;								## 5
	c0    add $r0.59 = $r0.59, -8   ## bblock 210, line 1916,  t515,  t515,  -8(SI32)
	c0    add $r0.57 = $r0.57, -2   ## bblock 210, line 1916,  t516,  t516,  -2(SI32)
	c0    goto L27?3 ## goto
;;								## 6
.trace 121
L28?3:
	c0    mov $r0.2 = $r0.58   ## t499
	c0    ldw $r0.59 = 0x81c[$r0.1]  ## restore ## t484
;;								## 0
	c0    ldw $r0.58 = 0x820[$r0.1]  ## restore ## t483
;;								## 1
	c0    ldw $r0.57 = 0x824[$r0.1]  ## restore ## t482
;;								## 2
	c0    ldw $r0.4 = 0x800[$r0.1]  ## restore ## t2
	      xnop 1
;;								## 4
	c0    goto L22?3 ## goto
;;								## 5
.trace 13
L14?3:
	c0    ldbu $r0.2 = (_?1PACKET.6 + 0)[$r0.4]   ## bblock 24, line 1325, t494, t512
	c0    cmplt $r0.6 = $r0.4, 7   ## bblock 24, line 499,  t400,  t512,  7(SI32)
	c0    cmpgt $r0.7 = $r0.4, 143   ## bblock 24, line 499,  t401,  t512,  143(SI32)
;;								## 0
	c0    orl $b0.0 = $r0.6, $r0.7   ## bblock 24, line 499,  t782(I1),  t400,  t401
	c0    mov $r0.59 = $r0.63   ## t12
	c0    mov $r0.5 = $r0.4   ## t512
;;								## 1
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
;;								## 2
	c0    sub $r0.6 = 1, $r0.2   ## bblock 24, line 1335,  t135,  1(SI32),  t494
;;								## 3
	c0    sh3add $r0.6 = $r0.6, $r0.63   ## bblock 24, line 1335,  t137,  t135,  t12
;;								## 4
	c0    ldw $r0.3 = 0[$r0.6]   ## bblock 24, line 1335, t495, t137
;;								## 5
	c0    ldw $r0.4 = 4[$r0.6]   ## bblock 24, line 1335, t496, t137
	      xnop 1
;;								## 7
	c0    brf $b0.0, L29?3   ## bblock 24, line 499,  t782(I1)
;;								## 8
.trace 9
L30?3:
_?1.yyparse.TAG.0.7:
_?1.yyparse.TAG.0.53:
_?1.yyparse.TAG.0.39:
_?1.yyparse.TAG.0.47:
_?1.yyparse.TAG.0.49:
_?1.yyparse.TAG.0.31:
_?1.yyparse.TAG.0.48:
_?1.yyparse.TAG.0.4:
_?1.yyparse.TAG.0.8:
_?1.yyparse.TAG.0.32:
_?1.yyparse.TAG.0.52:
_?1.yyparse.TAG.0.33:
_?1.yyparse.TAG.0.6:
_?1.yyparse.TAG.0.40:
_?1.yyparse.TAG.0.5:
_?1.yyparse.TAG.0.50:
_?1.yyparse.TAG.0.51:
_?1.yyparse.TAG.0.DEFAULT:
	c0    sub $r0.2 = $r0.0, $r0.2   ## bblock 28, line 1817,  t409,  0(I32),  t494
;;								## 0
	c0    sh3add $r0.59 = $r0.2, $r0.59   ## bblock 28, line 1817,  t407,  t409,  t12
	c0    sh1add $r0.60 = $r0.2, $r0.60   ## bblock 28, line 1818,  t3,  t409,  t3
;;								## 1
	c0    add $r0.63 = $r0.59, 8   ## bblock 28, line 1823,  t12,  t407,  8(SI32)
	c0    stw 8[$r0.59] = $r0.3   ## bblock 28, line 1823, t407, t495
;;								## 2
	c0    stw 12[$r0.59] = $r0.4   ## bblock 28, line 1823, t407, t496
;;								## 3
	c0    ldbu $r0.5 = (_?1PACKET.5 + 0)[$r0.5]   ## bblock 28, line 1830, t514, t512
;;								## 4
	c0    ldh $r0.2 = 0[$r0.60]   ## bblock 28, line 1832, t417(SI16), t3
	      xnop 1
;;								## 6
	c0    sh1add $r0.3 = $r0.5, ((_?1PACKET.10 + 0) + (~0x6b))   ## bblock 28, line 1832,  t784,  t514,  (addr(yypgoto?1.0)(P32) + 0xffffff94(I32))(P32)
	c0    sh1add $r0.4 = $r0.5, ((_?1PACKET.8 + 0) + (~0x6b))   ## bblock 28, line 1836,  t788,  t514,  (addr(yydefgoto?1.0)(P32) + 0xffffff94(I32))(P32)
;;								## 7
	c0    ldh $r0.3 = 0[$r0.3]   ## bblock 28, line 1832, t420(SI16), t784
	c0    add $r0.60 = $r0.60, 2   ## bblock 15, line 1165,  t3,  t3,  2(SI32)
;;								## 8
	c0    ldh.d $r0.4 = 0[$r0.4]   ## [spec] bblock 28, line 1836, t538, t788
	      xnop 1
;;								## 10
	c0    add $r0.3 = $r0.2, $r0.3   ## bblock 28, line 1832,  t513,  t417(SI16),  t420(SI16)
;;								## 11
	c0    cmpge $r0.6 = $r0.3, $r0.0   ## bblock 28, line 1833,  t422,  t513,  0(SI32)
	c0    ldbu.d $r0.5 = (_?1PACKET.12 + 0)[$r0.3]   ## [spec] bblock 28, line 1833, t425(I8), t513
;;								## 12
	c0    cmple $r0.7 = $r0.3, 288   ## bblock 28, line 1833,  t423,  t513,  288(SI32)
	c0    sh1add $r0.8 = $r0.3, (_?1PACKET.11 + 0)   ## bblock 28, line 1834,  t787,  t513,  addr(yytable?1.0)(P32)
;;								## 13
	c0    ldh.d $r0.8 = 0[$r0.8]   ## [spec] bblock 28, line 1834, t536, t787
;;								## 14
	c0    cmpeq $r0.5 = $r0.5, $r0.2   ## bblock 28, line 1833,  t523(I1),  t425(I8),  t417(SI16)
;;								## 15
	c0    andl $r0.6 = $r0.6, $r0.5   ## bblock 28, line 1833,  t785,  t422,  t523(I1)
;;								## 16
	c0    andl $b0.0 = $r0.6, $r0.7   ## bblock 28, line 1833,  t535(I1),  t785,  t423
;;								## 17
	c0    slct $r0.57 = $b0.0, $r0.8, $r0.4   ## bblock 28, line 1834,  t0,  t535(I1),  t536,  t538
	c0    goto L0?3 ## goto
;;								## 18
.trace 15
L29?3:
	c0    sh2add $r0.6 = $r0.5, ((_?1.yyparse.TAGPACKET.0 + 0) - 28)   ## bblock 25, line 499,  t783,  t512,  (addr(_?1.yyparse.TAGARRAY.0)(P32) - 0x1c(I32))(P32)
;;								## 0
	c0    ldw $l0.0 = 0[$r0.6]   ## bblock 25, line 499, t403, t783
	      xnop 3
;;								## 4
	c0    goto $l0.0   ## bblock 25, line 499,  t403
;;								## 5
.trace 38
_?1.yyparse.TAG.0.77:
	c0    ldw $r0.3 = 0[$r0.59]   ## bblock 27, line 495, t495, t12
	      xnop 1
;;								## 1
	c0    goto L30?3 ## goto
;;								## 2
.trace 43
_?1.yyparse.TAG.0.76:
	c0    ldw $r0.6 = 0[$r0.59]   ## bblock 33, line 494, t396, t12
	      xnop 2
;;								## 2
	c0    ldw $r0.3 = 0[$r0.6]   ## bblock 33, line 494, t495, t396
	      xnop 1
;;								## 4
	c0    goto L30?3 ## goto
;;								## 5
.trace 77
_?1.yyparse.TAG.0.75:
	c0    ldw $r0.3 = 0[$r0.59]   ## bblock 35, line 493, t495, t12
	      xnop 1
;;								## 1
	c0    goto L30?3 ## goto
;;								## 2
.trace 111
_?1.yyparse.TAG.0.74:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
;;								## 1
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 2
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 3
	c0    ldw $r0.3 = 0[$r0.59]   ## bblock 37, line 487, t392, t12
	      xnop 1
;;								## 5
.call build_numexp, caller, arg($r0.3:s32), ret($r0.3:u32)
	c0    call $l0.0 = build_numexp   ## bblock 37, line 487,  raddr(build_numexp)(P32),  t392
;;								## 6
	   ## bblock 38, line 487,  t495,  t390## $r0.3(skipped)
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 7
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 8
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 9
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 11
	c0    goto L30?3 ## goto
;;								## 12
.trace 81
_?1.yyparse.TAG.0.73:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
;;								## 1
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 2
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 3
	c0    ldw $r0.3 = 0[$r0.59]   ## bblock 40, line 486, t389, t12
	      xnop 1
;;								## 5
.call build_strexp, caller, arg($r0.3:u32), ret($r0.3:u32)
	c0    call $l0.0 = build_strexp   ## bblock 40, line 486,  raddr(build_strexp)(P32),  t389
;;								## 6
	   ## bblock 41, line 486,  t495,  t387## $r0.3(skipped)
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 7
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 8
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 9
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 11
	c0    goto L30?3 ## goto
;;								## 12
.trace 80
_?1.yyparse.TAG.0.72:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
;;								## 1
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 2
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 3
	c0    ldw $r0.3 = 0[$r0.59]   ## bblock 43, line 485, t386, t12
	      xnop 1
;;								## 5
.call build_strexp, caller, arg($r0.3:u32), ret($r0.3:u32)
	c0    call $l0.0 = build_strexp   ## bblock 43, line 485,  raddr(build_strexp)(P32),  t386
;;								## 6
	   ## bblock 44, line 485,  t495,  t384## $r0.3(skipped)
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 7
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 8
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 9
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 11
	c0    goto L30?3 ## goto
;;								## 12
.trace 79
_?1.yyparse.TAG.0.71:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
	c0    mov $r0.3 = 126   ## 126(SI32)
;;								## 0
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
;;								## 1
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 2
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 3
	c0    ldw $r0.4 = 0[$r0.59]   ## bblock 46, line 484, t383, t12
	      xnop 1
;;								## 5
.call build_unexp, caller, arg($r0.3:s32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = build_unexp   ## bblock 46, line 484,  raddr(build_unexp)(P32),  126(SI32),  t383
;;								## 6
	   ## bblock 47, line 484,  t495,  t381## $r0.3(skipped)
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 7
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 8
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 9
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 11
	c0    goto L30?3 ## goto
;;								## 12
.trace 40
_?1.yyparse.TAG.0.70:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
	c0    mov $r0.3 = 43   ## 43(SI32)
;;								## 0
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
;;								## 1
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 2
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 3
	c0    ldw $r0.4 = 0[$r0.59]   ## bblock 49, line 483, t380, t12
	      xnop 1
;;								## 5
.call build_unexp, caller, arg($r0.3:s32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = build_unexp   ## bblock 49, line 483,  raddr(build_unexp)(P32),  43(SI32),  t380
;;								## 6
	   ## bblock 50, line 483,  t495,  t378## $r0.3(skipped)
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 7
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 8
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 9
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 11
	c0    goto L30?3 ## goto
;;								## 12
.trace 39
_?1.yyparse.TAG.0.69:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
	c0    mov $r0.3 = 45   ## 45(SI32)
;;								## 0
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
;;								## 1
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 2
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 3
	c0    ldw $r0.4 = 0[$r0.59]   ## bblock 52, line 482, t377, t12
	      xnop 1
;;								## 5
.call build_unexp, caller, arg($r0.3:s32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = build_unexp   ## bblock 52, line 482,  raddr(build_unexp)(P32),  45(SI32),  t377
;;								## 6
	   ## bblock 53, line 482,  t495,  t375## $r0.3(skipped)
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 7
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 8
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 9
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 11
	c0    goto L30?3 ## goto
;;								## 12
.trace 106
_?1.yyparse.TAG.0.68:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
	c0    mov $r0.3 = 45   ## 45(SI32)
;;								## 0
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
;;								## 1
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 2
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 3
	c0    ldw $r0.4 = (~0xf)[$r0.59]   ## bblock 55, line 481, t372, t12
;;								## 4
	c0    ldw $r0.5 = 0[$r0.59]   ## bblock 55, line 481, t374, t12
	      xnop 1
;;								## 6
.call build_binexp, caller, arg($r0.3:s32,$r0.4:u32,$r0.5:u32), ret($r0.3:u32)
	c0    call $l0.0 = build_binexp   ## bblock 55, line 481,  raddr(build_binexp)(P32),  45(SI32),  t372,  t374
;;								## 7
	   ## bblock 56, line 481,  t495,  t370## $r0.3(skipped)
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 8
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 9
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 10
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 12
	c0    goto L30?3 ## goto
;;								## 13
.trace 97
_?1.yyparse.TAG.0.67:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
	c0    mov $r0.3 = 43   ## 43(SI32)
;;								## 0
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
;;								## 1
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 2
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 3
	c0    ldw $r0.4 = (~0xf)[$r0.59]   ## bblock 58, line 480, t367, t12
;;								## 4
	c0    ldw $r0.5 = 0[$r0.59]   ## bblock 58, line 480, t369, t12
	      xnop 1
;;								## 6
.call build_binexp, caller, arg($r0.3:s32,$r0.4:u32,$r0.5:u32), ret($r0.3:u32)
	c0    call $l0.0 = build_binexp   ## bblock 58, line 480,  raddr(build_binexp)(P32),  43(SI32),  t367,  t369
;;								## 7
	   ## bblock 59, line 480,  t495,  t365## $r0.3(skipped)
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 8
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 9
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 10
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 12
	c0    goto L30?3 ## goto
;;								## 13
.trace 110
_?1.yyparse.TAG.0.66:
	c0    ldw $r0.3 = (~0x7)[$r0.59]   ## bblock 61, line 479, t495, t12
	      xnop 1
;;								## 1
	c0    goto L30?3 ## goto
;;								## 2
.trace 45
_?1.yyparse.TAG.0.65:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.38 + 0)   ## addr(_?1STRINGVAR.38)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 63, line 469,  raddr(printf)(P32),  addr(_?1STRINGVAR.38)(P32)
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.3 = (~0x17)[$r0.59]   ## bblock 64, line 470, t357, t12
	      xnop 1
;;								## 6
.call print_exp, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = print_exp   ## bblock 64, line 470,  raddr(print_exp)(P32),  t357
;;								## 7
	c0    ldw $r0.4 = (~0x7)[$r0.59]   ## bblock 65, line 471, t362, t12
	c0    mov $r0.3 = (_?1STRINGPACKET.39 + 0)   ## addr(_?1STRINGVAR.39)(P32)
	      xnop 1
;;								## 9
.call printf, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 65, line 471,  raddr(printf)(P32),  addr(_?1STRINGVAR.39)(P32),  t362
;;								## 10
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 11
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 12
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 13
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 14
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 16
	c0    goto L30?3 ## goto
;;								## 17
.trace 87
_?1.yyparse.TAG.0.64:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.37 + 0)   ## addr(_?1STRINGVAR.37)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.4 = (~0x7)[$r0.59]   ## bblock 67, line 466, t352, t12
	      xnop 1
;;								## 6
.call printf, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 67, line 466,  raddr(printf)(P32),  addr(_?1STRINGVAR.37)(P32),  t352
;;								## 7
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 8
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 9
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 10
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 11
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 13
	c0    goto L30?3 ## goto
;;								## 14
.trace 100
_?1.yyparse.TAG.0.63:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.35 + 0)   ## addr(_?1STRINGVAR.35)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 69, line 461,  raddr(printf)(P32),  addr(_?1STRINGVAR.35)(P32)
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.3 = 0[$r0.59]   ## bblock 70, line 462, t344, t12
	      xnop 1
;;								## 6
.call print_exp, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = print_exp   ## bblock 70, line 462,  raddr(print_exp)(P32),  t344
;;								## 7
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 71, line 463,  raddr(printf)(P32),  addr(_?1STRINGVAR.36)(P32)
	c0    mov $r0.3 = (_?1STRINGPACKET.36 + 0)   ## addr(_?1STRINGVAR.36)(P32)
;;								## 8
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 9
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 10
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 11
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 12
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 14
	c0    goto L30?3 ## goto
;;								## 15
.trace 84
_?1.yyparse.TAG.0.62:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.34 + 0)   ## addr(_?1STRINGVAR.34)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 73, line 451,  raddr(printf)(P32),  addr(_?1STRINGVAR.34)(P32)
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 5
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 6
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 7
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 8
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 10
	c0    goto L30?3 ## goto
;;								## 11
.trace 112
_?1.yyparse.TAG.0.61:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.33 + 0)   ## addr(_?1STRINGVAR.33)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 75, line 450,  raddr(printf)(P32),  addr(_?1STRINGVAR.33)(P32)
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 5
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 6
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 7
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 8
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 10
	c0    goto L30?3 ## goto
;;								## 11
.trace 70
_?1.yyparse.TAG.0.60:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.32 + 0)   ## addr(_?1STRINGVAR.32)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 77, line 441,  raddr(printf)(P32),  addr(_?1STRINGVAR.32)(P32)
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 5
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 6
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 7
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 8
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 10
	c0    goto L30?3 ## goto
;;								## 11
.trace 74
_?1.yyparse.TAG.0.59:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.31 + 0)   ## addr(_?1STRINGVAR.31)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.7 = (~0xf)[$r0.59]   ## bblock 79, line 438, t327, t12
;;								## 5
	c0    ldw $r0.4 = (~0x17)[$r0.59]   ## bblock 79, line 438, t325, t12
;;								## 6
	c0    ldw $r0.6 = 0[$r0.59]   ## bblock 79, line 438, t330, t12
;;								## 7
	c0    ldw $r0.5 = 0[$r0.7]   ## bblock 79, line 438, t328, t327
	      xnop 1
;;								## 9
.call printf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32,$r0.6:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 79, line 438,  raddr(printf)(P32),  addr(_?1STRINGVAR.31)(P32),  t325,  t328,  t330
;;								## 10
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 11
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 12
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 13
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 14
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 16
	c0    goto L30?3 ## goto
;;								## 17
.trace 71
_?1.yyparse.TAG.0.58:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.30 + 0)   ## addr(_?1STRINGVAR.30)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.4 = 0[$r0.59]   ## bblock 81, line 432, t320, t12
	      xnop 1
;;								## 6
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 81, line 432,  raddr(printf)(P32),  addr(_?1STRINGVAR.30)(P32),  t320
;;								## 7
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 8
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 9
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 10
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 11
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 13
	c0    goto L30?3 ## goto
;;								## 14
.trace 114
_?1.yyparse.TAG.0.57:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.29 + 0)   ## addr(_?1STRINGVAR.29)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 83, line 427,  raddr(printf)(P32),  addr(_?1STRINGVAR.29)(P32)
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 5
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 6
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 7
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 8
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 10
	c0    goto L30?3 ## goto
;;								## 11
.trace 66
_?1.yyparse.TAG.0.56:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.28 + 0)   ## addr(_?1STRINGVAR.28)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.6 = 0[$r0.59]   ## bblock 85, line 424, t311, t12
;;								## 5
	c0    ldw $r0.4 = (~0x7)[$r0.59]   ## bblock 85, line 424, t309, t12
	      xnop 1
;;								## 7
	c0    ldw $r0.5 = 0[$r0.6]   ## bblock 85, line 424, t312, t311
	      xnop 1
;;								## 9
.call printf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 85, line 424,  raddr(printf)(P32),  addr(_?1STRINGVAR.28)(P32),  t309,  t312
;;								## 10
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 11
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 12
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 13
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 14
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 16
	c0    goto L30?3 ## goto
;;								## 17
.trace 76
_?1.yyparse.TAG.0.55:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.27 + 0)   ## addr(_?1STRINGVAR.27)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 87, line 410,  raddr(printf)(P32),  addr(_?1STRINGVAR.27)(P32)
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 5
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 6
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 7
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 8
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 10
	c0    goto L30?3 ## goto
;;								## 11
.trace 88
_?1.yyparse.TAG.0.54:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.26 + 0)   ## addr(_?1STRINGVAR.26)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.4 = ((_?1PACKET.3 + 0) + 0)[$r0.0]   ## bblock 89, line 402, t299, 0(I32)
	      xnop 1
;;								## 6
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 89, line 402,  raddr(printf)(P32),  addr(_?1STRINGVAR.26)(P32),  t299
;;								## 7
	c0    ldw $r0.6 = ((_?1PACKET.3 + 0) + 0)[$r0.0]   ## bblock 90, line 403, t300, 0(I32)
;;								## 8
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 9
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 10
	c0    add $r0.6 = $r0.6, 1   ## bblock 90, line 403,  t301,  t300,  1(SI32)
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 11
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 12
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
;;								## 13
	c0    stw ((_?1PACKET.3 + 0) + 0)[$r0.0] = $r0.6   ## bblock 90, line 403, 0(I32), t301
;;								## 14
	c0    goto L30?3 ## goto
;;								## 15
.trace 90
_?1.yyparse.TAG.0.46:
	c0    mov $r0.3 = 1   ## bblock 99, line 358,  t495,  1(SI32)
	c0    goto L30?3 ## goto
;;								## 0
.trace 63
_?1.yyparse.TAG.0.45:
	c0    mov $r0.3 = $r0.0   ## bblock 101, line 357,  t495,  0(SI32)
	c0    goto L30?3 ## goto
;;								## 0
.trace 62
_?1.yyparse.TAG.0.44:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.24 + 0)   ## addr(_?1STRINGVAR.24)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.4 = (~0xf)[$r0.59]   ## bblock 103, line 351, t290, t12
	      xnop 1
;;								## 6
.call printf, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 103, line 351,  raddr(printf)(P32),  addr(_?1STRINGVAR.24)(P32),  t290
;;								## 7
	c0    ldw $r0.3 = 0[$r0.59]   ## bblock 104, line 352, t292, t12
	      xnop 1
;;								## 9
.call print_exp, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = print_exp   ## bblock 104, line 352,  raddr(print_exp)(P32),  t292
;;								## 10
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 105, line 353,  raddr(printf)(P32),  addr(_?1STRINGVAR.25)(P32)
	c0    mov $r0.3 = (_?1STRINGPACKET.25 + 0)   ## addr(_?1STRINGVAR.25)(P32)
;;								## 11
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 12
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 13
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 14
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 15
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 17
	c0    goto L30?3 ## goto
;;								## 18
.trace 61
_?1.yyparse.TAG.0.43:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.23 + 0)   ## addr(_?1STRINGVAR.23)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.4 = 0[$r0.59]   ## bblock 107, line 346, t285, t12
	      xnop 1
;;								## 6
.call printf, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 107, line 346,  raddr(printf)(P32),  addr(_?1STRINGVAR.23)(P32),  t285
;;								## 7
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 8
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 9
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 10
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 11
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 13
	c0    goto L30?3 ## goto
;;								## 14
.trace 99
_?1.yyparse.TAG.0.42:
	c0    ldw $r0.3 = 0[$r0.59]   ## bblock 109, line 342, t495, t12
	      xnop 1
;;								## 1
	c0    goto L30?3 ## goto
;;								## 2
.trace 102
_?1.yyparse.TAG.0.41:
	c0    ldw $r0.3 = 0[$r0.59]   ## bblock 111, line 339, t495, t12
	      xnop 1
;;								## 1
	c0    goto L30?3 ## goto
;;								## 2
.trace 93
_?1.yyparse.TAG.0.38:
	c0    ldw $r0.4 = 0[$r0.59]   ## bblock 115, line 329, t496, t12
;;								## 0
	c0    ldw $r0.3 = (~0x7)[$r0.59]   ## bblock 115, line 328, t495, t12
	      xnop 1
;;								## 2
	c0    goto L30?3 ## goto
;;								## 3
.trace 96
_?1.yyparse.TAG.0.37:
	c0    ldw $r0.4 = 0[$r0.59]   ## bblock 117, line 325, t496, t12
;;								## 0
	c0    ldw $r0.3 = (~0x7)[$r0.59]   ## bblock 117, line 324, t495, t12
	      xnop 1
;;								## 2
	c0    goto L30?3 ## goto
;;								## 3
.trace 89
_?1.yyparse.TAG.0.36:
	c0    mov $r0.3 = (_?1STRINGPACKET.22 + 0)   ## bblock 119, line 320,  t495,  addr(_?1STRINGVAR.22)(P32)
	c0    goto L30?3 ## goto
;;								## 0
.trace 101
_?1.yyparse.TAG.0.35:
	c0    ldw $r0.3 = 0[$r0.59]   ## bblock 121, line 319, t495, t12
	      xnop 1
;;								## 1
	c0    goto L30?3 ## goto
;;								## 2
.trace 58
_?1.yyparse.TAG.0.34:
	c0    ldw $r0.3 = 0[$r0.59]   ## bblock 123, line 318, t495, t12
	      xnop 1
;;								## 1
	c0    goto L30?3 ## goto
;;								## 2
.trace 57
_?1.yyparse.TAG.0.30:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.21 + 0)   ## addr(_?1STRINGVAR.21)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.6 = 0[$r0.59]   ## bblock 128, line 309, t261, t12
;;								## 5
	c0    ldw $r0.4 = (~0x7)[$r0.59]   ## bblock 128, line 309, t258, t12
	      xnop 1
;;								## 7
	c0    sh2add $r0.6 = $r0.6, (_?1PACKET.2 + 0)   ## bblock 128, line 309,  t789,  t261,  addr(vexscope?1.0)(P32)
;;								## 8
	c0    ldw $r0.5 = 0[$r0.6]   ## bblock 128, line 309, t262, t789
	      xnop 1
;;								## 10
.call printf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 128, line 309,  raddr(printf)(P32),  addr(_?1STRINGVAR.21)(P32),  t258,  t262
;;								## 11
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 12
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 13
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 14
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 15
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 17
	c0    goto L30?3 ## goto
;;								## 18
.trace 98
_?1.yyparse.TAG.0.29:
	c0    stw ((_?1PACKET.3 + 0) + 0)[$r0.0] = $r0.0   ## bblock 130, line 288, 0(I32), 0(SI32)
	c0    goto L30?3 ## goto
;;								## 0
.trace 56
_?1.yyparse.TAG.0.28:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.20 + 0)   ## addr(_?1STRINGVAR.20)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.6 = (~0x7)[$r0.59]   ## bblock 132, line 283, t252, t12
;;								## 5
	c0    ldw $r0.4 = (~0xf)[$r0.59]   ## bblock 132, line 283, t249, t12
	      xnop 1
;;								## 7
	c0    sh2add $r0.6 = $r0.6, (_?1PACKET.2 + 0)   ## bblock 132, line 283,  t790,  t252,  addr(vexscope?1.0)(P32)
;;								## 8
	c0    ldw $r0.5 = 0[$r0.6]   ## bblock 132, line 283, t253, t790
	      xnop 1
;;								## 10
.call printf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 132, line 283,  raddr(printf)(P32),  addr(_?1STRINGVAR.20)(P32),  t249,  t253
;;								## 11
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 12
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 13
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 14
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 15
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 17
	c0    goto L30?3 ## goto
;;								## 18
.trace 55
_?1.yyparse.TAG.0.27:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.19 + 0)   ## addr(_?1STRINGVAR.19)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.4 = (~0x17)[$r0.59]   ## bblock 134, line 279, t244, t12
	      xnop 1
;;								## 6
.call printf, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 134, line 279,  raddr(printf)(P32),  addr(_?1STRINGVAR.19)(P32),  t244
;;								## 7
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 8
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 9
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 10
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 11
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 13
	c0    goto L30?3 ## goto
;;								## 14
.trace 54
_?1.yyparse.TAG.0.26:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.18 + 0)   ## addr(_?1STRINGVAR.18)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.6 = 4[$r0.59]   ## bblock 136, line 276, t238, t12
;;								## 5
	c0    ldw $r0.4 = 0[$r0.59]   ## bblock 136, line 276, t235, t12
	      xnop 1
;;								## 7
	c0    sh2add $r0.6 = $r0.6, (_?1PACKET.2 + 0)   ## bblock 136, line 276,  t791,  t238,  addr(vexscope?1.0)(P32)
;;								## 8
	c0    ldw $r0.5 = 0[$r0.6]   ## bblock 136, line 276, t239, t791
	      xnop 1
;;								## 10
.call printf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 136, line 276,  raddr(printf)(P32),  addr(_?1STRINGVAR.18)(P32),  t235,  t239
;;								## 11
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 12
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 13
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 14
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 15
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 17
	c0    goto L30?3 ## goto
;;								## 18
.trace 69
_?1.yyparse.TAG.0.25:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.17 + 0)   ## addr(_?1STRINGVAR.17)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.4 = 0[$r0.59]   ## bblock 138, line 270, t230, t12
	      xnop 1
;;								## 6
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 138, line 270,  raddr(printf)(P32),  addr(_?1STRINGVAR.17)(P32),  t230
;;								## 7
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 8
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 9
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 10
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 11
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 13
	c0    goto L30?3 ## goto
;;								## 14
.trace 52
_?1.yyparse.TAG.0.24:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.16 + 0)   ## addr(_?1STRINGVAR.16)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.6 = 0[$r0.59]   ## bblock 140, line 242, t224, t12
;;								## 5
	c0    ldw $r0.4 = (~0x7)[$r0.59]   ## bblock 140, line 242, t221, t12
	      xnop 1
;;								## 7
	c0    sh2add $r0.6 = $r0.6, (_?1PACKET.2 + 0)   ## bblock 140, line 242,  t792,  t224,  addr(vexscope?1.0)(P32)
;;								## 8
	c0    ldw $r0.5 = 0[$r0.6]   ## bblock 140, line 242, t225, t792
	      xnop 1
;;								## 10
.call printf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 140, line 242,  raddr(printf)(P32),  addr(_?1STRINGVAR.16)(P32),  t221,  t225
;;								## 11
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 12
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 13
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 14
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 15
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 17
	c0    goto L30?3 ## goto
;;								## 18
.trace 85
_?1.yyparse.TAG.0.23:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.15 + 0)   ## addr(_?1STRINGVAR.15)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.4 = 0[$r0.59]   ## bblock 142, line 236, t216, t12
	      xnop 1
;;								## 6
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 142, line 236,  raddr(printf)(P32),  addr(_?1STRINGVAR.15)(P32),  t216
;;								## 7
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 8
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 9
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 10
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 11
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 13
	c0    goto L30?3 ## goto
;;								## 14
.trace 72
_?1.yyparse.TAG.0.22:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.14 + 0)   ## addr(_?1STRINGVAR.14)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.4 = 0[$r0.59]   ## bblock 144, line 233, t211, t12
	      xnop 1
;;								## 6
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 144, line 233,  raddr(printf)(P32),  addr(_?1STRINGVAR.14)(P32),  t211
;;								## 7
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 8
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 9
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 10
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 11
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 13
	c0    goto L30?3 ## goto
;;								## 14
.trace 50
_?1.yyparse.TAG.0.21:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.13 + 0)   ## addr(_?1STRINGVAR.13)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.4 = 0[$r0.59]   ## bblock 146, line 210, t206, t12
	      xnop 1
;;								## 6
.call printf, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 146, line 210,  raddr(printf)(P32),  addr(_?1STRINGVAR.13)(P32),  t206
;;								## 7
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 8
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 9
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 10
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 11
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 13
	c0    goto L30?3 ## goto
;;								## 14
.trace 67
_?1.yyparse.TAG.0.20:
	c0    ldw $r0.3 = 0[$r0.59]   ## bblock 148, line 205, t495, t12
	      xnop 1
;;								## 1
	c0    goto L30?3 ## goto
;;								## 2
.trace 49
_?1.yyparse.TAG.0.19:
	c0    mov $r0.3 = $r0.0   ## bblock 150, line 204,  t495,  0(SI32)
	c0    goto L30?3 ## goto
;;								## 0
.trace 92
_?1.yyparse.TAG.0.18:
	c0    mov $r0.3 = 8   ## bblock 152, line 201,  t495,  8(SI32)
	c0    goto L30?3 ## goto
;;								## 0
.trace 94
_?1.yyparse.TAG.0.17:
	c0    mov $r0.3 = 4   ## bblock 154, line 200,  t495,  4(SI32)
	c0    goto L30?3 ## goto
;;								## 0
.trace 64
_?1.yyparse.TAG.0.16:
	c0    mov $r0.3 = 4   ## bblock 156, line 199,  t495,  4(SI32)
	c0    goto L30?3 ## goto
;;								## 0
.trace 47
_?1.yyparse.TAG.0.15:
	c0    mov $r0.3 = 2   ## bblock 158, line 198,  t495,  2(SI32)
	c0    goto L30?3 ## goto
;;								## 0
.trace 91
_?1.yyparse.TAG.0.14:
	c0    mov $r0.3 = 1   ## bblock 160, line 197,  t495,  1(SI32)
	c0    goto L30?3 ## goto
;;								## 0
.trace 86
_?1.yyparse.TAG.0.13:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
;;								## 1
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 2
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 3
	c0    ldw $r0.3 = (~0xf)[$r0.59]   ## bblock 162, line 195, t199, t12
	      xnop 1
;;								## 5
.call build_numexp, caller, arg($r0.3:s32), ret($r0.3:u32)
	c0    call $l0.0 = build_numexp   ## bblock 162, line 195,  raddr(build_numexp)(P32),  t199
;;								## 6
	   ## bblock 163, line 195,  t495,  t197## $r0.3(skipped)
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 7
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 8
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 9
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 11
	c0    goto L30?3 ## goto
;;								## 12
.trace 109
_?1.yyparse.TAG.0.12:
	c0    ldw $r0.3 = 0[$r0.59]   ## bblock 165, line 194, t495, t12
	      xnop 1
;;								## 1
	c0    goto L30?3 ## goto
;;								## 2
.trace 48
_?1.yyparse.TAG.0.11:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.12 + 0)   ## addr(_?1STRINGVAR.12)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.4 = 0[$r0.59]   ## bblock 167, line 190, t194, t12
	      xnop 1
;;								## 6
.call printf, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 167, line 190,  raddr(printf)(P32),  addr(_?1STRINGVAR.12)(P32),  t194
;;								## 7
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 8
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 9
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 10
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 11
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 13
	c0    goto L30?3 ## goto
;;								## 14
.trace 73
_?1.yyparse.TAG.0.10:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.11 + 0)   ## addr(_?1STRINGVAR.11)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.4 = 0[$r0.59]   ## bblock 169, line 187, t189, t12
	      xnop 1
;;								## 6
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 169, line 187,  raddr(printf)(P32),  addr(_?1STRINGVAR.11)(P32),  t189
;;								## 7
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 8
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 9
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 10
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 11
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 13
	c0    goto L30?3 ## goto
;;								## 14
.trace 44
_?1.yyparse.TAG.0.9:
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 0
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
;;								## 2
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 3
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
	c0    mov $r0.3 = (_?1STRINGPACKET.7 + 0)   ## addr(_?1STRINGVAR.7)(P32)
;;								## 4
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 171, line 178,  raddr(printf)(P32),  addr(_?1STRINGVAR.7)(P32)
;;								## 5
	c0    ldw $r0.3 = (~0x7)[$r0.59]   ## bblock 172, line 179, t169, t12
	      xnop 1
;;								## 7
.call print_exp, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = print_exp   ## bblock 172, line 179,  raddr(print_exp)(P32),  t169
;;								## 8
	c0    ldw $r0.4 = (~0xf)[$r0.59]   ## bblock 173, line 180, t174, t12
	c0    mov $r0.3 = (_?1STRINGPACKET.8 + 0)   ## addr(_?1STRINGVAR.8)(P32)
	      xnop 1
;;								## 10
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 173, line 180,  raddr(printf)(P32),  addr(_?1STRINGVAR.8)(P32),  t174
;;								## 11
	c0    ldw $r0.4 = 0[$r0.59]   ## bblock 174, line 181, t176, t12
	c0    mov $r0.3 = (_?1STRINGPACKET.9 + 0)   ## addr(_?1STRINGVAR.9)(P32)
	      xnop 2
;;								## 14
	c0    cmpne $b0.0 = $r0.4, $r0.0   ## bblock 174, line 181,  t793(I1),  t176,  0(SI32)
	      xnop 1
;;								## 16
	c0    brf $b0.0, L31?3   ## bblock 174, line 181,  t793(I1)
;;								## 17
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 176, line 182,  raddr(printf)(P32),  addr(_?1STRINGVAR.9)(P32),  t176
;;								## 18
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 19
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 20
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 21
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 22
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 24
	c0    goto L30?3 ## goto
;;								## 25
.trace 116
L31?3:
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 175, line 184,  raddr(printf)(P32),  addr(_?1STRINGVAR.10)(P32)
	c0    mov $r0.3 = (_?1STRINGPACKET.10 + 0)   ## addr(_?1STRINGVAR.10)(P32)
;;								## 0
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 1
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 2
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 3
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 4
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 6
	c0    goto L30?3 ## goto
;;								## 7
.trace 42
_?1.yyparse.TAG.0.3:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.6 + 0)   ## addr(_?1STRINGVAR.6)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.6 = 0[$r0.59]   ## bblock 183, line 164, t163, t12
;;								## 5
	c0    ldw $r0.4 = (~0x7)[$r0.59]   ## bblock 183, line 164, t160, t12
	      xnop 1
;;								## 7
	c0    sh2add $r0.6 = $r0.6, (_?1PACKET.2 + 0)   ## bblock 183, line 164,  t794,  t163,  addr(vexscope?1.0)(P32)
;;								## 8
	c0    ldw $r0.5 = 0[$r0.6]   ## bblock 183, line 164, t164, t794
	      xnop 1
;;								## 10
.call printf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 183, line 164,  raddr(printf)(P32),  addr(_?1STRINGVAR.6)(P32),  t160,  t164
;;								## 11
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 12
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 13
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 14
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 15
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 17
	c0    goto L30?3 ## goto
;;								## 18
.trace 82
_?1.yyparse.TAG.0.2:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.5 + 0)   ## addr(_?1STRINGVAR.5)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.4 = 0[$r0.59]   ## bblock 185, line 160, t155, t12
	      xnop 1
;;								## 6
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 185, line 160,  raddr(printf)(P32),  addr(_?1STRINGVAR.5)(P32),  t155
;;								## 7
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 8
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 9
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 10
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 11
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 13
	c0    goto L30?3 ## goto
;;								## 14
.trace 41
_?1.yyparse.TAG.0.1:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
	c0    mov $r0.3 = (_?1STRINGPACKET.4 + 0)   ## addr(_?1STRINGVAR.4)(P32)
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.4 = 0[$r0.59]   ## bblock 187, line 157, t150, t12
	      xnop 1
;;								## 6
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 187, line 157,  raddr(printf)(P32),  addr(_?1STRINGVAR.4)(P32),  t150
;;								## 7
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 8
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 9
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 10
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 11
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 13
	c0    goto L30?3 ## goto
;;								## 14
.trace 59
_?1.yyparse.TAG.0.0:
	c0    stw 0x828[$r0.1] = $r0.2  ## spill ## t494
;;								## 0
	c0    stw 0x834[$r0.1] = $r0.3  ## spill ## t495
;;								## 1
	c0    stw 0x82c[$r0.1] = $r0.4  ## spill ## t496
;;								## 2
	c0    stw 0x830[$r0.1] = $r0.5  ## spill ## t512
	c0    mov $r0.4 = (_?1STRINGPACKET.3 + 0)   ## addr(_?1STRINGVAR.3)(P32)
;;								## 3
	c0    stw 0x7ec[$r0.1] = $r0.11  ## spill ## t497
;;								## 4
	c0    ldw $r0.3 = ((yyout + 0) + 0)[$r0.0]   ## bblock 189, line 133, t141, 0(I32)
;;								## 5
	c0    ldw $r0.5 = 0[$r0.59]   ## bblock 189, line 133, t145, t12
	      xnop 1
;;								## 7
.call fprintf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32), ret($r0.3:s32)
	c0    call $l0.0 = fprintf   ## bblock 189, line 133,  raddr(fprintf)(P32),  t141,  addr(_?1STRINGVAR.3)(P32),  t145
;;								## 8
	c0    ldw $r0.2 = 0x828[$r0.1]  ## restore ## t494
;;								## 9
	c0    ldw $r0.3 = 0x834[$r0.1]  ## restore ## t495
;;								## 10
	c0    ldw $r0.4 = 0x82c[$r0.1]  ## restore ## t496
;;								## 11
	c0    ldw $r0.5 = 0x830[$r0.1]  ## restore ## t512
;;								## 12
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 14
	c0    goto L30?3 ## goto
;;								## 15
.trace 10
L12?3:
	c0    ldw $r0.6 = ((yychar + 0) + 0)[$r0.0]   ## bblock 3, line 1257, t103, 0(I32)
	c0    mov $r0.62 = $r0.0   ## [spec] bblock 214, line 1265,  t500,  0(SI32)
	c0    cmpeq $b0.0 = $r0.61, $r0.0   ## [spec] bblock 191, line 1846,  t795(I1),  t501,  0(SI32)
;;								## 0
	c0    ldw.d $r0.7 = ((yychar + 0) + 0)[$r0.0]   ## [spec] bblock 4, line 1263, t105, 0(I32)
	c0    add $r0.8 = $r0.62, $r0.2   ## [spec] bblock 8, line 1276,  t510,  t500,  t1
;;								## 1
	c0    cmplt $r0.10 = $r0.8, $r0.0   ## [spec] bblock 8, line 1277,  t113,  t510,  0(SI32)
	c0    ldbu.d $r0.9 = (_?1PACKET.12 + 0)[$r0.8]   ## [spec] bblock 8, line 1277, t116(I8), t510
;;								## 2
	c0    cmpeq $b0.1 = $r0.6, -2   ## bblock 3, line 1257,  t770(I1),  t103,  -2(SI32)
	c0    cmpgt $r0.12 = $r0.8, 288   ## [spec] bblock 8, line 1277,  t114,  t510,  288(SI32)
;;								## 3
	c0    cmple $b0.3 = $r0.7, $r0.0   ## [spec] bblock 4, line 1263,  t771(I1),  t105,  0(SI32)
	c0    orl $r0.10 = $r0.10, $r0.12   ## [spec] bblock 8, line 1277,  t520(I1),  t113,  t114
	c0    ldbu.d $r0.4 = (_?1PACKET.7 + 0)[$r0.57]   ## [spec] bblock 212, line 1314, t512, t0
;;								## 4
	c0    cmpne $r0.9 = $r0.9, $r0.62   ## [spec] bblock 8, line 1277,  t521(I1),  t116(I8),  t500
	c0    ldw.d $r0.6 = ((yynerrs + 0) + 0)[$r0.0]   ## [spec] bblock 211, line 1848, t433, 0(I32)
	c0    br $b0.1, L32?3   ## bblock 3, line 1257,  t770(I1)
;;								## 5
L33?3:
	c0    norl $b0.1 = $r0.10, $r0.9   ## [spec] bblock 8, line 1277,  t773(I1),  t520(I1),  t521(I1)
	c0    mov $r0.3 = (_?1STRINGPACKET.40 + 0)   ## addr(_?1STRINGVAR.40)(P32)
	c0    brf $b0.3, L34?3   ## bblock 4, line 1263,  t771(I1)
;;								## 6
	c0    stw ((yychar + 0) + 0)[$r0.0] = $r0.0   ## bblock 214, line 1265, 0(I32), 0(SI32)
	c0    cmpeq $b0.2 = $r0.4, $r0.0   ## [spec] bblock 212, line 1315,  t808(I1),  t512,  0(SI32)
;;								## 7
L35?3:
	c0    add $r0.5 = $r0.6, 1   ## [spec] bblock 211, line 1848,  t434,  t433,  1(SI32)
	c0    br $b0.1, L36?3   ## bblock 8, line 1277,  t773(I1)
	      ## goto
;;
	c0    goto L13?3 ## goto
;;								## 8
.trace 25
L36?3:
	c0    sh1add $r0.8 = $r0.8, (_?1PACKET.11 + 0)   ## bblock 10, line 1279,  t774,  t510,  addr(yytable?1.0)(P32)
	c0    ldw.d $r0.4 = ((yynerrs + 0) + 0)[$r0.0]   ## [spec] bblock 211, line 1848, t433, 0(I32)
;;								## 0
	c0    ldh $r0.8 = 0[$r0.8]   ## bblock 10, line 1279, t511, t774
	c0    cmpeq $b0.0 = $r0.61, $r0.0   ## [spec] bblock 191, line 1846,  t795(I1),  t501,  0(SI32)
	c0    mov $r0.3 = (_?1STRINGPACKET.40 + 0)   ## addr(_?1STRINGVAR.40)(P32)
	      xnop 1
;;								## 2
	c0    add $r0.5 = $r0.4, 1   ## [spec] bblock 211, line 1848,  t434,  t433,  1(SI32)
;;								## 3
	c0    cmple $b0.1 = $r0.8, $r0.0   ## bblock 10, line 1280,  t775(I1),  t511,  0(SI32)
	c0    cmpeq $r0.6 = $r0.8, -126   ## [spec] bblock 22, line 1282,  t121,  t511,  -126(SI32)
	c0    cmpeq $r0.4 = $r0.8, $r0.0   ## [spec] bblock 22, line 1282,  t781,  t511,  0(I32)
;;								## 4
	c0    orl $b0.2 = $r0.4, $r0.6   ## [spec] bblock 22, line 1282,  t780(I1),  t781,  t121
;;								## 5
	c0    brf $b0.1, L37?3   ## bblock 10, line 1280,  t775(I1)
;;								## 6
	c0    brf $b0.2, L38?3   ## bblock 22, line 1282,  t780(I1)
	      ## goto
;;
	c0    goto L15?3 ## goto
;;								## 7
.trace 35
L38?3:
	c0    sub $r0.4 = $r0.0, $r0.8   ## bblock 23, line 1284,  t512,  0(I32),  t511
	c0    goto L14?3 ## goto
;;								## 0
.trace 32
L37?3:
	c0    cmpeq $b0.0 = $r0.8, 19   ## bblock 11, line 1288,  t776(I1),  t511,  19(SI32)
	c0    ldw.d $r0.3 = ((yychar + 0) + 0)[$r0.0]   ## [spec] bblock 12, line 1295, t123, 0(I32)
	c0    mov $r0.2 = -2   ## -2(SI32)
;;								## 0
	c0    ldw.d $r0.4 = ((yylval + 0) + 0)[$r0.0]   ## [spec] bblock 13, line 1298, t124, 0(I32)
	c0    add $r0.5 = $r0.61, -1   ## [spec] bblock 13, line 1304,  t534,  t501,  -1(SI32)
	c0    cmpne $b0.1 = $r0.61, $r0.0   ## [spec] bblock 13, line 1304,  t778(I1),  t501,  0(I32)
;;								## 1
	c0    ldw.d $r0.6 = ((yylval + 4) + 0)[$r0.0]   ## [spec] bblock 13, line 1298, t125, 0(I32)
	c0    mov $r0.57 = $r0.8   ## [spec] bblock 13, line 1306,  t0,  t511
	c0    br $b0.0, L39?3   ## bblock 11, line 1288,  t776(I1)
;;								## 2
	c0    cmpne $b0.0 = $r0.3, $r0.0   ## bblock 12, line 1295,  t777(I1),  t123,  0(SI32)
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
	      xnop 1
;;								## 4
	c0    brf $b0.0, L40?3   ## bblock 12, line 1295,  t777(I1)
;;								## 5
	c0    stw ((yychar + 0) + 0)[$r0.0] = $r0.2   ## bblock 17, line 1296, 0(I32), -2(SI32)
	c0    slct $r0.61 = $b0.1, $r0.5, $r0.61   ## bblock 13, line 1304,  t501,  t778(I1),  t534,  t501
	c0    add $r0.60 = $r0.60, 2   ## bblock 15, line 1165,  t3,  t3,  2(SI32)
;;								## 6
L41?3:
	c0    stw 8[$r0.63] = $r0.4   ## bblock 13, line 1298, t12, t124
;;								## 7
	c0    stw 12[$r0.63] = $r0.6   ## bblock 13, line 1298, t12, t125
;;								## 8
	c0    add $r0.63 = $r0.63, 8   ## bblock 13, line 1298,  t12,  t12,  8(SI32)
	c0    goto L0?3 ## goto
;;								## 9
.trace 36
L40?3:
	c0    slct $r0.61 = $b0.1, $r0.5, $r0.61   ## bblock 13, line 1304,  t501,  t778(I1),  t534,  t501
	c0    add $r0.60 = $r0.60, 2   ## bblock 15, line 1165,  t3,  t3,  2(SI32)
	c0    goto L41?3 ## goto
;;								## 0
.trace 123
L39?3:
	c0    mov $r0.3 = $r0.0   ## bblock 18, line 1980,  t502,  0(SI32)
	c0    mov $r0.2 = $r0.58   ## t499
	c0    ldw $r0.57 = 0x824[$r0.1]  ## restore ## t482
;;								## 0
	c0    ldw $r0.4 = 0x800[$r0.1]  ## restore ## t2
	c0    goto L26?3 ## goto
;;								## 1
.trace 16
L34?3:
	c0    ldw $r0.5 = ((yychar + 0) + 0)[$r0.0]   ## bblock 5, line 1270, t107, 0(I32)
	c0    mov $r0.3 = (_?1STRINGPACKET.40 + 0)   ## addr(_?1STRINGVAR.40)(P32)
	      xnop 2
;;								## 2
	c0    cmpgtu $b0.2 = $r0.5, 296   ## bblock 5, line 1270,  t530(I1),  t107,  296(SI32)
	c0    ldbu.d $r0.7 = (_?1PACKET.4 + 0)[$r0.5]   ## [spec] bblock 5, line 1270, t531, t107
	      xnop 2
;;								## 5
	c0    slctf $r0.62 = $b0.2, $r0.7, 2   ## bblock 5, line 1270,  t500,  t530(I1),  t531,  2(SI32)
;;								## 6
	c0    add $r0.8 = $r0.62, $r0.2   ## bblock 8, line 1276,  t510,  t500,  t1
;;								## 7
	c0    cmplt $r0.10 = $r0.8, $r0.0   ## bblock 8, line 1277,  t113,  t510,  0(SI32)
	c0    ldbu.d $r0.9 = (_?1PACKET.12 + 0)[$r0.8]   ## [spec] bblock 8, line 1277, t116(I8), t510
;;								## 8
	c0    cmpgt $r0.12 = $r0.8, 288   ## bblock 8, line 1277,  t114,  t510,  288(SI32)
;;								## 9
	c0    orl $r0.10 = $r0.10, $r0.12   ## bblock 8, line 1277,  t520(I1),  t113,  t114
;;								## 10
	c0    cmpne $r0.9 = $r0.9, $r0.62   ## bblock 8, line 1277,  t521(I1),  t116(I8),  t500
;;								## 11
	c0    norl $b0.1 = $r0.10, $r0.9   ## bblock 8, line 1277,  t773(I1),  t520(I1),  t521(I1)
;;								## 12
	c0    cmpeq $b0.2 = $r0.4, $r0.0   ## [spec] bblock 212, line 1315,  t808(I1),  t512,  0(SI32)
	c0    goto L35?3 ## goto
;;								## 13
.trace 17
L32?3:
	c0    stw 0x804[$r0.1] = $r0.2  ## spill ## t1
;;								## 0
.call yylex, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = yylex   ## bblock 215, line 1260,  raddr(yylex)(P32)
;;								## 1
	c0    mov $r0.62 = $r0.0   ## [spec] bblock 214, line 1265,  t500,  0(SI32)
	c0    cmpeq $b0.0 = $r0.61, $r0.0   ## [spec] bblock 191, line 1846,  t795(I1),  t501,  0(SI32)
	c0    ldw $r0.2 = 0x804[$r0.1]  ## restore ## t1
;;								## 2
	c0    stw ((yychar + 0) + 0)[$r0.0] = $r0.3   ## bblock 216, line 1260, 0(I32), t104
;;								## 3
	c0    ldw $r0.7 = ((yychar + 0) + 0)[$r0.0]   ## bblock 4, line 1263, t105, 0(I32)
;;								## 4
	c0    add $r0.8 = $r0.62, $r0.2   ## [spec] bblock 8, line 1276,  t510,  t500,  t1
;;								## 5
	c0    cmplt $r0.4 = $r0.8, $r0.0   ## [spec] bblock 8, line 1277,  t113,  t510,  0(SI32)
	c0    ldbu.d $r0.3 = (_?1PACKET.12 + 0)[$r0.8]   ## [spec] bblock 8, line 1277, t116(I8), t510
;;								## 6
	c0    cmple $b0.3 = $r0.7, $r0.0   ## bblock 4, line 1263,  t771(I1),  t105,  0(SI32)
	c0    cmpgt $r0.12 = $r0.8, 288   ## [spec] bblock 8, line 1277,  t114,  t510,  288(SI32)
;;								## 7
	c0    orl $r0.10 = $r0.4, $r0.12   ## [spec] bblock 8, line 1277,  t520(I1),  t113,  t114
;;								## 8
	c0    cmpne $r0.9 = $r0.3, $r0.62   ## [spec] bblock 8, line 1277,  t521(I1),  t116(I8),  t500
	c0    ldbu.d $r0.4 = (_?1PACKET.7 + 0)[$r0.57]   ## [spec] bblock 212, line 1314, t512, t0
;;								## 9
	c0    ldw.d $r0.6 = ((yynerrs + 0) + 0)[$r0.0]   ## [spec] bblock 211, line 1848, t433, 0(I32)
	c0    goto L33?3 ## goto
;;								## 10
.trace 119
L42?3:
	c0    mov $r0.2 = $r0.58   ## t499
	c0    ldw $r0.4 = 0x800[$r0.1]  ## restore ## t2
;;								## 0
	c0    ldw $r0.57 = 0x824[$r0.1]  ## restore ## t482
;;								## 1
	c0    ldw $r0.58 = 0x820[$r0.1]  ## restore ## t483
;;								## 2
	c0    ldw $r0.59 = 0x81c[$r0.1]  ## restore ## t484
;;								## 3
	c0    ldw $r0.60 = 0x818[$r0.1]  ## restore ## t485
;;								## 4
	c0    ldw $r0.61 = 0x814[$r0.1]  ## restore ## t486
;;								## 5
	c0    ldw $r0.62 = 0x810[$r0.1]  ## restore ## t487
;;								## 6
	c0    ldw $r0.63 = 0x80c[$r0.1]  ## restore ## t488
	      xnop 1
;;								## 8
	c0    goto L22?3 ## goto
;;								## 9
.trace 29
L9?3:
	c0    mov $r0.58 = $r0.15   ## bblock 225, line 1215,  t498,  t491
	c0    stw 0x7f4[$r0.1] = $r0.14  ## spill ## t499
	c0    mov $r0.3 = $r0.11   ## t492
	      ## goto
;;
	c0    goto L11?3 ## goto
;;								## 0
.trace 27
L8?3:
	c0    mov $r0.58 = $r0.15   ## bblock 225, line 1215,  t498,  t491
	c0    stw 0x7f4[$r0.1] = $r0.14  ## spill ## t499
	c0    mov $r0.3 = $r0.11   ## t492
	      ## goto
;;
	c0    goto L11?3 ## goto
;;								## 0
.trace 12
L7?3:
	c0    mov $r0.58 = $r0.15   ## bblock 225, line 1215,  t498,  t491
	c0    stw 0x7f4[$r0.1] = $r0.14  ## spill ## t499
	c0    mov $r0.3 = $r0.11   ## t492
;;								## 0
L11?3:
	c0    stw 0x7ec[$r0.1] = $r0.12  ## spill ## t497
;;								## 1
	c0    stw 0x7f8[$r0.1] = $r0.13  ## spill ## t34
;;								## 2
	c0    stw 0x7fc[$r0.1] = $r0.15  ## spill ## t491
;;								## 3
	c0    stw 0x7f0[$r0.1] = $r0.58  ## spill ## t498
;;								## 4
	c0    ldw $r0.2 = 0x800[$r0.1]  ## restore ## t2
	      xnop 2
;;								## 7
	c0    cmpne $b0.0 = $r0.11, $r0.2   ## bblock 225, line 1218,  t816(I1),  t492,  t2
	      xnop 1
;;								## 9
	c0    brf $b0.0, L43?3   ## bblock 225, line 1218,  t816(I1)
;;								## 10
.call free, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = free   ## bblock 227, line 1219,  raddr(free)(P32),  t492
;;								## 11
L43?3:
	c0    ldw $r0.3 = 0x7fc[$r0.1]  ## restore ## t491
;;								## 12
	c0    ldw $r0.11 = 0x7ec[$r0.1]  ## restore ## t497
;;								## 13
	c0    ldw $r0.2 = 0x7f8[$r0.1]  ## restore ## t34
;;								## 14
	c0    sh3add $r0.63 = $r0.59, $r0.3   ## bblock 226, line 1225,  t12,  t27,  t491
	c0    ldw $r0.58 = 0x7f4[$r0.1]  ## restore ## t499
;;								## 15
	c0    add $r0.4 = $r0.11, -1   ## bblock 226, line 1231,  t97,  t497,  -1(SI32)
;;								## 16
	c0    sh1add $r0.60 = $r0.59, $r0.2   ## bblock 226, line 1224,  t3,  t27,  t34
	c0    sh1add $r0.4 = $r0.4, $r0.2   ## bblock 226, line 1231,  t100,  t97,  t34
;;								## 17
	c0    cmpleu $b0.0 = $r0.4, $r0.60   ## bblock 226, line 1231,  t817(I1),  t100,  t3
	      xnop 1
;;								## 19
	c0    br $b0.0, L42?3   ## bblock 226, line 1231,  t817(I1)
	      ## goto
;;
	c0    goto L1?3 ## goto
;;								## 20
.trace 118
L3?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.41 + 0)   ## addr(_?1STRINGVAR.41)(P32)
;;								## 0
.call yyerror, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = yyerror   ## bblock 230, line 1995,  raddr(yyerror)(P32),  addr(_?1STRINGVAR.41)(P32)
	      ## goto
;;
	c0    goto L44?3 ## goto
;;								## 1
.trace 117
L2?3:
.call yyerror, caller, arg($r0.3:u32), ret()
	c0    call $l0.0 = yyerror   ## bblock 230, line 1995,  raddr(yyerror)(P32),  addr(_?1STRINGVAR.41)(P32)
	c0    mov $r0.3 = (_?1STRINGPACKET.41 + 0)   ## addr(_?1STRINGVAR.41)(P32)
;;								## 0
L44?3:
	c0    mov $r0.3 = 2   ## bblock 231, line 1996,  t502,  2(SI32)
	c0    mov $r0.2 = $r0.58   ## t499
	c0    ldw $r0.4 = 0x800[$r0.1]  ## restore ## t2
;;								## 1
	c0    ldw $r0.57 = 0x824[$r0.1]  ## restore ## t482
;;								## 2
	c0    ldw $r0.58 = 0x820[$r0.1]  ## restore ## t483
;;								## 3
	c0    ldw $r0.59 = 0x81c[$r0.1]  ## restore ## t484
;;								## 4
	c0    ldw $r0.60 = 0x818[$r0.1]  ## restore ## t485
;;								## 5
	c0    ldw $r0.61 = 0x814[$r0.1]  ## restore ## t486
;;								## 6
	c0    ldw $r0.62 = 0x810[$r0.1]  ## restore ## t487
;;								## 7
	c0    ldw $r0.63 = 0x80c[$r0.1]  ## restore ## t488
	      xnop 1
;;								## 9
	c0    cmpne $b0.0 = $r0.2, $r0.4   ## bblock 19, line 2002,  t779(I1),  t499,  t2
	c0    goto L23?3 ## goto
;;								## 10
.endp
.section .bss
.section .data
_?1STRINGPACKET.4:
    .data1 100
    .data1 97
    .data1 116
    .data1 97
    .data1 32
    .data1 97
    .data1 108
    .data1 105
    .data1 103
    .data1 110
    .data1 58
    .data1 32
    .data1 37
    .data1 100
    .data1 10
    .data1 0
_?1STRINGPACKET.5:
    .data1 100
    .data1 97
    .data1 116
    .data1 97
    .data1 32
    .data1 115
    .data1 107
    .data1 105
    .data1 112
    .data1 58
    .data1 32
    .data1 37
    .data1 100
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.12:
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 105
    .data1 110
    .data1 105
    .data1 116
    .data1 58
    .data1 32
    .data1 115
    .data1 116
    .data1 114
    .data1 105
    .data1 110
    .data1 103
    .data1 32
    .data1 34
    .data1 37
    .data1 115
    .data1 34
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.14:
    .data1 98
    .data1 115
    .data1 115
    .data1 32
    .data1 97
    .data1 108
    .data1 105
    .data1 103
    .data1 110
    .data1 58
    .data1 32
    .data1 37
    .data1 100
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.15:
    .data1 98
    .data1 115
    .data1 115
    .data1 32
    .data1 115
    .data1 107
    .data1 105
    .data1 112
    .data1 58
    .data1 32
    .data1 37
    .data1 100
    .data1 10
    .data1 0
.skip 2
_?1STRINGPACKET.17:
    .data1 116
    .data1 101
    .data1 120
    .data1 116
    .data1 32
    .data1 97
    .data1 108
    .data1 105
    .data1 103
    .data1 110
    .data1 58
    .data1 32
    .data1 37
    .data1 100
    .data1 10
    .data1 0
_?1STRINGPACKET.19:
    .data1 43
    .data1 43
    .data1 32
    .data1 101
    .data1 110
    .data1 100
    .data1 32
    .data1 102
    .data1 117
    .data1 110
    .data1 99
    .data1 116
    .data1 105
    .data1 111
    .data1 110
    .data1 58
    .data1 32
    .data1 37
    .data1 115
    .data1 10
    .data1 0
.skip 3
_?1STRINGPACKET.22:
    .data1 40
    .data1 101
    .data1 109
    .data1 112
    .data1 116
    .data1 121
    .data1 41
    .data1 0
_?1STRINGPACKET.28:
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 37
    .data1 45
    .data1 53
    .data1 115
    .data1 32
    .data1 37
    .data1 115
    .data1 0
_?1STRINGPACKET.37:
    .data1 32
    .data1 91
    .data1 37
    .data1 115
    .data1 93
    .data1 32
    .data1 0
.skip 1
_?1STRINGPACKET.39:
    .data1 91
    .data1 37
    .data1 115
    .data1 93
    .data1 32
    .data1 0
.skip 2
_?1STRINGPACKET.40:
    .data1 115
    .data1 121
    .data1 110
    .data1 116
    .data1 97
    .data1 120
    .data1 32
    .data1 101
    .data1 114
    .data1 114
    .data1 111
    .data1 114
    .data1 0
.skip 3
_?1STRINGPACKET.41:
    .data1 112
    .data1 97
    .data1 114
    .data1 115
    .data1 101
    .data1 114
    .data1 32
    .data1 115
    .data1 116
    .data1 97
    .data1 99
    .data1 107
    .data1 32
    .data1 111
    .data1 118
    .data1 101
    .data1 114
    .data1 102
    .data1 108
    .data1 111
    .data1 119
    .data1 0
.skip 2
_?1STRINGPACKET.3:
    .data1 47
    .data1 42
    .data1 32
    .data1 37
    .data1 115
    .data1 32
    .data1 42
    .data1 47
    .data1 10
    .data1 0
.skip 2
_?1STRINGPACKET.6:
    .data1 100
    .data1 97
    .data1 116
    .data1 97
    .data1 32
    .data1 105
    .data1 116
    .data1 101
    .data1 109
    .data1 58
    .data1 32
    .data1 37
    .data1 115
    .data1 32
    .data1 40
    .data1 37
    .data1 115
    .data1 41
    .data1 10
    .data1 0
_?1STRINGPACKET.7:
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 105
    .data1 110
    .data1 105
    .data1 116
    .data1 58
    .data1 32
    .data1 0
.skip 1
_?1STRINGPACKET.8:
    .data1 32
    .data1 40
    .data1 115
    .data1 105
    .data1 122
    .data1 101
    .data1 58
    .data1 32
    .data1 37
    .data1 100
    .data1 0
.skip 1
_?1STRINGPACKET.9:
    .data1 44
    .data1 32
    .data1 100
    .data1 117
    .data1 112
    .data1 58
    .data1 32
    .data1 37
    .data1 100
    .data1 41
    .data1 10
    .data1 0
_?1STRINGPACKET.10:
    .data1 41
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.11:
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 105
    .data1 110
    .data1 105
    .data1 116
    .data1 58
    .data1 32
    .data1 115
    .data1 107
    .data1 105
    .data1 112
    .data1 32
    .data1 37
    .data1 100
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.13:
    .data1 100
    .data1 97
    .data1 116
    .data1 97
    .data1 32
    .data1 105
    .data1 109
    .data1 112
    .data1 111
    .data1 114
    .data1 116
    .data1 58
    .data1 32
    .data1 37
    .data1 115
    .data1 10
    .data1 0
.skip 3
_?1STRINGPACKET.16:
    .data1 98
    .data1 115
    .data1 115
    .data1 32
    .data1 105
    .data1 116
    .data1 101
    .data1 109
    .data1 58
    .data1 32
    .data1 37
    .data1 115
    .data1 32
    .data1 40
    .data1 37
    .data1 115
    .data1 41
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.18:
    .data1 43
    .data1 43
    .data1 32
    .data1 98
    .data1 101
    .data1 103
    .data1 105
    .data1 110
    .data1 32
    .data1 102
    .data1 117
    .data1 110
    .data1 99
    .data1 116
    .data1 105
    .data1 111
    .data1 110
    .data1 58
    .data1 32
    .data1 37
    .data1 115
    .data1 32
    .data1 40
    .data1 37
    .data1 115
    .data1 41
    .data1 10
    .data1 0
_?1STRINGPACKET.20:
    .data1 101
    .data1 109
    .data1 112
    .data1 116
    .data1 121
    .data1 32
    .data1 102
    .data1 117
    .data1 110
    .data1 99
    .data1 116
    .data1 105
    .data1 111
    .data1 110
    .data1 58
    .data1 32
    .data1 37
    .data1 115
    .data1 32
    .data1 40
    .data1 37
    .data1 115
    .data1 41
    .data1 10
    .data1 0
.skip 3
_?1STRINGPACKET.21:
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 108
    .data1 97
    .data1 98
    .data1 101
    .data1 108
    .data1 58
    .data1 32
    .data1 37
    .data1 115
    .data1 32
    .data1 40
    .data1 37
    .data1 115
    .data1 41
    .data1 10
    .data1 0
_?1STRINGPACKET.23:
    .data1 116
    .data1 101
    .data1 120
    .data1 116
    .data1 32
    .data1 105
    .data1 109
    .data1 112
    .data1 111
    .data1 114
    .data1 116
    .data1 58
    .data1 32
    .data1 37
    .data1 115
    .data1 10
    .data1 0
.skip 3
_?1STRINGPACKET.24:
    .data1 101
    .data1 113
    .data1 117
    .data1 58
    .data1 32
    .data1 37
    .data1 115
    .data1 32
    .data1 61
    .data1 32
    .data1 0
.skip 1
_?1STRINGPACKET.25:
    .data1 10
    .data1 0
.skip 2
_?1STRINGPACKET.26:
    .data1 37
    .data1 53
    .data1 100
    .data1 93
    .data1 32
    .data1 32
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 45
    .data1 10
    .data1 0
.skip 3
_?1STRINGPACKET.27:
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 110
    .data1 111
    .data1 112
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.29:
    .data1 10
    .data1 0
.skip 2
_?1STRINGPACKET.30:
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 120
    .data1 110
    .data1 111
    .data1 112
    .data1 32
    .data1 37
    .data1 100
    .data1 10
    .data1 0
.skip 3
_?1STRINGPACKET.31:
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 32
    .data1 37
    .data1 45
    .data1 53
    .data1 115
    .data1 32
    .data1 37
    .data1 115
    .data1 44
    .data1 37
    .data1 100
    .data1 32
    .data1 0
_?1STRINGPACKET.32:
    .data1 10
    .data1 0
.skip 2
_?1STRINGPACKET.33:
    .data1 60
    .data1 61
    .data1 0
.skip 1
_?1STRINGPACKET.34:
    .data1 60
    .data1 61
    .data1 0
.skip 1
_?1STRINGPACKET.35:
    .data1 32
    .data1 0
.skip 2
_?1STRINGPACKET.36:
    .data1 32
    .data1 0
.skip 2
_?1STRINGPACKET.38:
    .data1 32
    .data1 0
.skip 2
_?1.yyparse.TAGPACKET.0:
    .data4 (_?1.yyparse.TAG.0.0)
    .data4 (_?1.yyparse.TAG.0.DEFAULT):7
    .data4 (_?1.yyparse.TAG.0.1)
    .data4 (_?1.yyparse.TAG.0.2)
    .data4 (_?1.yyparse.TAG.0.3)
    .data4 (_?1.yyparse.TAG.0.4)
    .data4 (_?1.yyparse.TAG.0.5)
    .data4 (_?1.yyparse.TAG.0.6)
    .data4 (_?1.yyparse.TAG.0.7)
    .data4 (_?1.yyparse.TAG.0.8)
    .data4 (_?1.yyparse.TAG.0.DEFAULT):2
    .data4 (_?1.yyparse.TAG.0.9)
    .data4 (_?1.yyparse.TAG.0.10)
    .data4 (_?1.yyparse.TAG.0.11)
    .data4 (_?1.yyparse.TAG.0.12)
    .data4 (_?1.yyparse.TAG.0.13)
    .data4 (_?1.yyparse.TAG.0.14)
    .data4 (_?1.yyparse.TAG.0.15)
    .data4 (_?1.yyparse.TAG.0.16)
    .data4 (_?1.yyparse.TAG.0.17)
    .data4 (_?1.yyparse.TAG.0.18)
    .data4 (_?1.yyparse.TAG.0.19)
    .data4 (_?1.yyparse.TAG.0.20)
    .data4 (_?1.yyparse.TAG.0.21)
    .data4 (_?1.yyparse.TAG.0.DEFAULT):8
    .data4 (_?1.yyparse.TAG.0.22)
    .data4 (_?1.yyparse.TAG.0.23)
    .data4 (_?1.yyparse.TAG.0.24)
    .data4 (_?1.yyparse.TAG.0.DEFAULT):11
    .data4 (_?1.yyparse.TAG.0.25)
    .data4 (_?1.yyparse.TAG.0.26)
    .data4 (_?1.yyparse.TAG.0.27)
    .data4 (_?1.yyparse.TAG.0.28)
    .data4 (_?1.yyparse.TAG.0.DEFAULT)
    .data4 (_?1.yyparse.TAG.0.29)
    .data4 (_?1.yyparse.TAG.0.DEFAULT):10
    .data4 (_?1.yyparse.TAG.0.30)
    .data4 (_?1.yyparse.TAG.0.31)
    .data4 (_?1.yyparse.TAG.0.32)
    .data4 (_?1.yyparse.TAG.0.33)
    .data4 (_?1.yyparse.TAG.0.34)
    .data4 (_?1.yyparse.TAG.0.35)
    .data4 (_?1.yyparse.TAG.0.36)
    .data4 (_?1.yyparse.TAG.0.37)
    .data4 (_?1.yyparse.TAG.0.38)
    .data4 (_?1.yyparse.TAG.0.39)
    .data4 (_?1.yyparse.TAG.0.40)
    .data4 (_?1.yyparse.TAG.0.41)
    .data4 (_?1.yyparse.TAG.0.42)
    .data4 (_?1.yyparse.TAG.0.43)
    .data4 (_?1.yyparse.TAG.0.44)
    .data4 (_?1.yyparse.TAG.0.45)
    .data4 (_?1.yyparse.TAG.0.46)
    .data4 (_?1.yyparse.TAG.0.DEFAULT):4
    .data4 (_?1.yyparse.TAG.0.47)
    .data4 (_?1.yyparse.TAG.0.DEFAULT):2
    .data4 (_?1.yyparse.TAG.0.48)
    .data4 (_?1.yyparse.TAG.0.49)
    .data4 (_?1.yyparse.TAG.0.50)
    .data4 (_?1.yyparse.TAG.0.51)
    .data4 (_?1.yyparse.TAG.0.52)
    .data4 (_?1.yyparse.TAG.0.DEFAULT):2
    .data4 (_?1.yyparse.TAG.0.53)
    .data4 (_?1.yyparse.TAG.0.54)
    .data4 (_?1.yyparse.TAG.0.DEFAULT)
    .data4 (_?1.yyparse.TAG.0.55)
    .data4 (_?1.yyparse.TAG.0.DEFAULT):6
    .data4 (_?1.yyparse.TAG.0.56)
    .data4 (_?1.yyparse.TAG.0.57)
    .data4 (_?1.yyparse.TAG.0.58)
    .data4 (_?1.yyparse.TAG.0.59)
    .data4 (_?1.yyparse.TAG.0.60)
    .data4 (_?1.yyparse.TAG.0.DEFAULT)
    .data4 (_?1.yyparse.TAG.0.61)
    .data4 (_?1.yyparse.TAG.0.DEFAULT)
    .data4 (_?1.yyparse.TAG.0.62)
    .data4 (_?1.yyparse.TAG.0.DEFAULT):3
    .data4 (_?1.yyparse.TAG.0.63)
    .data4 (_?1.yyparse.TAG.0.64)
    .data4 (_?1.yyparse.TAG.0.65)
    .data4 (_?1.yyparse.TAG.0.66)
    .data4 (_?1.yyparse.TAG.0.67)
    .data4 (_?1.yyparse.TAG.0.68)
    .data4 (_?1.yyparse.TAG.0.69)
    .data4 (_?1.yyparse.TAG.0.70)
    .data4 (_?1.yyparse.TAG.0.71)
    .data4 (_?1.yyparse.TAG.0.72)
    .data4 (_?1.yyparse.TAG.0.73)
    .data4 (_?1.yyparse.TAG.0.74)
    .data4 (_?1.yyparse.TAG.0.75)
    .data4 (_?1.yyparse.TAG.0.76)
    .data4 (_?1.yyparse.TAG.0.77)
.equ ?2.2?2scratch.0, 0x0
.equ _?1PACKET.19, 0x10
.equ _?1PACKET.17, 0x650
.equ ?2.2?2ras_p, 0x7e0
.equ ?2.2?2spill_p, 0x7e4
.section .data
.section .text
.equ ?2.2?2auto_size, 0x840
 ## End yyparse
.equ _?1TEMPLATEPACKET.22, 0x0
 ## Begin print_exp
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-32, arg($r0.3:u32)
print_exp:
.trace 1
	c0    add $r0.1 = $r0.1, (-0x20)
	c0    ldw $r0.2 = 0[$r0.3]   ## bblock 0, line 129, t48, t2
;;								## 0
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t34
;;								## 1
	c0    ldw $r0.4 = 4[$r0.3]   ## bblock 0, line 130, t47, t2
;;								## 2
	c0    stw 0x14[$r0.1] = $r0.2  ## spill ## t48
	      xnop 1
;;								## 4
	c0    andl $b0.0 = $r0.2, $r0.4   ## bblock 0, line 132,  t49(I1),  t48,  t47
	c0    mov $r0.3 = (_?1STRINGPACKET.42 + 0)   ## addr(_?1STRINGVAR.42)(P32)
	c0    stw 0x18[$r0.1] = $r0.4  ## spill ## t47
	      xnop 1
;;								## 6
	c0    brf $b0.0, L45?3   ## bblock 0, line 132,  t49(I1)
;;								## 7
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 11, line 133,  raddr(printf)(P32),  addr(_?1STRINGVAR.42)(P32)
;;								## 8
L45?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.43 + 0)   ## addr(_?1STRINGVAR.43)(P32)
	c0    ldw $r0.4 = 0x18[$r0.1]  ## restore ## t47
	      xnop 2
;;								## 11
	c0    cmpne $b0.0 = $r0.4, $r0.0   ## bblock 1, line 134,  t50(I1),  t47,  0x0(P32)
	      xnop 1
;;								## 13
	c0    brf $b0.0, L46?3   ## bblock 1, line 134,  t50(I1)
;;								## 14
.call printf, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 6, line 135,  raddr(printf)(P32),  addr(_?1STRINGVAR.43)(P32),  t47
;;								## 15
	c0    mov $r0.3 = (_?1STRINGPACKET.44 + 0)   ## addr(_?1STRINGVAR.44)(P32)
	c0    ldw $r0.4 = 0x14[$r0.1]  ## restore ## t48
	      xnop 2
;;								## 18
	c0    cmpgt $b0.0 = $r0.4, $r0.0   ## bblock 7, line 136,  t52(I1),  t48,  0(SI32)
	      xnop 1
;;								## 20
	c0    brf $b0.0, L47?3   ## bblock 7, line 136,  t52(I1)
;;								## 21
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 10, line 137,  raddr(printf)(P32),  addr(_?1STRINGVAR.44)(P32),  t48
;;								## 22
L47?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.45 + 0)   ## addr(_?1STRINGVAR.45)(P32)
	c0    ldw $r0.2 = 0x14[$r0.1]  ## restore ## t48
	      xnop 2
;;								## 25
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 8, line 138,  t53(I1),  t48,  0(SI32)
	c0    sub $r0.4 = $r0.0, $r0.2   ## [spec] bblock 9, line 139,  t24,  0(I32),  t48
	      xnop 1
;;								## 27
	c0    brf $b0.0, L48?3   ## bblock 8, line 138,  t53(I1)
;;								## 28
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 9, line 139,  raddr(printf)(P32),  addr(_?1STRINGVAR.45)(P32),  t24
;;								## 29
;;								## 30
.trace 2
L48?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.47 + 0)   ## addr(_?1STRINGVAR.47)(P32)
	c0    ldw $r0.4 = 0x18[$r0.1]  ## restore ## t47
;;								## 0
	c0    ldw $r0.2 = 0x14[$r0.1]  ## restore ## t48
	      xnop 2
;;								## 3
	c0    andl $b0.0 = $r0.2, $r0.4   ## bblock 3, line 143,  t51(I1),  t48,  t47
	      xnop 1
;;								## 5
	c0    brf $b0.0, L49?3   ## bblock 3, line 143,  t51(I1)
;;								## 6
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 5, line 144,  raddr(printf)(P32),  addr(_?1STRINGVAR.47)(P32)
;;								## 7
L49?3:
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t34
	      xnop 3
;;								## 11
.return ret()
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 4, line 145,  t35,  ?2.3?2auto_size(I32),  t34
;;								## 12
.trace 3
L46?3:
	c0    ldw $r0.4 = 0x14[$r0.1]  ## restore ## t48
	c0    mov $r0.3 = (_?1STRINGPACKET.46 + 0)   ## addr(_?1STRINGVAR.46)(P32)
	      xnop 1
;;								## 1
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 2, line 142,  raddr(printf)(P32),  addr(_?1STRINGVAR.46)(P32),  t48
;;								## 2
	c0    goto L48?3 ## goto
;;								## 3
.endp
.section .bss
.section .data
_?1STRINGPACKET.44:
    .data1 32
    .data1 43
    .data1 32
    .data1 37
    .data1 100
    .data1 0
.skip 2
_?1STRINGPACKET.45:
    .data1 32
    .data1 45
    .data1 32
    .data1 37
    .data1 100
    .data1 0
.skip 2
_?1STRINGPACKET.42:
    .data1 40
    .data1 0
.skip 2
_?1STRINGPACKET.43:
    .data1 37
    .data1 115
    .data1 0
.skip 1
_?1STRINGPACKET.46:
    .data1 37
    .data1 100
    .data1 0
.skip 1
_?1STRINGPACKET.47:
    .data1 41
    .data1 0
.equ ?2.3?2scratch.0, 0x0
.equ ?2.3?2ras_p, 0x10
.equ ?2.3?2spill_p, 0x14
.section .data
.section .text
.equ ?2.3?2auto_size, 0x20
 ## End print_exp
.equ _?1TEMPLATEPACKET.18, 0x0
 ## Begin build_binexp
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-64, arg($r0.3:u32,$r0.4:u32,$r0.5:u32)
build_binexp:
.trace 1
	c0    add $r0.1 = $r0.1, (-0x40)
	c0    sxtb $r0.6 = $r0.3   ## bblock 0, line 147,  t59(SI8),  t58
	c0    ldw $r0.2 = 0[$r0.4]   ## bblock 0, line 150, t64, t60
;;								## 0
	c0    mov $r0.3 = 8   ## 8(I32)
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t44
;;								## 1
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t61
;;								## 2
	c0    stw 0x18[$r0.1] = $r0.4  ## spill ## t60
;;								## 3
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t64
;;								## 4
	c0    stw 0x1c[$r0.1] = $r0.6  ## spill ## t59(SI8)
;;								## 5
	c0    ldw $r0.2 = 0[$r0.5]   ## bblock 0, line 151, t63, t61
	      xnop 2
;;								## 8
.call malloc, caller, arg($r0.3:u32), ret($r0.3:u32)
	c0    call $l0.0 = malloc   ## bblock 0, line 152,  raddr(malloc)(P32),  8(I32)
	c0    stw 0x24[$r0.1] = $r0.2  ## spill ## t63
;;								## 9
	c0    ldw $r0.6 = 0x1c[$r0.1]  ## restore ## t59(SI8)
;;								## 10
	c0    ldw $r0.2 = 0x20[$r0.1]  ## restore ## t64
;;								## 11
	c0    ldw $r0.4 = 0x24[$r0.1]  ## restore ## t63
;;								## 12
	c0    cmpeq $b0.0 = $r0.6, 43   ## bblock 1, line 160,  t74(I1),  t59(SI8),  43(SI32)
	c0    ldw $r0.5 = 0x18[$r0.1]  ## restore ## t60
;;								## 13
	c0    ldw $r0.7 = 0x14[$r0.1]  ## restore ## t61
;;								## 14
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t44
	c0    brf $b0.0, L50?3   ## bblock 1, line 160,  t74(I1)
;;								## 15
	c0    add $r0.2 = $r0.2, $r0.4   ## bblock 13, line 155,  t65,  t64,  t63
	c0    ldw $r0.6 = 4[$r0.5]   ## bblock 5, line 161, t20, t60
;;								## 16
	c0    ldw.d $r0.4 = 4[$r0.7]   ## [spec] bblock 5, line 161, t22, t61
;;								## 17
	c0    ldw.d $r0.8 = 4[$r0.5]   ## [spec] bblock 6, line 165, t70, t60
;;								## 18
L51?3:
	c0    ldw.d $r0.9 = 4[$r0.7]   ## [spec] bblock 6, line 165, t71, t61
;;								## 19
	c0    andl $b0.0 = $r0.6, $r0.4   ## bblock 5, line 161,  t76(I1),  t20,  t22
;;								## 20
	c0    cmpne $b0.1 = $r0.8, $r0.0   ## [spec] bblock 6, line 165,  t77(I1),  t70,  0(I32)
;;								## 21
	c0    slct $r0.8 = $b0.1, $r0.8, $r0.9   ## [spec] bblock 6, line 165,  t33,  t77(I1),  t70,  t71
	c0    br $b0.0, L52?3   ## bblock 5, line 161,  t76(I1)
;;								## 22
L53?3:
	c0    stw 4[$r0.3] = $r0.8   ## bblock 6, line 165, t4, t33
;;								## 23
.return ret($r0.3:u32)
	c0    stw 0[$r0.3] = $r0.2   ## bblock 6, line 166, t4, t65
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 6, line 167,  t45,  ?2.4?2auto_size(I32),  t44
;;								## 24
.trace 4
L52?3:
	c0    stw 0x2c[$r0.1] = $r0.2  ## spill ## t65
	c0    mov $r0.6 = $r0.4   ## t22
	c0    mov $r0.5 = $r0.6   ## t20
;;								## 0
	c0    stw 0x28[$r0.1] = $r0.3  ## spill ## t4
	c0    mov $r0.4 = (_?1STRINGPACKET.49 + 0)   ## addr(_?1STRINGVAR.49)(P32)
;;								## 1
	c0    ldw $r0.9 = ((_impure_ptr + 0) + 0)[$r0.0]   ## bblock 11, line 162, t24, 0(I32)
;;								## 2
	c0    ldw $r0.7 = ((yylineno + 0) + 0)[$r0.0]   ## bblock 11, line 163, t32, 0(I32)
	      xnop 1
;;								## 4
	c0    ldw $r0.3 = 12[$r0.9]   ## bblock 11, line 162, t25, t24
	      xnop 1
;;								## 6
.call fprintf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32,$r0.6:u32,$r0.7:s32), ret($r0.3:s32)
	c0    call $l0.0 = fprintf   ## bblock 11, line 163,  raddr(fprintf)(P32),  t25,  addr(_?1STRINGVAR.49)(P32),  t20,  t22,  t32
;;								## 7
	c0    ldw $r0.4 = 0x18[$r0.1]  ## restore ## t60
;;								## 8
	c0    ldw $r0.5 = 0x14[$r0.1]  ## restore ## t61
;;								## 9
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t44
;;								## 10
	c0    ldw $r0.4 = 4[$r0.4]   ## bblock 6, line 165, t70, t60
;;								## 11
	c0    ldw.d $r0.9 = 4[$r0.5]   ## [spec] bblock 6, line 165, t71, t61
;;								## 12
	c0    ldw $r0.2 = 0x2c[$r0.1]  ## restore ## t65
;;								## 13
	c0    cmpne $b0.0 = $r0.4, $r0.0   ## bblock 6, line 165,  t77(I1),  t70,  0(I32)
	c0    ldw $r0.3 = 0x28[$r0.1]  ## restore ## t4
;;								## 14
	c0    slct $r0.8 = $b0.0, $r0.4, $r0.9   ## bblock 6, line 165,  t33,  t77(I1),  t70,  t71
;;								## 15
	c0    goto L53?3 ## goto
;;								## 16
.trace 2
L50?3:
	c0    ldw $r0.8 = 0x1c[$r0.1]  ## restore ## t59(SI8)
;;								## 0
	c0    ldw.d $r0.6 = 4[$r0.5]   ## [spec] bblock 5, line 161, t20, t60
	      xnop 1
;;								## 2
	c0    cmpeq $b0.0 = $r0.8, 45   ## bblock 2, line 160,  t75(I1),  t59(SI8),  45(SI32)
	      xnop 1
;;								## 4
	c0    brf $b0.0, L54?3   ## bblock 2, line 160,  t75(I1)
;;								## 5
	c0    sub $r0.2 = $r0.2, $r0.4   ## bblock 12, line 154,  t65,  t64,  t63
	c0    ldw.d $r0.4 = 4[$r0.7]   ## [spec] bblock 5, line 161, t22, t61
;;								## 6
	c0    ldw.d $r0.8 = 4[$r0.5]   ## [spec] bblock 6, line 165, t70, t60
	c0    goto L51?3 ## goto
;;								## 7
.trace 3
L54?3:
	c0    stw 0x28[$r0.1] = $r0.3  ## spill ## t4
	c0    mov $r0.4 = (_?1STRINGPACKET.48 + 0)   ## addr(_?1STRINGVAR.48)(P32)
;;								## 0
	c0    ldw $r0.8 = ((_impure_ptr + 0) + 0)[$r0.0]   ## bblock 3, line 157, t13, 0(I32)
;;								## 1
	c0    ldw $r0.6 = ((yylineno + 0) + 0)[$r0.0]   ## bblock 3, line 158, t18, 0(I32)
;;								## 2
	c0    ldw $r0.5 = 0x1c[$r0.1]  ## restore ## t59(SI8)
;;								## 3
	c0    ldw $r0.3 = 12[$r0.8]   ## bblock 3, line 157, t14, t13
	      xnop 1
;;								## 5
.call fprintf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:s32,$r0.6:s32), ret($r0.3:s32)
	c0    call $l0.0 = fprintf   ## bblock 3, line 158,  raddr(fprintf)(P32),  t14,  addr(_?1STRINGVAR.48)(P32),  t59(SI8),  t18
;;								## 6
.call exit, caller, arg($r0.3:s32), ret()
	c0    call $l0.0 = exit   ## bblock 4, line 159,  raddr(exit)(P32),  3(SI32)
	c0    mov $r0.3 = 3   ## 3(SI32)
;;								## 7
	c0    ldw $r0.5 = 0x18[$r0.1]  ## restore ## t60
;;								## 8
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t44
;;								## 9
	c0    ldw $r0.7 = 0x14[$r0.1]  ## restore ## t61
;;								## 10
	c0    ldw $r0.6 = 4[$r0.5]   ## bblock 5, line 161, t20, t60
;;								## 11
	c0    ldw $r0.3 = 0x28[$r0.1]  ## restore ## t4
;;								## 12
	c0    ldw $r0.2 = 0x2c[$r0.1]  ## restore ## t65
;;								## 13
	c0    ldw.d $r0.4 = 4[$r0.7]   ## [spec] bblock 5, line 161, t22, t61
;;								## 14
	c0    ldw.d $r0.8 = 4[$r0.5]   ## [spec] bblock 6, line 165, t70, t60
	c0    goto L51?3 ## goto
;;								## 15
.endp
.section .bss
.section .data
.skip 2
_?1STRINGPACKET.48:
    .data1 105
    .data1 108
    .data1 108
    .data1 101
    .data1 103
    .data1 97
    .data1 108
    .data1 32
    .data1 98
    .data1 105
    .data1 110
    .data1 97
    .data1 114
    .data1 121
    .data1 32
    .data1 111
    .data1 112
    .data1 32
    .data1 40
    .data1 96
    .data1 37
    .data1 99
    .data1 39
    .data1 41
    .data1 32
    .data1 97
    .data1 116
    .data1 32
    .data1 108
    .data1 105
    .data1 110
    .data1 101
    .data1 32
    .data1 37
    .data1 100
    .data1 10
    .data1 0
.skip 3
_?1STRINGPACKET.49:
    .data1 105
    .data1 108
    .data1 108
    .data1 101
    .data1 103
    .data1 97
    .data1 108
    .data1 32
    .data1 98
    .data1 105
    .data1 110
    .data1 97
    .data1 114
    .data1 121
    .data1 32
    .data1 101
    .data1 120
    .data1 112
    .data1 32
    .data1 40
    .data1 37
    .data1 115
    .data1 44
    .data1 32
    .data1 37
    .data1 115
    .data1 41
    .data1 32
    .data1 97
    .data1 116
    .data1 32
    .data1 108
    .data1 105
    .data1 110
    .data1 101
    .data1 32
    .data1 37
    .data1 100
    .data1 10
    .data1 0
.equ ?2.4?2scratch.0, 0x0
.equ ?2.4?2ras_p, 0x10
.equ ?2.4?2spill_p, 0x14
.section .data
.section .text
.equ ?2.4?2auto_size, 0x40
 ## End build_binexp
 ## Begin build_unexp
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-64, arg($r0.3:u32,$r0.4:u32)
build_unexp:
.trace 1
	c0    add $r0.1 = $r0.1, (-0x40)
	c0    sxtb $r0.2 = $r0.3   ## bblock 0, line 170,  t44(SI8),  t43
;;								## 0
	c0    mov $r0.3 = 8   ## 8(I32)
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t30
;;								## 1
	c0    stw 0x14[$r0.1] = $r0.4  ## spill ## t45
;;								## 2
.call malloc, caller, arg($r0.3:u32), ret($r0.3:u32)
	c0    call $l0.0 = malloc   ## bblock 0, line 173,  raddr(malloc)(P32),  8(I32)
	c0    stw 0x18[$r0.1] = $r0.2  ## spill ## t44(SI8)
;;								## 3
	c0    mov $r0.4 = (_?1STRINGPACKET.51 + 0)   ## addr(_?1STRINGVAR.51)(P32)
	c0    stw 0x1c[$r0.1] = $r0.3  ## spill ## t0
;;								## 4
	c0    ldw $r0.2 = 0x14[$r0.1]  ## restore ## t45
;;								## 5
	c0    ldw $r0.7 = 0x18[$r0.1]  ## restore ## t44(SI8)
;;								## 6
	c0    ldw.d $r0.8 = ((_impure_ptr + 0) + 0)[$r0.0]   ## [spec] bblock 8, line 185, t20, 0(I32)
;;								## 7
	c0    ldw $r0.9 = 0[$r0.2]   ## bblock 1, line 174, t46, t45
;;								## 8
	c0    cmpeq $b0.0 = $r0.7, 43   ## bblock 1, line 183,  t49(I1),  t44(SI8),  43(SI32)
	c0    ldw.d $r0.5 = 4[$r0.2]   ## [spec] bblock 6, line 184, t18, t45
;;								## 9
	c0    ldw.d $r0.3 = 12[$r0.8]   ## [spec] bblock 8, line 185, t21, t20
;;								## 10
	c0    ldw.d $r0.6 = ((yylineno + 0) + 0)[$r0.0]   ## [spec] bblock 8, line 186, t26, 0(I32)
	c0    brf $b0.0, L55?3   ## bblock 1, line 183,  t49(I1)
;;								## 11
	c0    mov $r0.2 = $r0.9   ## bblock 11, line 174,  t48,  t46
	c0    cmpne $b0.0 = $r0.5, $r0.0   ## bblock 6, line 184,  t52(I1),  t18,  0x0(P32)
;;								## 12
L56?3:
	c0    stw 0x20[$r0.1] = $r0.2  ## spill ## t48
;;								## 13
	c0    brf $b0.0, L57?3   ## bblock 6, line 184,  t52(I1)
;;								## 14
.call fprintf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32,$r0.6:s32), ret($r0.3:s32)
	c0    call $l0.0 = fprintf   ## bblock 8, line 186,  raddr(fprintf)(P32),  t21,  addr(_?1STRINGVAR.51)(P32),  t18,  t26
;;								## 15
L57?3:
	c0    ldw $r0.3 = 0x1c[$r0.1]  ## restore ## t0
;;								## 16
	c0    ldw $r0.2 = 0x20[$r0.1]  ## restore ## t48
;;								## 17
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t30
	      xnop 1
;;								## 19
	c0    stw 0[$r0.3] = $r0.2   ## bblock 7, line 188, t0, t48
	      xnop 1
;;								## 21
.return ret($r0.3:u32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 7, line 189,  t31,  ?2.5?2auto_size(I32),  t30
;;								## 22
.trace 2
L55?3:
	c0    mov $r0.4 = (_?1STRINGPACKET.51 + 0)   ## addr(_?1STRINGVAR.51)(P32)
	c0    ldw $r0.7 = 0x18[$r0.1]  ## restore ## t44(SI8)
	      xnop 2
;;								## 2
	c0    cmpeq $b0.0 = $r0.7, 45   ## bblock 2, line 183,  t50(I1),  t44(SI8),  45(SI32)
	      xnop 1
;;								## 4
	c0    brf $b0.0, L58?3   ## bblock 2, line 183,  t50(I1)
;;								## 5
	c0    sub $r0.2 = $r0.0, $r0.9   ## bblock 10, line 176,  t48,  0(I32),  t46
	c0    ldw.d $r0.6 = ((yylineno + 0) + 0)[$r0.0]   ## [spec] bblock 8, line 186, t26, 0(I32)
;;								## 6
	c0    cmpne $b0.0 = $r0.5, $r0.0   ## bblock 6, line 184,  t52(I1),  t18,  0x0(P32)
	c0    goto L56?3 ## goto
;;								## 7
.trace 4
L58?3:
	c0    mov $r0.4 = (_?1STRINGPACKET.51 + 0)   ## addr(_?1STRINGVAR.51)(P32)
	c0    ldw $r0.6 = 0x18[$r0.1]  ## restore ## t44(SI8)
	      xnop 2
;;								## 2
	c0    cmpeq $b0.0 = $r0.6, 126   ## bblock 3, line 183,  t51(I1),  t44(SI8),  126(SI32)
	      xnop 1
;;								## 4
	c0    brf $b0.0, L59?3   ## bblock 3, line 183,  t51(I1)
;;								## 5
	c0    orc $r0.2 = $r0.9, $r0.0   ## bblock 9, line 178,  t48,  t46,  0(I32)
	c0    ldw.d $r0.6 = ((yylineno + 0) + 0)[$r0.0]   ## [spec] bblock 8, line 186, t26, 0(I32)
;;								## 6
	c0    cmpne $b0.0 = $r0.5, $r0.0   ## bblock 6, line 184,  t52(I1),  t18,  0x0(P32)
	c0    goto L56?3 ## goto
;;								## 7
.trace 5
L59?3:
	c0    ldw $r0.7 = ((_impure_ptr + 0) + 0)[$r0.0]   ## bblock 4, line 180, t11, 0(I32)
	c0    mov $r0.4 = (_?1STRINGPACKET.50 + 0)   ## addr(_?1STRINGVAR.50)(P32)
;;								## 0
	c0    ldw $r0.6 = ((yylineno + 0) + 0)[$r0.0]   ## bblock 4, line 181, t16, 0(I32)
;;								## 1
	c0    ldw $r0.5 = 0x18[$r0.1]  ## restore ## t44(SI8)
;;								## 2
	c0    ldw $r0.3 = 12[$r0.7]   ## bblock 4, line 180, t12, t11
	      xnop 1
;;								## 4
.call fprintf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:s32,$r0.6:s32), ret($r0.3:s32)
	c0    call $l0.0 = fprintf   ## bblock 4, line 181,  raddr(fprintf)(P32),  t12,  addr(_?1STRINGVAR.50)(P32),  t44(SI8),  t16
;;								## 5
.call exit, caller, arg($r0.3:s32), ret()
	c0    call $l0.0 = exit   ## bblock 5, line 182,  raddr(exit)(P32),  3(SI32)
	c0    mov $r0.3 = 3   ## 3(SI32)
;;								## 6
	c0    ldw.d $r0.8 = ((_impure_ptr + 0) + 0)[$r0.0]   ## [spec] bblock 8, line 185, t20, 0(I32)
	c0    mov $r0.4 = (_?1STRINGPACKET.51 + 0)   ## addr(_?1STRINGVAR.51)(P32)
;;								## 7
	c0    ldw $r0.6 = 0x14[$r0.1]  ## restore ## t45
	      xnop 1
;;								## 9
	c0    ldw.d $r0.3 = 12[$r0.8]   ## [spec] bblock 8, line 185, t21, t20
;;								## 10
	c0    ldw $r0.5 = 4[$r0.6]   ## bblock 6, line 184, t18, t45
;;								## 11
	c0    ldw $r0.2 = 0x20[$r0.1]  ## restore ## t48
;;								## 12
	c0    ldw.d $r0.6 = ((yylineno + 0) + 0)[$r0.0]   ## [spec] bblock 8, line 186, t26, 0(I32)
;;								## 13
	c0    cmpne $b0.0 = $r0.5, $r0.0   ## bblock 6, line 184,  t52(I1),  t18,  0x0(P32)
	c0    goto L56?3 ## goto
;;								## 14
.endp
.section .bss
.section .data
_?1STRINGPACKET.50:
    .data1 105
    .data1 108
    .data1 108
    .data1 101
    .data1 103
    .data1 97
    .data1 108
    .data1 32
    .data1 117
    .data1 110
    .data1 97
    .data1 114
    .data1 121
    .data1 32
    .data1 111
    .data1 112
    .data1 32
    .data1 40
    .data1 96
    .data1 37
    .data1 99
    .data1 39
    .data1 41
    .data1 32
    .data1 97
    .data1 116
    .data1 32
    .data1 108
    .data1 105
    .data1 110
    .data1 101
    .data1 32
    .data1 37
    .data1 100
    .data1 10
    .data1 0
_?1STRINGPACKET.51:
    .data1 105
    .data1 108
    .data1 108
    .data1 101
    .data1 103
    .data1 97
    .data1 108
    .data1 32
    .data1 117
    .data1 110
    .data1 97
    .data1 114
    .data1 121
    .data1 32
    .data1 101
    .data1 120
    .data1 112
    .data1 32
    .data1 40
    .data1 37
    .data1 115
    .data1 41
    .data1 32
    .data1 97
    .data1 116
    .data1 32
    .data1 108
    .data1 105
    .data1 110
    .data1 101
    .data1 32
    .data1 37
    .data1 100
    .data1 10
    .data1 0
.equ ?2.5?2scratch.0, 0x0
.equ ?2.5?2ras_p, 0x10
.equ ?2.5?2spill_p, 0x14
.section .data
.section .text
.equ ?2.5?2auto_size, 0x40
 ## End build_unexp
 ## Begin build_strexp
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-32, arg($r0.3:u32)
build_strexp:
.trace 1
	c0    add $r0.1 = $r0.1, (-0x20)
;;								## 0
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t5
;;								## 1
	c0    stw 0x14[$r0.1] = $r0.3  ## spill ## t17
;;								## 2
.call malloc, caller, arg($r0.3:u32), ret($r0.3:u32)
	c0    call $l0.0 = malloc   ## bblock 0, line 194,  raddr(malloc)(P32),  8(I32)
	c0    mov $r0.3 = 8   ## 8(I32)
;;								## 3
	c0    ldw $r0.2 = 0x14[$r0.1]  ## restore ## t17
;;								## 4
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t5
;;								## 5
	c0    stw 0[$r0.3] = $r0.0   ## bblock 1, line 196, t0, 0(SI32)
;;								## 6
	c0    stw 4[$r0.3] = $r0.2   ## bblock 1, line 195, t0, t17
	      xnop 1
;;								## 8
.return ret($r0.3:u32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 1, line 197,  t6,  ?2.6?2auto_size(I32),  t5
;;								## 9
.endp
.section .bss
.section .data
.equ ?2.6?2scratch.0, 0x0
.equ ?2.6?2ras_p, 0x10
.equ ?2.6?2spill_p, 0x14
.section .data
.section .text
.equ ?2.6?2auto_size, 0x20
 ## End build_strexp
 ## Begin build_numexp
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-32, arg($r0.3:s32)
build_numexp:
.trace 1
	c0    add $r0.1 = $r0.1, (-0x20)
;;								## 0
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t5
;;								## 1
	c0    stw 0x14[$r0.1] = $r0.3  ## spill ## t17
;;								## 2
.call malloc, caller, arg($r0.3:u32), ret($r0.3:u32)
	c0    call $l0.0 = malloc   ## bblock 0, line 202,  raddr(malloc)(P32),  8(I32)
	c0    mov $r0.3 = 8   ## 8(I32)
;;								## 3
	c0    ldw $r0.2 = 0x14[$r0.1]  ## restore ## t17
;;								## 4
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t5
;;								## 5
	c0    stw 4[$r0.3] = $r0.0   ## bblock 1, line 203, t0, 0x0(P32)
;;								## 6
	c0    stw 0[$r0.3] = $r0.2   ## bblock 1, line 204, t0, t17
	      xnop 1
;;								## 8
.return ret($r0.3:u32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 1, line 205,  t6,  ?2.7?2auto_size(I32),  t5
;;								## 9
.endp
.section .bss
.section .data
.equ ?2.7?2scratch.0, 0x0
.equ ?2.7?2ras_p, 0x10
.equ ?2.7?2spill_p, 0x14
.section .data
.section .text
.equ ?2.7?2auto_size, 0x20
 ## End build_numexp
 ## Begin yyerror
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-32, arg($r0.3:u32)
yyerror::
.trace 1
	c0    add $r0.1 = $r0.1, (-0x20)
	c0    ldw $r0.2 = ((_impure_ptr + 0) + 0)[$r0.0]   ## bblock 0, line 210, t1, 0(I32)
;;								## 0
	c0    mov $r0.5 = $r0.3   ## t5
	c0    mov $r0.4 = (_?1STRINGPACKET.52 + 0)   ## addr(_?1STRINGVAR.52)(P32)
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t7
;;								## 1
	c0    ldw $r0.6 = ((yylineno + 0) + 0)[$r0.0]   ## bblock 0, line 210, t6, 0(I32)
;;								## 2
	c0    ldw $r0.3 = 12[$r0.2]   ## bblock 0, line 210, t2, t1
	      xnop 1
;;								## 4
.call fprintf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32,$r0.6:s32), ret($r0.3:s32)
	c0    call $l0.0 = fprintf   ## bblock 0, line 210,  raddr(fprintf)(P32),  t2,  addr(_?1STRINGVAR.52)(P32),  t5,  t6
;;								## 5
.call exit, caller, arg($r0.3:s32), ret()
	c0    call $l0.0 = exit   ## bblock 1, line 211,  raddr(exit)(P32),  100(SI32)
	c0    mov $r0.3 = 100   ## 100(SI32)
;;								## 6
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t7
	      xnop 3
;;								## 10
.return ret()
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 2, line 212,  t8,  ?2.8?2auto_size(I32),  t7
;;								## 11
.endp
.section .bss
.section .data
.skip 1
_?1STRINGPACKET.52:
    .data1 91
    .data1 70
    .data1 65
    .data1 84
    .data1 65
    .data1 76
    .data1 93
    .data1 32
    .data1 37
    .data1 115
    .data1 32
    .data1 97
    .data1 116
    .data1 32
    .data1 108
    .data1 105
    .data1 110
    .data1 101
    .data1 32
    .data1 37
    .data1 100
    .data1 10
    .data1 0
.equ ?2.8?2scratch.0, 0x0
.equ ?2.8?2ras_p, 0x10
.section .data
.section .text
.equ ?2.8?2auto_size, 0x20
 ## End yyerror
 ## Begin yywarn
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-32, arg($r0.3:u32)
yywarn::
.trace 1
	c0    add $r0.1 = $r0.1, (-0x20)
	c0    ldw $r0.2 = ((_impure_ptr + 0) + 0)[$r0.0]   ## bblock 0, line 216, t1, 0(I32)
;;								## 0
	c0    mov $r0.5 = $r0.3   ## t5
	c0    mov $r0.4 = (_?1STRINGPACKET.53 + 0)   ## addr(_?1STRINGVAR.53)(P32)
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t7
;;								## 1
	c0    ldw $r0.6 = ((yylineno + 0) + 0)[$r0.0]   ## bblock 0, line 216, t6, 0(I32)
;;								## 2
	c0    ldw $r0.3 = 12[$r0.2]   ## bblock 0, line 216, t2, t1
	      xnop 1
;;								## 4
.call fprintf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32,$r0.6:s32), ret($r0.3:s32)
	c0    call $l0.0 = fprintf   ## bblock 0, line 216,  raddr(fprintf)(P32),  t2,  addr(_?1STRINGVAR.53)(P32),  t5,  t6
;;								## 5
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t7
	      xnop 3
;;								## 9
.return ret()
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 1, line 217,  t8,  ?2.9?2auto_size(I32),  t7
;;								## 10
.endp
.section .bss
.section .data
.skip 1
_?1STRINGPACKET.53:
    .data1 91
    .data1 87
    .data1 65
    .data1 82
    .data1 78
    .data1 93
    .data1 32
    .data1 37
    .data1 115
    .data1 32
    .data1 97
    .data1 116
    .data1 32
    .data1 108
    .data1 105
    .data1 110
    .data1 101
    .data1 32
    .data1 37
    .data1 100
    .data1 10
    .data1 0
.equ ?2.9?2scratch.0, 0x0
.equ ?2.9?2ras_p, 0x10
.section .data
.section .text
.equ ?2.9?2auto_size, 0x20
 ## End yywarn
 ## Begin yywrap
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg()
yywrap::
.trace 1
	      ## auto_size == 0
	c0    mov $r0.3 = 1   ## 1(SI32)
;;								## 0
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 222,  t1,  ?2.10?2auto_size(I32),  t0
;;								## 1
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.10?2auto_size, 0x0
 ## End yywrap
.section .bss
.section .data
.skip 2
_?1PACKET.7:
    .data1 0
    .data1 0
    .data1 0
    .data1 0
    .data1 0
    .data1 0
    .data1 2
    .data1 7
    .data1 9
    .data1 39
    .data1 11
    .data1 51
    .data1 4
    .data1 5
    .data1 6
    .data1 143
    .data1 141
    .data1 142
    .data1 8
    .data1 1
    .data1 3
    .data1 0
    .data1 0
    .data1 0
    .data1 0
    .data1 38
    .data1 40
    .data1 41
    .data1 43
    .data1 44
    .data1 45
    .data1 0
    .data1 0
    .data1 0
    .data1 0
    .data1 0
    .data1 10
    .data1 12
    .data1 13
    .data1 21
    .data1 20
    .data1 19
    .data1 22
    .data1 0
    .data1 0
    .data1 0
    .data1 65
    .data1 50
    .data1 52
    .data1 53
    .data1 55
    .data1 0
    .data1 59
    .data1 57
    .data1 56
    .data1 58
    .data1 0
    .data1 46
    .data1 0
    .data1 0
    .data1 47
    .data1 42
    .data1 91
    .data1 48
    .data1 15
    .data1 37
    .data1 16
    .data1 0
    .data1 14
    .data1 17
    .data1 60
    .data1 89
    .data1 54
    .data1 64
    .data1 0
    .data1 61
    .data1 0
    .data1 76
    .data1 0
    .data1 0
    .data1 92
    .data1 0
    .data1 0
    .data1 85
    .data1 0
    .data1 110
    .data1 84
    .data1 0
    .data1 140
    .data1 139
    .data1 0
    .data1 0
    .data1 0
    .data1 0
    .data1 90
    .data1 138
    .data1 0
    .data1 0
    .data1 30
    .data1 31
    .data1 32
    .data1 33
    .data1 34
    .data1 0
    .data1 18
    .data1 23
    .data1 0
    .data1 0
    .data1 82
    .data1 0
    .data1 0
    .data1 143
    .data1 0
    .data1 110
    .data1 66
    .data1 73
    .data1 71
    .data1 69
    .data1 72
    .data1 70
    .data1 68
    .data1 0
    .data1 111
    .data1 112
    .data1 114
    .data1 115
    .data1 116
    .data1 63
    .data1 0
    .data1 136
    .data1 135
    .data1 0
    .data1 137
    .data1 0
    .data1 0
    .data1 93
    .data1 27
    .data1 26
    .data1 24
    .data1 140
    .data1 35
    .data1 28
    .data1 0
    .data1 0
    .data1 105
    .data1 81
    .data1 0
    .data1 80
    .data1 88
    .data1 0
    .data1 74
    .data1 117
    .data1 119
    .data1 62
    .data1 67
    .data1 0
    .data1 108
    .data1 0
    .data1 113
    .data1 49
    .data1 132
    .data1 133
    .data1 134
    .data1 0
    .data1 0
    .data1 25
    .data1 0
    .data1 0
    .data1 0
    .data1 94
    .data1 0
    .data1 0
    .data1 122
    .data1 109
    .data1 29
    .data1 36
    .data1 107
    .data1 87
    .data1 0
    .data1 106
    .data1 0
    .data1 0
    .data1 0
    .data1 0
    .data1 95
    .data1 98
    .data1 0
    .data1 75
    .data1 120
    .data1 0
    .data1 118
    .data1 126
    .data1 127
    .data1 129
    .data1 94
    .data1 77
    .data1 0
    .data1 86
    .data1 96
    .data1 0
    .data1 0
    .data1 0
    .data1 0
    .data1 122
    .data1 0
    .data1 0
    .data1 123
    .data1 0
    .data1 0
    .data1 0
    .data1 0
    .data1 99
    .data1 0
    .data1 0
    .data1 100
    .data1 0
    .data1 138
    .data1 121
    .data1 130
    .data1 128
    .data1 0
    .data1 0
    .data1 0
    .data1 87
    .data1 0
    .data1 102
    .data1 103
    .data1 97
    .data1 0
    .data1 0
    .data1 124
    .data1 131
    .data1 0
    .data1 94
    .data1 104
    .data1 101
    .data1 83
    .data1 0
    .data1 0
    .data1 78
    .data1 0
    .data1 0
    .data1 94
    .data1 0
    .data1 79
.skip 3
_?1PACKET.2:
    .data4 ((_?1STRINGPACKET.1 + 0) + 0)
    .data4 ((_?1STRINGPACKET.2 + 0) + 0)
_?1STRINGPACKET.1:
    .data1 108
    .data1 111
    .data1 99
    .data1 97
    .data1 108
    .data1 0
.skip 2
_?1STRINGPACKET.2:
    .data1 103
    .data1 108
    .data1 111
    .data1 98
    .data1 97
    .data1 108
    .data1 0
.skip 1
_?1PACKET.6:
    .data1 0
    .data1 2
    .data1 1
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 0
    .data1 1
    .data1 1
    .data1 2
    .data1 2
    .data1 2
    .data1 0
    .data1 4
    .data1 1
    .data1 1
    .data1 1
    .data1 1
    .data1 1
    .data1 2
    .data1 3
    .data1 2
    .data1 2
    .data1 1
    .data1 3
    .data1 1
    .data1 1
    .data1 1
    .data1 1
    .data1 1
    .data1 0
    .data1 2
    .data1 2
    .data1 2
    .data1 0
    .data1 1
    .data1 1
    .data1 2
    .data1 1
    .data1 1
    .data1 1
    .data1 2
    .data1 2
    .data1 2
    .data1 6
    .data1 2
    .data1 0
    .data1 1
    .data1 1
    .data1 2
    .data1 1
    .data1 1
    .data1 1
    .data1 1
    .data1 1
    .data1 2
    .data1 0
    .data1 5
    .data1 4
    .data1 2
    .data1 1
    .data1 1
    .data1 2
    .data1 1
    .data1 1
    .data1 1
    .data1 1
    .data1 1
    .data1 1
    .data1 2
    .data1 4
    .data1 2
    .data1 0
    .data1 0
    .data1 16
    .data1 1
    .data1 1
    .data1 0
    .data1 11
    .data1 2
    .data1 1
    .data1 5
    .data1 1
    .data1 1
    .data1 2
    .data1 4
    .data1 1
    .data1 2
    .data1 5
    .data1 0
    .data1 1
    .data1 2
    .data1 4
    .data1 1
    .data1 3
    .data1 3
    .data1 5
    .data1 4
    .data1 1
    .data1 3
    .data1 1
    .data1 3
    .data1 3
    .data1 2
    .data1 2
    .data1 0
    .data1 1
    .data1 1
    .data1 2
    .data1 1
    .data1 1
    .data1 1
    .data1 0
    .data1 4
    .data1 2
    .data1 0
    .data1 6
    .data1 0
    .data1 0
    .data1 4
    .data1 2
    .data1 1
    .data1 1
    .data1 3
    .data1 1
    .data1 3
    .data1 4
    .data1 3
    .data1 3
    .data1 3
    .data1 2
    .data1 2
    .data1 2
    .data1 1
    .data1 1
    .data1 1
    .data1 1
    .data1 1
    .data1 1
_?1PACKET.10:
    .data2 -192
    .data2 -192
    .data2 264
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 236
    .data2 -192
    .data2 -192
    .data2 170
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 244
    .data2 -192
    .data2 3
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 232
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 163
    .data2 -192
    .data2 -83
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 109
    .data2 -192
    .data2 70
    .data2 43
    .data2 -192
    .data2 -2
    .data2 -42
    .data2 0
    .data2 -191
    .data2 -192
    .data2 98
    .data2 84
    .data2 -173
    .data2 -192
    .data2 115
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 165
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 83
    .data2 -192
    .data2 68
    .data2 80
    .data2 -67
    .data2 -4
.skip 2
_?1PACKET.5:
    .data1 0
    .data1 54
    .data1 55
    .data1 55
    .data1 56
    .data1 56
    .data1 56
    .data1 56
    .data1 56
    .data1 56
    .data1 57
    .data1 58
    .data1 58
    .data1 59
    .data1 59
    .data1 60
    .data1 60
    .data1 61
    .data1 60
    .data1 60
    .data1 60
    .data1 60
    .data1 60
    .data1 62
    .data1 62
    .data1 63
    .data1 63
    .data1 63
    .data1 64
    .data1 64
    .data1 65
    .data1 65
    .data1 65
    .data1 65
    .data1 65
    .data1 66
    .data1 66
    .data1 67
    .data1 68
    .data1 69
    .data1 69
    .data1 70
    .data1 70
    .data1 71
    .data1 71
    .data1 71
    .data1 71
    .data1 71
    .data1 72
    .data1 73
    .data1 74
    .data1 75
    .data1 75
    .data1 76
    .data1 76
    .data1 77
    .data1 77
    .data1 77
    .data1 77
    .data1 77
    .data1 77
    .data1 79
    .data1 78
    .data1 78
    .data1 78
    .data1 80
    .data1 81
    .data1 81
    .data1 82
    .data1 82
    .data1 82
    .data1 82
    .data1 82
    .data1 82
    .data1 83
    .data1 83
    .data1 84
    .data1 86
    .data1 87
    .data1 85
    .data1 88
    .data1 88
    .data1 88
    .data1 89
    .data1 89
    .data1 90
    .data1 91
    .data1 92
    .data1 93
    .data1 94
    .data1 95
    .data1 96
    .data1 96
    .data1 97
    .data1 98
    .data1 98
    .data1 98
    .data1 99
    .data1 100
    .data1 100
    .data1 101
    .data1 101
    .data1 101
    .data1 102
    .data1 102
    .data1 103
    .data1 103
    .data1 104
    .data1 105
    .data1 106
    .data1 107
    .data1 107
    .data1 108
    .data1 108
    .data1 109
    .data1 109
    .data1 109
    .data1 111
    .data1 110
    .data1 112
    .data1 114
    .data1 113
    .data1 115
    .data1 116
    .data1 115
    .data1 115
    .data1 115
    .data1 117
    .data1 117
    .data1 118
    .data1 118
    .data1 118
    .data1 119
    .data1 119
    .data1 119
    .data1 119
    .data1 119
    .data1 119
    .data1 119
    .data1 119
    .data1 119
    .data1 120
    .data1 120
    .data1 120
_?1PACKET.13:
    .data1 0
    .data1 7
    .data1 21
    .data1 22
    .data1 24
    .data1 55
    .data1 56
    .data1 33
    .data1 30
    .data1 5
    .data1 9
    .data1 25
    .data1 57
    .data1 68
    .data1 74
    .data1 28
    .data1 29
    .data1 31
    .data1 120
    .data1 0
    .data1 56
    .data1 3
    .data1 8
    .data1 15
    .data1 23
    .data1 69
    .data1 70
    .data1 71
    .data1 72
    .data1 73
    .data1 95
    .data1 120
    .data1 3
    .data1 16
    .data1 23
    .data1 27
    .data1 58
    .data1 59
    .data1 60
    .data1 67
    .data1 73
    .data1 95
    .data1 97
    .data1 120
    .data1 3
    .data1 16
    .data1 17
    .data1 75
    .data1 76
    .data1 77
    .data1 78
    .data1 80
    .data1 84
    .data1 94
    .data1 95
    .data1 97
    .data1 120
    .data1 30
    .data1 120
    .data1 120
    .data1 30
    .data1 71
    .data1 45
    .data1 96
    .data1 30
    .data1 120
    .data1 30
    .data1 120
    .data1 60
    .data1 96
    .data1 30
    .data1 120
    .data1 77
    .data1 13
    .data1 14
    .data1 89
    .data1 120
    .data1 96
    .data1 44
    .data1 44
    .data1 45
    .data1 44
    .data1 61
    .data1 29
    .data1 90
    .data1 79
    .data1 96
    .data1 30
    .data1 30
    .data1 34
    .data1 35
    .data1 36
    .data1 46
    .data1 53
    .data1 119
    .data1 120
    .data1 48
    .data1 4
    .data1 10
    .data1 11
    .data1 12
    .data1 18
    .data1 19
    .data1 23
    .data1 62
    .data1 63
    .data1 65
    .data1 44
    .data1 6
    .data1 20
    .data1 26
    .data1 28
    .data1 32
    .data1 81
    .data1 82
    .data1 83
    .data1 84
    .data1 85
    .data1 91
    .data1 95
    .data1 105
    .data1 107
    .data1 108
    .data1 109
    .data1 110
    .data1 112
    .data1 113
    .data1 13
    .data1 44
    .data1 119
    .data1 119
    .data1 119
    .data1 119
    .data1 35
    .data1 36
    .data1 29
    .data1 33
    .data1 30
    .data1 63
    .data1 30
    .data1 64
    .data1 119
    .data1 29
    .data1 103
    .data1 104
    .data1 34
    .data1 88
    .data1 120
    .data1 29
    .data1 93
    .data1 30
    .data1 31
    .data1 30
    .data1 13
    .data1 82
    .data1 49
    .data1 106
    .data1 28
    .data1 109
    .data1 30
    .data1 47
    .data1 119
    .data1 119
    .data1 44
    .data1 45
    .data1 66
    .data1 52
    .data1 44
    .data1 44
    .data1 46
    .data1 44
    .data1 44
    .data1 111
    .data1 49
    .data1 30
    .data1 30
    .data1 119
    .data1 29
    .data1 92
    .data1 104
    .data1 90
    .data1 45
    .data1 98
    .data1 99
    .data1 100
    .data1 101
    .data1 119
    .data1 30
    .data1 30
    .data1 50
    .data1 115
    .data1 117
    .data1 118
    .data1 119
    .data1 46
    .data1 44
    .data1 119
    .data1 47
    .data1 100
    .data1 119
    .data1 44
    .data1 44
    .data1 45
    .data1 114
    .data1 34
    .data1 44
    .data1 52
    .data1 50
    .data1 98
    .data1 86
    .data1 45
    .data1 101
    .data1 30
    .data1 50
    .data1 102
    .data1 119
    .data1 120
    .data1 115
    .data1 51
    .data1 118
    .data1 116
    .data1 34
    .data1 47
    .data1 29
    .data1 92
    .data1 102
    .data1 120
    .data1 49
    .data1 30
    .data1 45
    .data1 117
    .data1 51
    .data1 120
    .data1 46
    .data1 51
    .data1 102
    .data1 96
    .data1 98
    .data1 47
    .data1 44
    .data1 87
    .data1 93
    .data1 46
    .data1 98
    .data1 47
.skip 3
_?1PACKET.8:
    .data2 -1
    .data2 5
    .data2 6
    .data2 12
    .data2 36
    .data2 37
    .data2 38
    .data2 82
    .data2 104
    .data2 105
    .data2 140
    .data2 106
    .data2 165
    .data2 39
    .data2 13
    .data2 25
    .data2 26
    .data2 27
    .data2 28
    .data2 29
    .data2 14
    .data2 47
    .data2 48
    .data2 49
    .data2 50
    .data2 85
    .data2 51
    .data2 113
    .data2 114
    .data2 115
    .data2 52
    .data2 117
    .data2 209
    .data2 240
    .data2 146
    .data2 75
    .data2 84
    .data2 118
    .data2 178
    .data2 149
    .data2 53
    .data2 30
    .data2 63
    .data2 42
    .data2 182
    .data2 183
    .data2 184
    .data2 185
    .data2 214
    .data2 143
    .data2 144
    .data2 120
    .data2 156
    .data2 121
    .data2 122
    .data2 123
    .data2 124
    .data2 172
    .data2 125
    .data2 126
    .data2 203
    .data2 190
    .data2 220
    .data2 191
    .data2 192
    .data2 186
    .data2 95
.skip 2
_?1PACKET.9:
    .data2 31
    .data2 -23
    .data2 -15
    .data2 11
    .data2 129
    .data2 223
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 69
    .data2 42
    .data2 59
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -13
    .data2 129
    .data2 129
    .data2 2
    .data2 -192
    .data2 69
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 4
    .data2 13
    .data2 129
    .data2 24
    .data2 129
    .data2 -192
    .data2 42
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 4
    .data2 29
    .data2 129
    .data2 -192
    .data2 -192
    .data2 59
    .data2 -192
    .data2 -192
    .data2 65
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 4
    .data2 -192
    .data2 41
    .data2 45
    .data2 -192
    .data2 -192
    .data2 35
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 47
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 66
    .data2 -192
    .data2 4
    .data2 -192
    .data2 89
    .data2 173
    .data2 -192
    .data2 82
    .data2 230
    .data2 -192
    .data2 93
    .data2 114
    .data2 126
    .data2 103
    .data2 -192
    .data2 -192
    .data2 173
    .data2 173
    .data2 173
    .data2 173
    .data2 -8
    .data2 -192
    .data2 130
    .data2 137
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 141
    .data2 230
    .data2 -192
    .data2 186
    .data2 143
    .data2 226
    .data2 160
    .data2 148
    .data2 164
    .data2 161
    .data2 95
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 151
    .data2 36
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 175
    .data2 -192
    .data2 -192
    .data2 71
    .data2 -192
    .data2 173
    .data2 173
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 166
    .data2 167
    .data2 -8
    .data2 159
    .data2 169
    .data2 -192
    .data2 -192
    .data2 180
    .data2 -192
    .data2 -192
    .data2 181
    .data2 184
    .data2 185
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 182
    .data2 -192
    .data2 164
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 203
    .data2 205
    .data2 -192
    .data2 173
    .data2 207
    .data2 66
    .data2 120
    .data2 208
    .data2 213
    .data2 133
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 -8
    .data2 159
    .data2 191
    .data2 -192
    .data2 202
    .data2 173
    .data2 204
    .data2 120
    .data2 206
    .data2 -192
    .data2 149
    .data2 -192
    .data2 -192
    .data2 218
    .data2 -192
    .data2 100
    .data2 -192
    .data2 67
    .data2 120
    .data2 -192
    .data2 77
    .data2 -192
    .data2 206
    .data2 96
    .data2 120
    .data2 228
    .data2 146
    .data2 133
    .data2 210
    .data2 133
    .data2 -28
    .data2 222
    .data2 212
    .data2 233
    .data2 32
    .data2 -192
    .data2 214
    .data2 234
    .data2 -192
    .data2 152
    .data2 81
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 133
    .data2 215
    .data2 129
    .data2 -192
    .data2 219
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 216
    .data2 32
    .data2 224
    .data2 -192
    .data2 4
    .data2 120
    .data2 -192
    .data2 -192
    .data2 -192
    .data2 225
    .data2 227
    .data2 -192
    .data2 160
    .data2 229
    .data2 120
    .data2 231
    .data2 -192
.skip 2
_?1PACKET.12:
    .data1 4
    .data1 43
    .data1 85
    .data1 194
    .data1 32
    .data1 9
    .data1 10
    .data1 11
    .data1 10
    .data1 11
    .data1 33
    .data1 11
    .data1 79
    .data1 10
    .data1 56
    .data1 30
    .data1 5
    .data1 30
    .data1 22
    .data1 23
    .data1 9
    .data1 49
    .data1 26
    .data1 90
    .data1 91
    .data1 92
    .data1 93
    .data1 35
    .data1 36
    .data1 33
    .data1 113
    .data1 35
    .data1 30
    .data1 37
    .data1 76
    .data1 37
    .data1 25
    .data1 210
    .data1 7
    .data1 106
    .data1 37
    .data1 45
    .data1 233
    .data1 30
    .data1 48
    .data1 3
    .data1 48
    .data1 51
    .data1 48
    .data1 45
    .data1 8
    .data1 242
    .data1 21
    .data1 22
    .data1 30
    .data1 24
    .data1 229
    .data1 15
    .data1 16
    .data1 30
    .data1 28
    .data1 29
    .data1 3
    .data1 31
    .data1 28
    .data1 23
    .data1 133
    .data1 134
    .data1 32
    .data1 27
    .data1 28
    .data1 29
    .data1 3
    .data1 31
    .data1 15
    .data1 16
    .data1 17
    .data1 8
    .data1 13
    .data1 14
    .data1 45
    .data1 85
    .data1 50
    .data1 85
    .data1 15
    .data1 44
    .data1 27
    .data1 28
    .data1 29
    .data1 44
    .data1 31
    .data1 44
    .data1 23
    .data1 28
    .data1 29
    .data1 29
    .data1 31
    .data1 28
    .data1 29
    .data1 166
    .data1 31
    .data1 6
    .data1 35
    .data1 36
    .data1 108
    .data1 172
    .data1 35
    .data1 36
    .data1 13
    .data1 113
    .data1 15
    .data1 113
    .data1 35
    .data1 36
    .data1 181
    .data1 20
    .data1 183
    .data1 50
    .data1 47
    .data1 30
    .data1 6
    .data1 26
    .data1 45
    .data1 28
    .data1 29
    .data1 44
    .data1 31
    .data1 32
    .data1 47
    .data1 15
    .data1 48
    .data1 35
    .data1 36
    .data1 200
    .data1 20
    .data1 202
    .data1 203
    .data1 44
    .data1 205
    .data1 13
    .data1 26
    .data1 45
    .data1 28
    .data1 29
    .data1 44
    .data1 31
    .data1 32
    .data1 44
    .data1 28
    .data1 29
    .data1 30
    .data1 31
    .data1 52
    .data1 220
    .data1 34
    .data1 35
    .data1 36
    .data1 28
    .data1 29
    .data1 29
    .data1 31
    .data1 28
    .data1 29
    .data1 30
    .data1 31
    .data1 45
    .data1 46
    .data1 34
    .data1 35
    .data1 36
    .data1 33
    .data1 30
    .data1 29
    .data1 53
    .data1 28
    .data1 29
    .data1 30
    .data1 31
    .data1 30
    .data1 46
    .data1 34
    .data1 35
    .data1 36
    .data1 50
    .data1 35
    .data1 36
    .data1 53
    .data1 35
    .data1 36
    .data1 29
    .data1 232
    .data1 30
    .data1 46
    .data1 44
    .data1 45
    .data1 31
    .data1 50
    .data1 45
    .data1 202
    .data1 53
    .data1 49
    .data1 28
    .data1 29
    .data1 30
    .data1 31
    .data1 30
    .data1 210
    .data1 34
    .data1 35
    .data1 36
    .data1 44
    .data1 52
    .data1 45
    .data1 44
    .data1 28
    .data1 29
    .data1 30
    .data1 31
    .data1 222
    .data1 46
    .data1 34
    .data1 35
    .data1 36
    .data1 0
    .data1 44
    .data1 229
    .data1 53
    .data1 46
    .data1 44
    .data1 44
    .data1 7
    .data1 49
    .data1 46
    .data1 30
    .data1 4
    .data1 30
    .data1 29
    .data1 46
    .data1 30
    .data1 53
    .data1 10
    .data1 11
    .data1 12
    .data1 30
    .data1 21
    .data1 22
    .data1 44
    .data1 24
    .data1 18
    .data1 19
    .data1 44
    .data1 47
    .data1 34
    .data1 23
    .data1 28
    .data1 29
    .data1 34
    .data1 31
    .data1 30
    .data1 47
    .data1 34
    .data1 51
    .data1 29
    .data1 49
    .data1 30
    .data1 46
    .data1 51
    .data1 51
    .data1 44
    .data1 5
    .data1 26
    .data1 44
    .data1 47
    .data1 37
    .data1 104
    .data1 46
    .data1 113
    .data1 168
    .data1 47
    .data1 209
    .data1 48
    .data1 183
    .data1 167
    .data1 240
    .data1 200
    .data1 205
    .data1 203
    .data1 122
    .data1 220
.skip 3
_?1PACKET.11:
    .data2 18
    .data2 69
    .data2 116
    .data2 208
    .data2 -125
    .data2 31
    .data2 43
    .data2 56
    .data2 41
    .data2 54
    .data2 7
    .data2 55
    .data2 94
    .data2 40
    .data2 77
    .data2 8
    .data2 9
    .data2 57
    .data2 58
    .data2 59
    .data2 10
    .data2 -125
    .data2 31
    .data2 129
    .data2 130
    .data2 131
    .data2 132
    .data2 133
    .data2 134
    .data2 65
    .data2 116
    .data2 67
    .data2 60
    .data2 43
    .data2 86
    .data2 41
    .data2 11
    .data2 225
    .data2 1
    .data2 141
    .data2 40
    .data2 71
    .data2 237
    .data2 64
    .data2 56
    .data2 32
    .data2 54
    .data2 76
    .data2 55
    .data2 62
    .data2 22
    .data2 243
    .data2 2
    .data2 3
    .data2 66
    .data2 4
    .data2 235
    .data2 23
    .data2 33
    .data2 70
    .data2 15
    .data2 16
    .data2 44
    .data2 17
    .data2 157
    .data2 34
    .data2 161
    .data2 162
    .data2 112
    .data2 35
    .data2 15
    .data2 16
    .data2 21
    .data2 17
    .data2 23
    .data2 45
    .data2 46
    .data2 22
    .data2 73
    .data2 74
    .data2 80
    .data2 56
    .data2 213
    .data2 119
    .data2 23
    .data2 78
    .data2 35
    .data2 15
    .data2 16
    .data2 79
    .data2 17
    .data2 81
    .data2 24
    .data2 15
    .data2 16
    .data2 83
    .data2 17
    .data2 15
    .data2 16
    .data2 176
    .data2 17
    .data2 108
    .data2 133
    .data2 134
    .data2 147
    .data2 193
    .data2 133
    .data2 134
    .data2 153
    .data2 56
    .data2 23
    .data2 119
    .data2 133
    .data2 134
    .data2 196
    .data2 109
    .data2 199
    .data2 207
    .data2 160
    .data2 87
    .data2 108
    .data2 110
    .data2 210
    .data2 111
    .data2 16
    .data2 -103
    .data2 17
    .data2 112
    .data2 -103
    .data2 23
    .data2 96
    .data2 133
    .data2 134
    .data2 199
    .data2 109
    .data2 215
    .data2 193
    .data2 107
    .data2 193
    .data2 127
    .data2 110
    .data2 202
    .data2 111
    .data2 16
    .data2 205
    .data2 17
    .data2 112
    .data2 128
    .data2 15
    .data2 16
    .data2 88
    .data2 17
    .data2 206
    .data2 193
    .data2 89
    .data2 90
    .data2 91
    .data2 15
    .data2 16
    .data2 135
    .data2 17
    .data2 15
    .data2 16
    .data2 88
    .data2 17
    .data2 181
    .data2 92
    .data2 89
    .data2 90
    .data2 91
    .data2 136
    .data2 137
    .data2 142
    .data2 93
    .data2 15
    .data2 16
    .data2 88
    .data2 17
    .data2 150
    .data2 92
    .data2 89
    .data2 90
    .data2 91
    .data2 189
    .data2 133
    .data2 134
    .data2 93
    .data2 133
    .data2 134
    .data2 148
    .data2 236
    .data2 152
    .data2 92
    .data2 201
    .data2 202
    .data2 151
    .data2 213
    .data2 229
    .data2 216
    .data2 93
    .data2 155
    .data2 15
    .data2 16
    .data2 88
    .data2 17
    .data2 159
    .data2 226
    .data2 89
    .data2 90
    .data2 91
    .data2 163
    .data2 166
    .data2 164
    .data2 167
    .data2 15
    .data2 16
    .data2 139
    .data2 17
    .data2 232
    .data2 92
    .data2 89
    .data2 90
    .data2 91
    .data2 19
    .data2 168
    .data2 226
    .data2 93
    .data2 169
    .data2 170
    .data2 171
    .data2 1
    .data2 173
    .data2 92
    .data2 174
    .data2 97
    .data2 175
    .data2 177
    .data2 194
    .data2 187
    .data2 93
    .data2 98
    .data2 99
    .data2 100
    .data2 188
    .data2 2
    .data2 3
    .data2 195
    .data2 4
    .data2 101
    .data2 102
    .data2 200
    .data2 197
    .data2 204
    .data2 103
    .data2 15
    .data2 16
    .data2 221
    .data2 17
    .data2 212
    .data2 222
    .data2 145
    .data2 218
    .data2 223
    .data2 227
    .data2 228
    .data2 233
    .data2 231
    .data2 234
    .data2 205
    .data2 20
    .data2 61
    .data2 239
    .data2 238
    .data2 68
    .data2 138
    .data2 242
    .data2 154
    .data2 180
    .data2 244
    .data2 224
    .data2 72
    .data2 198
    .data2 179
    .data2 241
    .data2 211
    .data2 219
    .data2 217
    .data2 158
    .data2 230
.skip 2
_?1PACKET.3:
    .data4 0
_?1PACKET.4:
    .data1 0
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 46
    .data1 47
    .data1 2
    .data1 35
    .data1 44
    .data1 36
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 45
    .data1 49
    .data1 2
    .data1 52
    .data1 2
    .data1 2
    .data1 48
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 50
    .data1 2
    .data1 51
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 53
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 2
    .data1 1
    .data1 2
    .data1 3
    .data1 4
    .data1 5
    .data1 6
    .data1 7
    .data1 8
    .data1 9
    .data1 10
    .data1 11
    .data1 12
    .data1 13
    .data1 14
    .data1 15
    .data1 16
    .data1 17
    .data1 18
    .data1 19
    .data1 20
    .data1 21
    .data1 22
    .data1 23
    .data1 24
    .data1 25
    .data1 26
    .data1 27
    .data1 28
    .data1 29
    .data1 30
    .data1 31
    .data1 32
    .data1 33
    .data1 34
    .data1 37
    .data1 38
    .data1 39
    .data1 40
    .data1 41
    .data1 42
    .data1 43
.section .data
.import yylineno
.type yylineno,@object
.import yyout
.type yyout,@object
.import _impure_ptr
.type _impure_ptr,@object
.comm yynerrs, 0x4, 4
.comm yylval, 0x8, 4
.comm yychar, 0x4, 4
.section .text
.import yylex
.type yylex,@function
.import yyerror
.type yyerror,@function
.import printf
.type printf,@function
.import fprintf
.type fprintf,@function
.import malloc
.type malloc,@function
.import free
.type free,@function
.import exit
.type exit,@function

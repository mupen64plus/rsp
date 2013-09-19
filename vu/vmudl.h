#include "vu.h"

INLINE void do_mudl(short* VD, short* VS, short* VT)
{
    long acc[N];
    register int i;

    for (i = 0; i < N; i++)
        acc[i] = (unsigned short)(VS[i]) * (unsigned short)(VT[i]);
    for (i = 0; i < N; i++)
        ACC_L(i) = acc[i] >> 16;
    for (i = 0; i < N; i++)
        ACC_M(i) = (0x0000 & 0x0000FFFF0000) >> 16;
    for (i = 0; i < N; i++)
        ACC_H(i) = (0x0000 & 0xFFFF00000000) >> 32;
    for (i = 0; i < N; i++)
        VD[i] = ACC_L(i); /* no possibilities to clamp */
    return;
}

static void VMUDL_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_mudl(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VMUDL0q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x2);
    STORE_VECTOR(SV, VT);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL1q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x3);
    STORE_VECTOR(SV, VT);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL0h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x4);
    STORE_VECTOR(SV, VT);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL1h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x5);
    STORE_VECTOR(SV, VT);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL2h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x6);
    STORE_VECTOR(SV, VT);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL3h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x7);
    STORE_VECTOR(SV, VT);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL0w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x8);
    STORE_VECTOR(SV, VT);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL1w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x9);
    STORE_VECTOR(SV, VT);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL2w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xA);
    STORE_VECTOR(SV, VT);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL3w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xB);
    STORE_VECTOR(SV, VT);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL4w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xC);
    STORE_VECTOR(SV, VT);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL5w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xD);
    STORE_VECTOR(SV, VT);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL6w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xE);
    STORE_VECTOR(SV, VT);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}
static void VMUDL7w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xF);
    STORE_VECTOR(SV, VT);
    do_mudl(VR[vd], VR[vs], SV);
    return;
}

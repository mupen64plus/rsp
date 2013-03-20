/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Byte from Vector Unit                *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.20                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SBV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + offset;
    addr &= 0x00000FFF; /* RCP no-exception override:  Force SP DMEM range. */
    RSP.DMEM[addr ^ 03] = (VR[vt][element >> 1] >> 8*(!(element & 0x1))) & 0xFF;
    return;
}

/* Note about vector registers.
 * RSP vectors are just like standard mathematical vectors, big endian.
 * It is correct to have them as big-endian arrays, with bits in little.
 *
 * I have not yet figured out how to address 128-bit vectors by byte quickly.
 * The legacy of RSP emulation has always used unions to have such
 * constructors predefined, but this inverted the vector indexing endian.
 * There is no necessity for Objective-C or unions to define vectors.
 *
 * lbv, ldv, sbv, ssv, sdv, spv, and `cop2::mfc2` all require byte-indexing
 * for the demands of the standard F3DEX graphics microcodes.
 */

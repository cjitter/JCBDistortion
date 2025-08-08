#include "JCBDistortion.h"

namespace JCBDistortion {

/****************************************************************************************
Copyright (c) 2023 Cycling '74

The code that Max generates automatically and that end users are capable of
exporting and using, and any associated documentation files (the “Software”)
is a work of authorship for which Cycling '74 is the author and owner for
copyright purposes.

This Software is dual-licensed either under the terms of the Cycling '74
License for Max-Generated Code for Export, or alternatively under the terms
of the General Public License (GPL) Version 3. You may use the Software
according to either of these licenses as it is most appropriate for your
project on a case-by-case basis (proprietary or not).

A) Cycling '74 License for Max-Generated Code for Export

A license is hereby granted, free of charge, to any person obtaining a copy
of the Software (“Licensee”) to use, copy, modify, merge, publish, and
distribute copies of the Software, and to permit persons to whom the Software
is furnished to do so, subject to the following conditions:

The Software is licensed to Licensee for all uses that do not include the sale,
sublicensing, or commercial distribution of software that incorporates this
source code. This means that the Licensee is free to use this software for
educational, research, and prototyping purposes, to create musical or other
creative works with software that incorporates this source code, or any other
use that does not constitute selling software that makes use of this source
code. Commercial distribution also includes the packaging of free software with
other paid software, hardware, or software-provided commercial services.

For entities with UNDER 200k USD in annual revenue or funding, a license is hereby
granted, free of charge, for the sale, sublicensing, or commercial distribution
of software that incorporates this source code, for as long as the entity's
annual revenue remains below 200k USD annual revenue or funding.

For entities with OVER 200k USD in annual revenue or funding interested in the
sale, sublicensing, or commercial distribution of software that incorporates
this source code, please send inquiries to licensing (at) cycling74.com.

The above copyright notice and this license shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Please see
https://support.cycling74.com/hc/en-us/articles/360050779193-Gen-Code-Export-Licensing-FAQ
for additional information

B) General Public License Version 3 (GPLv3)
Details of the GPLv3 license can be found at: https://www.gnu.org/licenses/gpl-3.0.html
****************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	DCBlock __m_dcblock_105;
	DCBlock __m_dcblock_96;
	DCBlock __m_dcblock_95;
	DCBlock __m_dcblock_99;
	DCBlock __m_dcblock_104;
	DCBlock __m_dcblock_100;
	Phasor __m_phasor_101;
	int __exception;
	int vectorsize;
	t_sample m_tiltL_6;
	t_sample m_h_BITSON_37;
	t_sample m_g_BITS_38;
	t_sample m_f_BYPASS_39;
	t_sample m_i_TILT_36;
	t_sample m_j_HPF_35;
	t_sample m_k_LPF_34;
	t_sample m_e_CEILING_40;
	t_sample m_k_INPUT_32;
	t_sample m_l_SC_33;
	t_sample m_d_MODE_41;
	t_sample m_c_DC_42;
	t_sample m_b_DRIVE_43;
	t_sample samples_to_seconds;
	t_sample __m_latch_102;
	t_sample __m_latch_103;
	t_sample m_l_OUTPUT_31;
	t_sample samplerate;
	t_sample m_tiltR_2;
	t_sample m_tiltR_1;
	t_sample m_a_DRYWET_44;
	t_sample m_tiltR_3;
	t_sample m_tiltL_5;
	t_sample m_m_DOWNSAMPLE_30;
	t_sample m_hDrive_28;
	t_sample m_lpfR_z_13;
	t_sample m_hpfFreqHistory_12;
	t_sample m_lpfL_z_14;
	t_sample m_hpfR_z_15;
	t_sample m_hpfL_z_16;
	t_sample m_lpfFreqHistory_11;
	t_sample m_dsPhasor_9;
	t_sample m_scEnableHistory_10;
	t_sample m_tiltL_7;
	t_sample m_tiltL_8;
	t_sample m_n_DOWNSAMPLEON_29;
	t_sample m_hBypass_17;
	t_sample m_hDownsample_19;
	t_sample m_hBits_25;
	t_sample m_tiltR_4;
	t_sample m_hDc_27;
	t_sample m_hDownsampleOn_18;
	t_sample m_hBitson_24;
	t_sample m_hInput_22;
	t_sample m_hTilt_23;
	t_sample m_hMode_20;
	t_sample m_hOutput_21;
	t_sample m_hDrywet_26;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_tiltR_1 = ((int)0);
		m_tiltR_2 = ((int)0);
		m_tiltR_3 = ((int)0);
		m_tiltR_4 = ((int)0);
		m_tiltL_5 = ((int)0);
		m_tiltL_6 = ((int)0);
		m_tiltL_7 = ((int)0);
		m_tiltL_8 = ((int)0);
		m_dsPhasor_9 = ((int)0);
		m_scEnableHistory_10 = ((int)0);
		m_lpfFreqHistory_11 = ((int)0);
		m_hpfFreqHistory_12 = ((int)0);
		m_lpfR_z_13 = ((int)0);
		m_lpfL_z_14 = ((int)0);
		m_hpfR_z_15 = ((int)0);
		m_hpfL_z_16 = ((int)0);
		m_hBypass_17 = ((int)0);
		m_hDownsampleOn_18 = ((int)0);
		m_hDownsample_19 = ((int)0);
		m_hMode_20 = ((int)0);
		m_hOutput_21 = ((int)0);
		m_hInput_22 = ((int)0);
		m_hTilt_23 = ((int)0);
		m_hBitson_24 = ((int)0);
		m_hBits_25 = ((int)0);
		m_hDrywet_26 = ((int)0);
		m_hDc_27 = ((int)0);
		m_hDrive_28 = ((int)0);
		m_n_DOWNSAMPLEON_29 = 0;
		m_m_DOWNSAMPLE_30 = 0;
		m_l_OUTPUT_31 = 0;
		m_k_INPUT_32 = 0;
		m_l_SC_33 = 0;
		m_k_LPF_34 = 20000;
		m_j_HPF_35 = 20;
		m_i_TILT_36 = 0;
		m_h_BITSON_37 = 0;
		m_g_BITS_38 = 16;
		m_f_BYPASS_39 = 0;
		m_e_CEILING_40 = 0;
		m_d_MODE_41 = 0;
		m_c_DC_42 = 0;
		m_b_DRIVE_43 = 1;
		m_a_DRYWET_44 = 1;
		__m_dcblock_95.reset();
		__m_dcblock_96.reset();
		__m_dcblock_99.reset();
		__m_dcblock_100.reset();
		samples_to_seconds = (1 / samplerate);
		__m_phasor_101.reset(0);
		__m_latch_102 = 0;
		__m_latch_103 = 0;
		__m_dcblock_104.reset();
		__m_dcblock_105.reset();
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		t_sample * __out3 = __outs[2];
		t_sample * __out4 = __outs[3];
		t_sample * __out5 = __outs[4];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample ceiling = dbtoa(m_e_CEILING_40);
		t_sample omega = safediv(((t_sample)5026.5482457437), samplerate);
		t_sample sn = sin(omega);
		t_sample cs = cos(omega);
		samples_to_seconds = (1 / samplerate);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample lIn = in1;
			t_sample rIn = in2;
			m_hDrive_28 = ((m_hDrive_28 * ((t_sample)0.999)) + (m_b_DRIVE_43 * ((t_sample)0.001)));
			t_sample drive = m_hDrive_28;
			m_hDc_27 = ((m_hDc_27 * ((t_sample)0.999)) + (m_c_DC_42 * ((t_sample)0.001)));
			t_sample dc = m_hDc_27;
			m_hDrywet_26 = ((m_hDrywet_26 * ((t_sample)0.999)) + (m_a_DRYWET_44 * ((t_sample)0.001)));
			t_sample drywet = m_hDrywet_26;
			m_hBits_25 = ((m_hBits_25 * ((t_sample)0.999)) + (m_g_BITS_38 * ((t_sample)0.001)));
			t_sample bits = m_hBits_25;
			m_hBitson_24 = ((m_hBitson_24 * ((t_sample)0.999)) + (m_h_BITSON_37 * ((t_sample)0.001)));
			t_sample bitson = m_hBitson_24;
			m_hTilt_23 = ((m_hTilt_23 * ((t_sample)0.999)) + (m_i_TILT_36 * ((t_sample)0.001)));
			t_sample tiltDb = m_hTilt_23;
			m_hInput_22 = ((m_hInput_22 * ((t_sample)0.999)) + (m_k_INPUT_32 * ((t_sample)0.001)));
			t_sample inputTrimDb = m_hInput_22;
			m_hOutput_21 = ((m_hOutput_21 * ((t_sample)0.999)) + (m_l_OUTPUT_31 * ((t_sample)0.001)));
			t_sample outputMakeupDb = m_hOutput_21;
			m_hMode_20 = ((m_hMode_20 * ((t_sample)0.99)) + (m_d_MODE_41 * ((t_sample)0.01)));
			t_sample smoothedMode = m_hMode_20;
			m_hDownsample_19 = ((m_hDownsample_19 * ((t_sample)0.999)) + (m_m_DOWNSAMPLE_30 * ((t_sample)0.001)));
			m_hDownsampleOn_18 = ((m_hDownsampleOn_18 * ((t_sample)0.999)) + (m_n_DOWNSAMPLEON_29 * ((t_sample)0.001)));
			t_sample downsampleOn = m_hDownsampleOn_18;
			m_hBypass_17 = ((m_hBypass_17 * ((t_sample)0.999)) + ((((int)1) - m_f_BYPASS_39) * ((t_sample)0.001)));
			t_sample bypass = m_hBypass_17;
			t_sample smoothHpfFreq = ((m_hpfFreqHistory_12 * ((t_sample)0.999)) + (m_j_HPF_35 * ((t_sample)0.001)));
			m_hpfFreqHistory_12 = fixdenorm(smoothHpfFreq);
			t_sample smoothLpfFreq = ((m_lpfFreqHistory_11 * ((t_sample)0.999)) + (m_k_LPF_34 * ((t_sample)0.001)));
			m_lpfFreqHistory_11 = fixdenorm(smoothLpfFreq);
			t_sample smoothScEnable = ((m_scEnableHistory_10 * ((t_sample)0.999)) + (m_l_SC_33 * ((t_sample)0.001)));
			m_scEnableHistory_10 = fixdenorm(smoothScEnable);
			t_sample inputTrimLinear = dbtoa(inputTrimDb);
			t_sample outputMakeupLinear = dbtoa(outputMakeupDb);
			t_sample lTrimmed = (lIn * inputTrimLinear);
			t_sample rTrimmed = (rIn * inputTrimLinear);
			t_sample hpf_freq = ((smoothHpfFreq <= ((int)20)) ? ((int)20) : ((smoothHpfFreq >= ((int)20000)) ? ((int)20000) : smoothHpfFreq));
			t_sample hpf_coeff = exp(safediv((((t_sample)-6.2831853071796) * hpf_freq), samplerate));
			t_sample hpfL_out = (lTrimmed - m_hpfL_z_16);
			m_hpfL_z_16 = (lTrimmed - (hpfL_out * hpf_coeff));
			t_sample hpfR_out = (rTrimmed - m_hpfR_z_15);
			m_hpfR_z_15 = (rTrimmed - (hpfR_out * hpf_coeff));
			t_sample lpf_freq = ((smoothLpfFreq <= ((int)20)) ? ((int)20) : ((smoothLpfFreq >= ((int)20000)) ? ((int)20000) : smoothLpfFreq));
			t_sample lpf_coeff = safediv((((t_sample)6.2831853071796) * lpf_freq), samplerate);
			t_sample lpf_coeff_579 = ((lpf_coeff <= ((int)0)) ? ((int)0) : ((lpf_coeff >= ((int)1)) ? ((int)1) : lpf_coeff));
			m_lpfL_z_14 = (m_lpfL_z_14 + (lpf_coeff_579 * (hpfL_out - m_lpfL_z_14)));
			m_lpfR_z_13 = (m_lpfR_z_13 + (lpf_coeff_579 * (hpfR_out - m_lpfR_z_13)));
			t_sample filteredL = m_lpfL_z_14;
			t_sample filteredR = m_lpfR_z_13;
			t_sample mix_603 = (lTrimmed + (smoothScEnable * (filteredL - lTrimmed)));
			t_sample lFiltered = mix_603;
			t_sample mix_604 = (rTrimmed + (smoothScEnable * (filteredR - rTrimmed)));
			t_sample rFiltered = mix_604;
			t_sample tiltGain = dbtoa((-tiltDb));
			t_sample A = sqrt(tiltGain);
			t_sample beta = sqrt(((((A * A) + ((int)1)) * ((t_sample)1.4142271248763)) - ((A - ((int)1)) * (A - ((int)1)))));
			t_sample b0Ls = safediv(((int)1), (((A + ((int)1)) + ((A - ((int)1)) * cs)) + (beta * sn)));
			t_sample a0Ls = ((A * (((A + ((int)1)) - ((A - ((int)1)) * cs)) + (beta * sn))) * b0Ls);
			t_sample a1Ls = (((((int)2) * A) * ((A - ((int)1)) - ((A + ((int)1)) * cs))) * b0Ls);
			t_sample a2Ls = ((A * (((A + ((int)1)) - ((A - ((int)1)) * cs)) - (beta * sn))) * b0Ls);
			t_sample b1Ls = ((((int)-2) * ((A - ((int)1)) + ((A + ((int)1)) * cs))) * b0Ls);
			t_sample b2Ls = ((((A + ((int)1)) + ((A - ((int)1)) * cs)) - (beta * sn)) * b0Ls);
			t_sample lLs = (((((a0Ls * lFiltered) + (a1Ls * m_tiltL_7)) + (a2Ls * m_tiltL_8)) - (b1Ls * m_tiltL_5)) - (b2Ls * m_tiltL_6));
			m_tiltL_8 = m_tiltL_7;
			m_tiltL_7 = lFiltered;
			m_tiltL_6 = m_tiltL_5;
			m_tiltL_5 = lLs;
			t_sample rLs = (((((a0Ls * rFiltered) + (a1Ls * m_tiltR_3)) + (a2Ls * m_tiltR_4)) - (b1Ls * m_tiltR_1)) - (b2Ls * m_tiltR_2));
			m_tiltR_4 = m_tiltR_3;
			m_tiltR_3 = rFiltered;
			m_tiltR_2 = m_tiltR_1;
			m_tiltR_1 = rLs;
			t_sample aInv = sqrt(safediv(((int)1), tiltGain));
			t_sample betaHs = sqrt(((((aInv * aInv) + ((int)1)) * ((t_sample)1.4142271248763)) - ((aInv - ((int)1)) * (aInv - ((int)1)))));
			t_sample b0Hs = safediv(((int)1), (((aInv + ((int)1)) - ((aInv - ((int)1)) * cs)) + (betaHs * sn)));
			t_sample a0Hs = ((aInv * (((aInv + ((int)1)) + ((aInv - ((int)1)) * cs)) + (betaHs * sn))) * b0Hs);
			t_sample a1Hs = (((((int)-2) * aInv) * ((aInv - ((int)1)) + ((aInv + ((int)1)) * cs))) * b0Hs);
			t_sample a2Hs = ((aInv * (((aInv + ((int)1)) + ((aInv - ((int)1)) * cs)) - (betaHs * sn))) * b0Hs);
			t_sample b1Hs = ((((int)2) * ((aInv - ((int)1)) - ((aInv + ((int)1)) * cs))) * b0Hs);
			t_sample b2Hs = ((((aInv + ((int)1)) - ((aInv - ((int)1)) * cs)) - (betaHs * sn)) * b0Hs);
			t_sample lTilt = (((((a0Hs * lLs) + (a1Hs * m_tiltL_7)) + (a2Hs * m_tiltL_8)) - (b1Hs * m_tiltL_5)) - (b2Hs * m_tiltL_6));
			t_sample rTilt = (((((a0Hs * rLs) + (a1Hs * m_tiltR_3)) + (a2Hs * m_tiltR_4)) - (b1Hs * m_tiltR_1)) - (b2Hs * m_tiltR_2));
			t_sample return_47;
			t_sample return_48;
			softclip_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_47, return_48);
			t_sample softL = return_47;
			t_sample softR = return_48;
			t_sample return_53;
			t_sample return_54;
			sigmoid_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_53, return_54);
			t_sample sigmL = return_53;
			t_sample sigmR = return_54;
			t_sample return_57;
			t_sample return_58;
			rectF_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_57, return_58);
			t_sample rectL = return_57;
			t_sample rectR = return_58;
			t_sample return_61;
			t_sample return_62;
			fuzzExp1_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_61, return_62);
			t_sample fuzz1L = return_61;
			t_sample fuzz1R = return_62;
			t_sample return_67;
			t_sample return_68;
			tangenteHiperbolica_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_67, return_68);
			t_sample tanhL = return_67;
			t_sample tanhR = return_68;
			t_sample return_73;
			t_sample return_74;
			rectH_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_73, return_74);
			t_sample recthL = return_73;
			t_sample recthR = return_74;
			t_sample return_75;
			t_sample return_76;
			arctangent_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_75, return_76);
			t_sample atanL = return_75;
			t_sample atanR = return_76;
			t_sample return_85;
			t_sample return_86;
			hardClip_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_85, return_86);
			t_sample hardL = return_85;
			t_sample hardR = return_86;
			t_sample maxb_87 = (((int)1) - fabs((smoothedMode - ((int)0))));
			t_sample w0 = ((((int)0) < maxb_87) ? maxb_87 : ((int)0));
			t_sample maxb_88 = (((int)1) - fabs((smoothedMode - ((int)1))));
			t_sample w1 = ((((int)0) < maxb_88) ? maxb_88 : ((int)0));
			t_sample maxb_89 = (((int)1) - fabs((smoothedMode - ((int)2))));
			t_sample w2 = ((((int)0) < maxb_89) ? maxb_89 : ((int)0));
			t_sample maxb_90 = (((int)1) - fabs((smoothedMode - ((int)3))));
			t_sample w3 = ((((int)0) < maxb_90) ? maxb_90 : ((int)0));
			t_sample maxb_91 = (((int)1) - fabs((smoothedMode - ((int)4))));
			t_sample w4 = ((((int)0) < maxb_91) ? maxb_91 : ((int)0));
			t_sample maxb_92 = (((int)1) - fabs((smoothedMode - ((int)5))));
			t_sample w5 = ((((int)0) < maxb_92) ? maxb_92 : ((int)0));
			t_sample maxb_93 = (((int)1) - fabs((smoothedMode - ((int)6))));
			t_sample w6 = ((((int)0) < maxb_93) ? maxb_93 : ((int)0));
			t_sample maxb_94 = (((int)1) - fabs((smoothedMode - ((int)7))));
			t_sample w7 = ((((int)0) < maxb_94) ? maxb_94 : ((int)0));
			t_sample sumWeights = ((((((((w0 + w1) + w2) + w3) + w4) + w5) + w6) + w7) + ((t_sample)0.0001));
			t_sample w_580 = safediv(w0, sumWeights);
			t_sample w_581 = safediv(w1, sumWeights);
			t_sample w_582 = safediv(w2, sumWeights);
			t_sample w_583 = safediv(w3, sumWeights);
			t_sample w_584 = safediv(w4, sumWeights);
			t_sample w_585 = safediv(w5, sumWeights);
			t_sample w_586 = safediv(w6, sumWeights);
			t_sample w_587 = safediv(w7, sumWeights);
			t_sample distL = ((((((((softL * w_580) + (sigmL * w_581)) + (rectL * w_582)) + (fuzz1L * w_583)) + (tanhL * w_584)) + (recthL * w_585)) + (atanL * w_586)) + (hardL * w_587));
			t_sample distR = ((((((((softR * w_580) + (sigmR * w_581)) + (rectR * w_582)) + (fuzz1R * w_583)) + (tanhR * w_584)) + (recthR * w_585)) + (atanR * w_586)) + (hardR * w_587));
			t_sample processedL = __m_dcblock_95(distL);
			t_sample processedR = __m_dcblock_96(distR);
			t_sample return_97;
			t_sample return_98;
			bitCrusher_d_d_d(processedL, processedR, bits, return_97, return_98);
			t_sample bitL = return_97;
			t_sample bitR = return_98;
			t_sample bcL = __m_dcblock_99(bitL);
			t_sample bcR = __m_dcblock_100(bitR);
			t_sample mix_605 = (processedL + (bitson * (bcL - processedL)));
			t_sample mix_606 = (processedR + (bitson * (bcR - processedR)));
			t_sample deciFactor = (m_hDownsample_19 + ((int)1));
			t_sample deciFreq = safediv((samplerate * ((t_sample)0.5)), deciFactor);
			m_dsPhasor_9 = __m_phasor_101(deciFreq, samples_to_seconds);
			int dsTrigger = (m_dsPhasor_9 > ((t_sample)0.5));
			__m_latch_102 = ((dsTrigger != 0) ? mix_605 : __m_latch_102);
			t_sample dsHeldL = __m_latch_102;
			__m_latch_103 = ((dsTrigger != 0) ? mix_606 : __m_latch_103);
			t_sample dsHeldR = __m_latch_103;
			t_sample mix_607 = (mix_605 + (downsampleOn * (dsHeldL - mix_605)));
			t_sample mix_608 = (mix_606 + (downsampleOn * (dsHeldR - mix_606)));
			t_sample wetWithMakeupL = (mix_607 * outputMakeupLinear);
			t_sample wetWithMakeupR = (mix_608 * outputMakeupLinear);
			t_sample mix_609 = (lIn + (drywet * (wetWithMakeupL - lIn)));
			t_sample mix_610 = (rIn + (drywet * (wetWithMakeupR - rIn)));
			t_sample finalDcBlockedL = __m_dcblock_104(mix_609);
			t_sample finalDcBlockedR = __m_dcblock_105(mix_610);
			t_sample mix_611 = (lIn + (bypass * (finalDcBlockedL - lIn)));
			t_sample mix_612 = (rIn + (bypass * (finalDcBlockedR - rIn)));
			t_sample out1 = mix_611;
			t_sample out4 = lTrimmed;
			t_sample out2 = mix_612;
			t_sample out3 = ((int)0);
			t_sample out5 = rTrimmed;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			(*(__out4++)) = out4;
			(*(__out5++)) = out5;
			
		};
		return __exception;
		
	};
	inline void set_n_DOWNSAMPLEON(t_param _value) {
		m_n_DOWNSAMPLEON_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_m_DOWNSAMPLE(t_param _value) {
		m_m_DOWNSAMPLE_30 = (_value < 0 ? 0 : (_value > 99 ? 99 : _value));
	};
	inline void set_l_OUTPUT(t_param _value) {
		m_l_OUTPUT_31 = (_value < -12 ? -12 : (_value > 12 ? 12 : _value));
	};
	inline void set_k_INPUT(t_param _value) {
		m_k_INPUT_32 = (_value < -12 ? -12 : (_value > 12 ? 12 : _value));
	};
	inline void set_l_SC(t_param _value) {
		m_l_SC_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_k_LPF(t_param _value) {
		m_k_LPF_34 = (_value < 20 ? 20 : (_value > 20000 ? 20000 : _value));
	};
	inline void set_j_HPF(t_param _value) {
		m_j_HPF_35 = (_value < 20 ? 20 : (_value > 20000 ? 20000 : _value));
	};
	inline void set_i_TILT(t_param _value) {
		m_i_TILT_36 = (_value < -6 ? -6 : (_value > 6 ? 6 : _value));
	};
	inline void set_h_BITSON(t_param _value) {
		m_h_BITSON_37 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_g_BITS(t_param _value) {
		m_g_BITS_38 = (_value < 3 ? 3 : (_value > 16 ? 16 : _value));
	};
	inline void set_f_BYPASS(t_param _value) {
		m_f_BYPASS_39 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_e_CEILING(t_param _value) {
		m_e_CEILING_40 = (_value < -20 ? -20 : (_value > 6 ? 6 : _value));
	};
	inline void set_d_MODE(t_param _value) {
		m_d_MODE_41 = (_value < 0 ? 0 : (_value > 7 ? 7 : _value));
	};
	inline void set_c_DC(t_param _value) {
		m_c_DC_42 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_b_DRIVE(t_param _value) {
		m_b_DRIVE_43 = (_value < 1 ? 1 : (_value > 50 ? 50 : _value));
	};
	inline void set_a_DRYWET(t_param _value) {
		m_a_DRYWET_44 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void softclip_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample lNorm = safediv((lWithDC * dr), cell);
		t_sample rNorm = safediv((rWithDC * dr), cell);
		t_sample lCubic = (lNorm - (((lNorm * lNorm) * lNorm) * ((t_sample)0.33333333333333)));
		t_sample rCubic = (rNorm - (((rNorm * rNorm) * rNorm) * ((t_sample)0.33333333333333)));
		t_sample lLimited = (((lNorm > 0) ? 1 : ((lNorm < 0) ? -1 : 0)) * (((int)2) * ((t_sample)0.33333333333333)));
		t_sample rLimited = (((rNorm > 0) ? 1 : ((rNorm < 0) ? -1 : 0)) * (((int)2) * ((t_sample)0.33333333333333)));
		int cond_45 = (fabs(lNorm) <= ((int)1));
		t_sample lOut = (cond_45 ? lCubic : lLimited);
		int cond_46 = (fabs(rNorm) <= ((int)1));
		t_sample rOut = (cond_46 ? rCubic : rLimited);
		out1 = (lOut * cell);
		out2 = (rOut * cell);
		
	};
	inline void sigmoid_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample factor = ((-((int)1)) * dr);
		t_sample l = ((((int)2) * safediv(((int)1), (((int)1) + exp((factor * lWithDC))))) - ((int)1));
		t_sample r = ((((int)2) * safediv(((int)1), (((int)1) + exp((factor * rWithDC))))) - ((int)1));
		t_sample v_49 = (l * cell);
		t_sample min_50 = (-cell);
		t_sample lOut = ((v_49 <= min_50) ? min_50 : ((v_49 >= cell) ? cell : v_49));
		t_sample v_51 = (r * cell);
		t_sample min_52 = (-cell);
		t_sample rOut = ((v_51 <= min_52) ? min_52 : ((v_51 >= cell) ? cell : v_51));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void rectF_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample l = ((((lWithDC > 0) ? 1 : ((lWithDC < 0) ? -1 : 0)) * fabs((lWithDC * dr))) * ((t_sample)0.707));
		t_sample r = ((((rWithDC > 0) ? 1 : ((rWithDC < 0) ? -1 : 0)) * fabs((rWithDC * dr))) * ((t_sample)0.707));
		t_sample min_55 = (-cell);
		t_sample lOut = ((l <= min_55) ? min_55 : ((l >= cell) ? cell : l));
		t_sample min_56 = (-cell);
		t_sample rOut = ((r <= min_56) ? min_56 : ((r >= cell) ? cell : r));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void fuzzExp1_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		int signl = ((lWithDC > 0) ? 1 : ((lWithDC < 0) ? -1 : 0));
		int signr = ((rWithDC > 0) ? 1 : ((rWithDC < 0) ? -1 : 0));
		t_sample lScaled = fabs((lWithDC * dr));
		t_sample rScaled = fabs((rWithDC * dr));
		t_sample l = (signl * (((int)1) - exp((-lScaled))));
		t_sample r = (signr * (((int)1) - exp((-rScaled))));
		t_sample min_59 = (-cell);
		t_sample lOut = ((l <= min_59) ? min_59 : ((l >= cell) ? cell : l));
		t_sample min_60 = (-cell);
		t_sample rOut = ((r <= min_60) ? min_60 : ((r >= cell) ? cell : r));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void tangenteHiperbolica_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample v_63 = (lWithDC * dr);
		t_sample min_64 = (-cell);
		t_sample l = ((v_63 <= min_64) ? min_64 : ((v_63 >= cell) ? cell : v_63));
		t_sample v_65 = (rWithDC * dr);
		t_sample min_66 = (-cell);
		t_sample r = ((v_65 <= min_66) ? min_66 : ((v_65 >= cell) ? cell : v_65));
		t_sample lOut = safediv(tanh(l), tanh(dr));
		t_sample rOut = safediv(tanh(r), tanh(dr));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void rectH_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample lPositive = ((lWithDC < ((int)0)) ? ((int)0) : lWithDC);
		t_sample rPositive = ((rWithDC < ((int)0)) ? ((int)0) : rWithDC);
		t_sample v_69 = ((lPositive * dr) * ((t_sample)0.5));
		t_sample min_70 = (-cell);
		t_sample l = ((v_69 <= min_70) ? min_70 : ((v_69 >= cell) ? cell : v_69));
		t_sample v_71 = ((rPositive * dr) * ((t_sample)0.5));
		t_sample min_72 = (-cell);
		t_sample r = ((v_71 <= min_72) ? min_72 : ((v_71 >= cell) ? cell : v_71));
		out1 = l;
		out2 = r;
		
	};
	inline void arctangent_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample lScaled = ((lWithDC * dr) * ((int)2));
		t_sample rScaled = ((rWithDC * dr) * ((int)2));
		t_sample l = ((((int)2) * ((t_sample)0.31830988618379)) * atan(lScaled));
		t_sample r = ((((int)2) * ((t_sample)0.31830988618379)) * atan(rScaled));
		t_sample lOut = (l * cell);
		t_sample rOut = (r * cell);
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void hardClip_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample lDriven = (lWithDC * dr);
		t_sample rDriven = (rWithDC * dr);
		int cond_77 = (lDriven > cell);
		int cond_78 = (lDriven < (-cell));
		t_sample iftrue_79 = (-cell);
		t_sample iffalse_80 = (cond_78 ? iftrue_79 : lDriven);
		t_sample l = (cond_77 ? cell : iffalse_80);
		int cond_81 = (rDriven > cell);
		int cond_82 = (rDriven < (-cell));
		t_sample iftrue_83 = (-cell);
		t_sample iffalse_84 = (cond_82 ? iftrue_83 : rDriven);
		t_sample r = (cond_81 ? cell : iffalse_84);
		out1 = l;
		out2 = r;
		
	};
	inline void bitCrusher_d_d_d(t_sample inl, t_sample inr, t_sample bits, t_sample& out1, t_sample& out2) {
		t_sample steps = (safepow(((int)2), bits) - ((int)1));
		t_sample invSteps = safediv(((int)1), steps);
		t_sample l = (ceil((inl * steps)) * invSteps);
		t_sample r = (ceil((inr * steps)) * invSteps);
		out1 = l;
		out2 = r;
		
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 5;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 16; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2", "out3", "out4", "out5" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_a_DRYWET(value); break;
		case 1: self->set_b_DRIVE(value); break;
		case 2: self->set_c_DC(value); break;
		case 3: self->set_d_MODE(value); break;
		case 4: self->set_e_CEILING(value); break;
		case 5: self->set_f_BYPASS(value); break;
		case 6: self->set_g_BITS(value); break;
		case 7: self->set_h_BITSON(value); break;
		case 8: self->set_i_TILT(value); break;
		case 9: self->set_j_HPF(value); break;
		case 10: self->set_k_INPUT(value); break;
		case 11: self->set_k_LPF(value); break;
		case 12: self->set_l_OUTPUT(value); break;
		case 13: self->set_l_SC(value); break;
		case 14: self->set_m_DOWNSAMPLE(value); break;
		case 15: self->set_n_DOWNSAMPLEON(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_a_DRYWET_44; break;
		case 1: *value = self->m_b_DRIVE_43; break;
		case 2: *value = self->m_c_DC_42; break;
		case 3: *value = self->m_d_MODE_41; break;
		case 4: *value = self->m_e_CEILING_40; break;
		case 5: *value = self->m_f_BYPASS_39; break;
		case 6: *value = self->m_g_BITS_38; break;
		case 7: *value = self->m_h_BITSON_37; break;
		case 8: *value = self->m_i_TILT_36; break;
		case 9: *value = self->m_j_HPF_35; break;
		case 10: *value = self->m_k_INPUT_32; break;
		case 11: *value = self->m_k_LPF_34; break;
		case 12: *value = self->m_l_OUTPUT_31; break;
		case 13: *value = self->m_l_SC_33; break;
		case 14: *value = self->m_m_DOWNSAMPLE_30; break;
		case 15: *value = self->m_n_DOWNSAMPLEON_29; break;
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(16 * sizeof(ParamInfo));
	self->__commonstate.numparams = 16;
	// initialize parameter 0 ("m_a_DRYWET_44")
	pi = self->__commonstate.params + 0;
	pi->name = "a_DRYWET";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_a_DRYWET_44;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_b_DRIVE_43")
	pi = self->__commonstate.params + 1;
	pi->name = "b_DRIVE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_b_DRIVE_43;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 50;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_c_DC_42")
	pi = self->__commonstate.params + 2;
	pi->name = "c_DC";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_c_DC_42;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_d_MODE_41")
	pi = self->__commonstate.params + 3;
	pi->name = "d_MODE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d_MODE_41;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 7;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_e_CEILING_40")
	pi = self->__commonstate.params + 4;
	pi->name = "e_CEILING";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_e_CEILING_40;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -20;
	pi->outputmax = 6;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_f_BYPASS_39")
	pi = self->__commonstate.params + 5;
	pi->name = "f_BYPASS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_f_BYPASS_39;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_g_BITS_38")
	pi = self->__commonstate.params + 6;
	pi->name = "g_BITS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_g_BITS_38;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 3;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_h_BITSON_37")
	pi = self->__commonstate.params + 7;
	pi->name = "h_BITSON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_h_BITSON_37;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_i_TILT_36")
	pi = self->__commonstate.params + 8;
	pi->name = "i_TILT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_i_TILT_36;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -6;
	pi->outputmax = 6;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_j_HPF_35")
	pi = self->__commonstate.params + 9;
	pi->name = "j_HPF";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_j_HPF_35;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 20;
	pi->outputmax = 20000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_k_INPUT_32")
	pi = self->__commonstate.params + 10;
	pi->name = "k_INPUT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_k_INPUT_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -12;
	pi->outputmax = 12;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_k_LPF_34")
	pi = self->__commonstate.params + 11;
	pi->name = "k_LPF";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_k_LPF_34;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 20;
	pi->outputmax = 20000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_l_OUTPUT_31")
	pi = self->__commonstate.params + 12;
	pi->name = "l_OUTPUT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_l_OUTPUT_31;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -12;
	pi->outputmax = 12;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_l_SC_33")
	pi = self->__commonstate.params + 13;
	pi->name = "l_SC";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_l_SC_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_m_DOWNSAMPLE_30")
	pi = self->__commonstate.params + 14;
	pi->name = "m_DOWNSAMPLE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_m_DOWNSAMPLE_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_n_DOWNSAMPLEON_29")
	pi = self->__commonstate.params + 15;
	pi->name = "n_DOWNSAMPLEON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_n_DOWNSAMPLEON_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // JCBDistortion::

#include "GEN_DSP.h"

namespace GEN_DSP {

/*******************************************************************************************************************
Cycling '74 License for Max-Generated Code for Export
Copyright (c) 2016 Cycling '74
The code that Max generates automatically and that end users are capable of exporting and using, and any
  associated documentation files (the “Software”) is a work of authorship for which Cycling '74 is the author
  and owner for copyright purposes.  A license is hereby granted, free of charge, to any person obtaining a
  copy of the Software (“Licensee”) to use, copy, modify, merge, publish, and distribute copies of the Software,
  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The Software is licensed to Licensee only for non-commercial use. Users who wish to make commercial use of the
  Software must contact the copyright owner to determine if a license for commercial use is available, and the
  terms and conditions for same, which may include fees or royalties. For commercial use, please send inquiries
  to licensing (at) cycling74.com.  The determination of whether a use is commercial use or non-commercial use is based
  upon the use, not the user. The Software may be used by individuals, institutions, governments, corporations, or
  other business whether for-profit or non-profit so long as the use itself is not a commercialization of the
  materials or a use that generates or is intended to generate income, revenue, sales or profit.
The above copyright notice and this license shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
  THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  DEALINGS IN THE SOFTWARE.
*******************************************************************************************************************/

// global noise generator
//Noise noise;
//static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	DCBlock __m_dcblock_64;
	DCBlock __m_dcblock_59;
	DCBlock __m_dcblock_60;
	DCBlock __m_dcblock_63;
	int __exception;
	int vectorsize;
	t_sample m_history_3;
	t_sample m_f_bypass_25;
	t_sample m_i_tilt_26;
	t_sample m_j_gain_27;
	t_sample m_c_dc_24;
	t_sample m_history_22;
	t_sample m_history_23;
	t_sample m_history_21;
	t_sample m_b_drive_28;
	t_sample m_d_mode_30;
	t_sample samplerate;
	t_sample m_h_bitsOn_29;
	t_sample m_g_bits_33;
	t_sample m_a_drywet_31;
	t_sample m_e_celling_32;
	t_sample m_history_2;
	t_sample m_history_20;
	t_sample m_history_18;
	t_sample m_history_7;
	t_sample m_history_8;
	t_sample m_history_9;
	t_sample m_history_6;
	t_sample m_history_4;
	t_sample m_history_5;
	t_sample m_history_19;
	t_sample m_history_10;
	t_sample m_history_12;
	t_sample m_history_16;
	t_sample m_history_1;
	t_sample m_history_11;
	t_sample m_history_15;
	t_sample m_history_13;
	t_sample m_history_14;
	t_sample m_history_17;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_history_5 = ((int)0);
		m_history_6 = ((int)0);
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_history_10 = ((int)0);
		m_history_11 = ((int)0);
		m_history_12 = ((int)0);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_history_20 = ((int)0);
		m_history_21 = ((int)0);
		m_history_22 = ((int)0);
		m_history_23 = ((int)0);
		m_c_dc_24 = 0;
		m_f_bypass_25 = 0;
		m_i_tilt_26 = 0;
		m_j_gain_27 = 0;
		m_b_drive_28 = 1;
		m_h_bitsOn_29 = 0;
		m_d_mode_30 = 1;
		m_a_drywet_31 = 1;
		m_e_celling_32 = 0;
		m_g_bits_33 = 24;
		__m_dcblock_59.reset();
		__m_dcblock_60.reset();
		__m_dcblock_63.reset();
		__m_dcblock_64.reset();
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample mul_457 = (m_b_drive_28 * ((t_sample)0.001));
		t_sample dbtoa_419 = dbtoa(m_e_celling_32);
		t_sample rsub_401 = (((int)1) - m_f_bypass_25);
		t_sample mul_447 = (m_c_dc_24 * ((t_sample)0.0001));
		t_sample setparam_13 = m_i_tilt_26;
		int min_34 = (-12);
		t_sample gain = ((setparam_13 <= min_34) ? min_34 : ((setparam_13 >= ((int)12)) ? ((int)12) : setparam_13));
		t_sample mul_15 = (gain * ((t_sample)0.001));
		t_sample omega = safediv(((t_sample)5026.5482457437), samplerate);
		t_sample sn = sin(omega);
		t_sample cs = cos(omega);
		t_sample omega_228 = safediv(((t_sample)5026.5482457437), samplerate);
		t_sample sn_232 = sin(omega_228);
		t_sample cs_225 = cos(omega_228);
		t_sample omega_235 = safediv(((t_sample)5026.5482457437), samplerate);
		t_sample sn_238 = sin(omega_235);
		t_sample cs_243 = cos(omega_235);
		t_sample omega_248 = safediv(((t_sample)5026.5482457437), samplerate);
		t_sample sn_251 = sin(omega_248);
		t_sample cs_246 = cos(omega_248);
		t_sample mul_268 = (m_g_bits_33 * ((t_sample)0.001));
		t_sample mul_259 = (m_h_bitsOn_29 * ((t_sample)0.001));
		t_sample mul_465 = (m_a_drywet_31 * ((t_sample)0.001));
		t_sample mul_5 = (m_j_gain_27 * ((t_sample)0.001));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			int expr_6427 = ((int)0);
			int expr_6428 = ((int)0);
			int expr_6424 = ((int)0);
			int expr_6425 = ((int)0);
			int expr_6426 = ((int)0);
			if ((m_d_mode_30 == ((int)1))) {
				expr_6424 = ((int)1);
				
			} else {
				expr_6424 = ((int)0);
				
			};
			if ((m_d_mode_30 == ((int)2))) {
				expr_6425 = ((int)1);
				
			} else {
				expr_6425 = ((int)0);
				
			};
			if ((m_d_mode_30 == ((int)3))) {
				expr_6426 = ((int)1);
				
			} else {
				expr_6426 = ((int)0);
				
			};
			if ((m_d_mode_30 == ((int)4))) {
				expr_6427 = ((int)1);
				
			} else {
				expr_6427 = ((int)0);
				
			};
			if ((m_d_mode_30 == ((int)5))) {
				expr_6428 = ((int)1);
				
			} else {
				expr_6428 = ((int)0);
				
			};
			t_sample mul_456 = (m_history_23 * ((t_sample)0.999));
			t_sample add_459 = (mul_457 + mul_456);
			t_sample gen_463 = add_459;
			t_sample history_458_next_462 = fixdenorm(add_459);
			t_sample l_403 = in1;
			t_sample r_402 = in2;
			t_sample mul_525 = (gen_463 * ((t_sample)0.9));
			t_sample mul_446 = (m_history_22 * ((t_sample)0.9999));
			t_sample add_449 = (mul_447 + mul_446);
			t_sample gen_453 = add_449;
			t_sample history_448_next_452 = fixdenorm(add_449);
			t_sample mul_473 = (mul_525 * gen_453);
			t_sample mul_14 = (m_history_21 * ((t_sample)0.999));
			t_sample add_17 = (mul_15 + mul_14);
			t_sample gen_21 = add_17;
			t_sample history_16_next_20 = fixdenorm(add_17);
			t_sample dbtoa_105 = dbtoa(gen_21);
			t_sample rdiv_23 = safediv(((int)1), dbtoa_105);
			t_sample min_70 = ((rdiv_23 < ((int)0)) ? ((int)0) : rdiv_23);
			t_sample A = sqrt(min_70);
			t_sample beta = sqrt(((((A * A) + ((int)1)) * ((t_sample)1.4142271248763)) - ((A - ((int)1)) * (A - ((int)1)))));
			t_sample b0 = safediv(((int)1), (((A + ((int)1)) + ((A - ((int)1)) * cs)) + (beta * sn)));
			t_sample a0 = ((A * (((A + ((int)1)) - ((A - ((int)1)) * cs)) + (beta * sn))) * b0);
			t_sample a1 = (((((int)2) * A) * ((A - ((int)1)) - ((A + ((int)1)) * cs))) * b0);
			t_sample a2 = ((A * (((A + ((int)1)) - ((A - ((int)1)) * cs)) - (beta * sn))) * b0);
			t_sample b1 = ((((int)-2) * ((A - ((int)1)) + ((A + ((int)1)) * cs))) * b0);
			t_sample b2 = ((((A + ((int)1)) + ((A - ((int)1)) * cs)) - (beta * sn)) * b0);
			t_sample expr_98 = a0;
			t_sample expr_99 = a1;
			t_sample expr_100 = a2;
			t_sample expr_101 = b1;
			t_sample expr_102 = b2;
			t_sample mul_81 = (in2 * expr_98);
			t_sample mul_78 = (m_history_18 * expr_99);
			t_sample mul_76 = (m_history_20 * expr_100);
			t_sample mul_72 = (m_history_19 * expr_102);
			t_sample mul_74 = (m_history_17 * expr_101);
			t_sample sub_80 = (((mul_76 + mul_78) + mul_81) - (mul_74 + mul_72));
			t_sample gen_91 = sub_80;
			t_sample history_77_next_87 = fixdenorm(m_history_18);
			t_sample history_73_next_88 = fixdenorm(m_history_17);
			t_sample history_79_next_89 = fixdenorm(in2);
			t_sample history_75_next_90 = fixdenorm(sub_80);
			t_sample gen_103 = gen_91;
			t_sample min_30 = ((dbtoa_105 < ((int)0)) ? ((int)0) : dbtoa_105);
			t_sample A_226 = sqrt(min_30);
			t_sample beta_227 = sqrt(((((A_226 * A_226) + ((int)1)) * ((t_sample)1.4142271248763)) - ((A_226 - ((int)1)) * (A_226 - ((int)1)))));
			t_sample b_222 = safediv(((int)1), (((A_226 + ((int)1)) - ((A_226 - ((int)1)) * cs_225)) + (beta_227 * sn_232)));
			t_sample a_224 = ((A_226 * (((A_226 + ((int)1)) + ((A_226 - ((int)1)) * cs_225)) + (beta_227 * sn_232))) * b_222);
			t_sample a_230 = (((((int)-2) * A_226) * ((A_226 - ((int)1)) + ((A_226 + ((int)1)) * cs_225))) * b_222);
			t_sample a_223 = ((A_226 * (((A_226 + ((int)1)) + ((A_226 - ((int)1)) * cs_225)) - (beta_227 * sn_232))) * b_222);
			t_sample b_229 = ((((int)2) * ((A_226 - ((int)1)) - ((A_226 + ((int)1)) * cs_225))) * b_222);
			t_sample b_231 = ((((A_226 + ((int)1)) - ((A_226 - ((int)1)) * cs_225)) - (beta_227 * sn_232)) * b_222);
			t_sample expr_58 = a_224;
			t_sample expr_59 = a_230;
			t_sample expr_60 = a_223;
			t_sample expr_61 = b_229;
			t_sample expr_62 = b_231;
			t_sample mul_41 = (gen_103 * expr_58);
			t_sample mul_38 = (m_history_14 * expr_59);
			t_sample mul_36 = (m_history_16 * expr_60);
			t_sample mul_32 = (m_history_15 * expr_62);
			t_sample mul_34 = (m_history_13 * expr_61);
			t_sample sub_40 = (((mul_36 + mul_38) + mul_41) - (mul_34 + mul_32));
			t_sample gen_51 = sub_40;
			t_sample history_37_next_47 = fixdenorm(m_history_14);
			t_sample history_33_next_48 = fixdenorm(m_history_13);
			t_sample history_39_next_49 = fixdenorm(gen_103);
			t_sample history_35_next_50 = fixdenorm(sub_40);
			t_sample rdiv_104 = safediv(((int)1), dbtoa_105);
			t_sample min_153 = ((rdiv_104 < ((int)0)) ? ((int)0) : rdiv_104);
			t_sample A_242 = sqrt(min_153);
			t_sample beta_234 = sqrt(((((A_242 * A_242) + ((int)1)) * ((t_sample)1.4142271248763)) - ((A_242 - ((int)1)) * (A_242 - ((int)1)))));
			t_sample b_240 = safediv(((int)1), (((A_242 + ((int)1)) + ((A_242 - ((int)1)) * cs_243)) + (beta_234 * sn_238)));
			t_sample a_239 = ((A_242 * (((A_242 + ((int)1)) - ((A_242 - ((int)1)) * cs_243)) + (beta_234 * sn_238))) * b_240);
			t_sample a_237 = (((((int)2) * A_242) * ((A_242 - ((int)1)) - ((A_242 + ((int)1)) * cs_243))) * b_240);
			t_sample a_233 = ((A_242 * (((A_242 + ((int)1)) - ((A_242 - ((int)1)) * cs_243)) - (beta_234 * sn_238))) * b_240);
			t_sample b_236 = ((((int)-2) * ((A_242 - ((int)1)) + ((A_242 + ((int)1)) * cs_243))) * b_240);
			t_sample b_241 = ((((A_242 + ((int)1)) + ((A_242 - ((int)1)) * cs_243)) - (beta_234 * sn_238)) * b_240);
			t_sample expr_181 = a_239;
			t_sample expr_182 = a_237;
			t_sample expr_183 = a_233;
			t_sample expr_184 = b_236;
			t_sample expr_185 = b_241;
			t_sample mul_164 = (in1 * expr_181);
			t_sample mul_161 = (m_history_10 * expr_182);
			t_sample mul_159 = (m_history_11 * expr_183);
			t_sample mul_155 = (m_history_12 * expr_185);
			t_sample mul_157 = (m_history_9 * expr_184);
			t_sample sub_163 = (((mul_159 + mul_161) + mul_164) - (mul_157 + mul_155));
			t_sample gen_174 = sub_163;
			t_sample history_156_next_170 = fixdenorm(m_history_9);
			t_sample history_160_next_171 = fixdenorm(m_history_10);
			t_sample history_162_next_172 = fixdenorm(in1);
			t_sample history_158_next_173 = fixdenorm(sub_163);
			t_sample gen_186 = gen_174;
			t_sample min_113 = ((dbtoa_105 < ((int)0)) ? ((int)0) : dbtoa_105);
			t_sample A_254 = sqrt(min_113);
			t_sample beta_247 = sqrt(((((A_254 * A_254) + ((int)1)) * ((t_sample)1.4142271248763)) - ((A_254 - ((int)1)) * (A_254 - ((int)1)))));
			t_sample b_252 = safediv(((int)1), (((A_254 + ((int)1)) - ((A_254 - ((int)1)) * cs_246)) + (beta_247 * sn_251)));
			t_sample a_253 = ((A_254 * (((A_254 + ((int)1)) + ((A_254 - ((int)1)) * cs_246)) + (beta_247 * sn_251))) * b_252);
			t_sample a_250 = (((((int)-2) * A_254) * ((A_254 - ((int)1)) + ((A_254 + ((int)1)) * cs_246))) * b_252);
			t_sample a_244 = ((A_254 * (((A_254 + ((int)1)) + ((A_254 - ((int)1)) * cs_246)) - (beta_247 * sn_251))) * b_252);
			t_sample b_249 = ((((int)2) * ((A_254 - ((int)1)) - ((A_254 + ((int)1)) * cs_246))) * b_252);
			t_sample b_245 = ((((A_254 + ((int)1)) - ((A_254 - ((int)1)) * cs_246)) - (beta_247 * sn_251)) * b_252);
			t_sample expr_141 = a_253;
			t_sample expr_142 = a_250;
			t_sample expr_143 = a_244;
			t_sample expr_144 = b_249;
			t_sample expr_145 = b_245;
			t_sample mul_124 = (gen_186 * expr_141);
			t_sample mul_121 = (m_history_6 * expr_142);
			t_sample mul_119 = (m_history_8 * expr_143);
			t_sample mul_115 = (m_history_7 * expr_145);
			t_sample mul_117 = (m_history_5 * expr_144);
			t_sample sub_123 = (((mul_119 + mul_121) + mul_124) - (mul_117 + mul_115));
			t_sample gen_134 = sub_123;
			t_sample history_120_next_130 = fixdenorm(m_history_6);
			t_sample history_116_next_131 = fixdenorm(m_history_5);
			t_sample history_122_next_132 = fixdenorm(gen_186);
			t_sample history_118_next_133 = fixdenorm(sub_123);
			t_sample mix_6486 = (((int)0) + (expr_6425 * (gen_51 - ((int)0))));
			t_sample mix_6487 = (((int)0) + (expr_6424 * (gen_51 - ((int)0))));
			t_sample mix_6488 = (((int)0) + (expr_6427 * (gen_51 - ((int)0))));
			t_sample mix_6489 = (((int)0) + (expr_6428 * (gen_51 - ((int)0))));
			t_sample mix_6490 = (((int)0) + (expr_6426 * (gen_51 - ((int)0))));
			t_sample mix_6495 = (((int)0) + (expr_6426 * (gen_134 - ((int)0))));
			t_sample return_39;
			t_sample return_40;
			rectF_d_d_d_d(mix_6495, mix_6490, gen_463, dbtoa_419, return_39, return_40);
			t_sample expr_6450 = return_39;
			t_sample expr_6451 = return_40;
			t_sample mix_6496 = (((int)0) + (expr_6424 * (gen_134 - ((int)0))));
			t_sample return_43;
			t_sample return_44;
			softclip_d_d_d((mix_6496 * (gen_463 + mul_473)), (mix_6487 * (gen_463 + mul_473)), dbtoa_419, return_43, return_44);
			t_sample expr_6446 = return_43;
			t_sample expr_6447 = return_44;
			t_sample mix_6497 = (((int)0) + (expr_6425 * (gen_134 - ((int)0))));
			t_sample return_49;
			t_sample return_50;
			rectH_d_d_d_d(mix_6497, mix_6486, gen_463, dbtoa_419, return_49, return_50);
			t_sample expr_6448 = return_49;
			t_sample expr_6449 = return_50;
			t_sample mix_6498 = (((int)0) + (expr_6427 * (gen_134 - ((int)0))));
			t_sample return_53;
			t_sample return_54;
			fuzzExp1_d_d_d_d_d(mix_6498, mix_6488, gen_463, mul_473, dbtoa_419, return_53, return_54);
			t_sample expr_6454 = return_53;
			t_sample expr_6455 = return_54;
			t_sample mix_6499 = (((int)0) + (expr_6428 * (gen_134 - ((int)0))));
			t_sample return_57;
			t_sample return_58;
			fuzzExp2_d_d_d_d_d(mix_6499, mix_6489, gen_463, mul_473, dbtoa_419, return_57, return_58);
			t_sample expr_6460 = return_57;
			t_sample expr_6461 = return_58;
			t_sample mul_267 = (m_history_4 * ((t_sample)0.999));
			t_sample add_270 = (mul_268 + mul_267);
			t_sample gen_274 = add_270;
			t_sample history_269_next_273 = fixdenorm(add_270);
			t_sample mul_258 = (m_history_3 * ((t_sample)0.999));
			t_sample add_261 = (mul_259 + mul_258);
			t_sample gen_265 = add_261;
			t_sample history_260_next_264 = fixdenorm(add_261);
			t_sample mul_464 = (m_history_2 * ((t_sample)0.999));
			t_sample add_467 = (mul_465 + mul_464);
			t_sample gen_471 = add_467;
			t_sample history_466_next_470 = fixdenorm(add_467);
			t_sample toL_438 = ((((expr_6460 + expr_6454) + expr_6450) + expr_6448) + expr_6446);
			t_sample dcblock_2446 = __m_dcblock_59(toL_438);
			t_sample toR_437 = ((((expr_6461 + expr_6455) + expr_6451) + expr_6449) + expr_6447);
			t_sample dcblock_2571 = __m_dcblock_60(toR_437);
			t_sample mul_4 = (m_history_1 * ((t_sample)0.999));
			t_sample add_7 = (mul_5 + mul_4);
			t_sample gen_11 = add_7;
			t_sample history_6_next_10 = fixdenorm(add_7);
			t_sample dbtoa_12 = dbtoa(gen_11);
			t_sample mul_2 = (dcblock_2446 * dbtoa_12);
			t_sample mix_6504 = (l_403 + (gen_471 * (mul_2 - l_403)));
			t_sample mul_1 = (dcblock_2571 * dbtoa_12);
			t_sample mix_6505 = (r_402 + (gen_471 * (mul_1 - r_402)));
			t_sample return_61;
			t_sample return_62;
			bitCrusher_d_d_d(mix_6504, mix_6505, gen_274, return_61, return_62);
			t_sample expr_2132 = return_61;
			t_sample expr_2133 = return_62;
			t_sample dcblock_2065 = __m_dcblock_63(expr_2133);
			t_sample mix_6506 = (mix_6505 + (gen_265 * (dcblock_2065 - mix_6505)));
			t_sample dcblock_1932 = __m_dcblock_64(expr_2132);
			t_sample mix_6507 = (mix_6504 + (gen_265 * (dcblock_1932 - mix_6504)));
			t_sample mix_6508 = (l_403 + (rsub_401 * (mix_6507 - l_403)));
			t_sample out1 = mix_6508;
			t_sample mix_6509 = (r_402 + (rsub_401 * (mix_6506 - r_402)));
			t_sample out2 = mix_6509;
			m_history_23 = history_458_next_462;
			m_history_22 = history_448_next_452;
			m_history_21 = history_16_next_20;
			m_history_5 = history_118_next_133;
			m_history_6 = history_122_next_132;
			m_history_7 = history_116_next_131;
			m_history_8 = history_120_next_130;
			m_history_9 = history_158_next_173;
			m_history_10 = history_162_next_172;
			m_history_11 = history_160_next_171;
			m_history_12 = history_156_next_170;
			m_history_13 = history_35_next_50;
			m_history_14 = history_39_next_49;
			m_history_15 = history_33_next_48;
			m_history_16 = history_37_next_47;
			m_history_17 = history_75_next_90;
			m_history_18 = history_79_next_89;
			m_history_19 = history_73_next_88;
			m_history_20 = history_77_next_87;
			m_history_4 = history_269_next_273;
			m_history_3 = history_260_next_264;
			m_history_2 = history_466_next_470;
			m_history_1 = history_6_next_10;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			
		};
		return __exception;
		
	};
	inline void set_c_dc(t_param _value) {
		m_c_dc_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_f_bypass(t_param _value) {
		m_f_bypass_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_i_tilt(t_param _value) {
		m_i_tilt_26 = (_value < -12 ? -12 : (_value > 12 ? 12 : _value));
	};
	inline void set_j_gain(t_param _value) {
		m_j_gain_27 = (_value < -20 ? -20 : (_value > 6 ? 6 : _value));
	};
	inline void set_b_drive(t_param _value) {
		m_b_drive_28 = (_value < 1 ? 1 : (_value > 50 ? 50 : _value));
	};
	inline void set_h_bitsOn(t_param _value) {
		m_h_bitsOn_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_d_mode(t_param _value) {
		m_d_mode_30 = (_value < 1 ? 1 : (_value > 10 ? 10 : _value));
	};
	inline void set_a_drywet(t_param _value) {
		m_a_drywet_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_e_celling(t_param _value) {
		m_e_celling_32 = (_value < -20 ? -20 : (_value > 6 ? 6 : _value));
	};
	inline void set_g_bits(t_param _value) {
		m_g_bits_33 = (_value < 1 ? 1 : (_value > 24 ? 24 : _value));
	};
	inline void rectF_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample v_35 = fabs(((inl * dr) * ((t_sample)0.5)));
		t_sample min_36 = (-cell);
		t_sample l = ((v_35 <= min_36) ? min_36 : ((v_35 >= cell) ? cell : v_35));
		t_sample v_37 = fabs(((inr * dr) * ((t_sample)0.5)));
		t_sample min_38 = (-cell);
		t_sample r = ((v_37 <= min_38) ? min_38 : ((v_37 >= cell) ? cell : v_37));
		out1 = l;
		out2 = r;
		
	};
	inline void softclip_d_d_d(t_sample inl, t_sample inr, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample min_41 = (-cell);
		t_sample l = ((inl <= min_41) ? min_41 : ((inl >= cell) ? cell : inl));
		t_sample min_42 = (-cell);
		t_sample r = ((inr <= min_42) ? min_42 : ((inr >= cell) ? cell : inr));
		t_sample l_6444 = ((((int)2) * ((t_sample)0.31830988618379)) * tanh(l));
		t_sample r_6445 = ((((int)2) * ((t_sample)0.31830988618379)) * tanh(r));
		out1 = l_6444;
		out2 = r_6445;
		
	};
	inline void rectH_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample cell, t_sample& out1, t_sample& out2) {
		if ((inl < ((int)0))) {
			inl = ((int)0);
			
		};
		if ((inr < ((int)0))) {
			inr = ((int)0);
			
		};
		t_sample v_45 = ((inl * dr) * ((t_sample)0.5));
		t_sample min_46 = (-cell);
		t_sample l = ((v_45 <= min_46) ? min_46 : ((v_45 >= cell) ? cell : v_45));
		t_sample v_47 = ((inr * dr) * ((t_sample)0.5));
		t_sample min_48 = (-cell);
		t_sample r = ((v_47 <= min_48) ? min_48 : ((v_47 >= cell) ? cell : v_47));
		out1 = l;
		out2 = r;
		
	};
	inline void fuzzExp1_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		int signl = ((int)0);
		int signr = ((int)0);
		if ((inl < ((int)0))) {
			signl = (-((int)1));
			
		} else {
			signl = ((int)1);
			
		};
		if ((inr < ((int)0))) {
			signr = (-((int)1));
			
		} else {
			signr = ((int)1);
			
		};
		t_sample l = (signl * safediv((((int)1) - exp(((-((int)1)) * fabs(((inl * (dr * ((t_sample)0.16666666666667))) + (dc * ((t_sample)0.01))))))), (((int)1) - exp((((-((int)1)) * (dr * ((t_sample)0.16666666666667))) + (dc * ((t_sample)0.01)))))));
		t_sample r = (signr * safediv((((int)1) - exp(((-((int)1)) * fabs(((inr * (dr * ((t_sample)0.16666666666667))) + (dc * ((t_sample)0.01))))))), (((int)1) - exp((((-((int)1)) * (dr * ((t_sample)0.16666666666667))) + (dc * ((t_sample)0.01)))))));
		t_sample min_51 = (-cell);
		t_sample l_6452 = ((l <= min_51) ? min_51 : ((l >= cell) ? cell : l));
		t_sample min_52 = (-cell);
		t_sample r_6453 = ((r <= min_52) ? min_52 : ((r >= cell) ? cell : r));
		out1 = l_6452;
		out2 = r_6453;
		
	};
	inline void fuzzExp2_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		int signl = ((int)0);
		int signr = ((int)0);
		if ((inl < ((int)0))) {
			signl = (-((int)1));
			
		} else {
			signl = ((int)1);
			
		};
		if ((inr < ((int)0))) {
			signr = (-((int)1));
			
		} else {
			signr = ((int)1);
			
		};
		t_sample l = (inl * ((t_sample)0.1));
		t_sample r = (inr * ((t_sample)0.1));
		t_sample l_6456 = ((signl * ((((-((int)1)) * l) * dr) + (dc * ((t_sample)0.005)))) * (((int)1) - safediv(exp(fabs(l)), (exp(((int)0)) - ((int)1)))));
		t_sample r_6457 = ((signr * ((((-((int)1)) * r) * dr) + (dc * ((t_sample)0.005)))) * (((int)1) - safediv(exp(fabs(r)), (exp(((int)0)) - ((int)1)))));
		t_sample min_55 = (-cell);
		t_sample l_6458 = ((l_6456 <= min_55) ? min_55 : ((l_6456 >= cell) ? cell : l_6456));
		t_sample min_56 = (-cell);
		t_sample r_6459 = ((r_6457 <= min_56) ? min_56 : ((r_6457 >= cell) ? cell : r_6457));
		out1 = l_6458;
		out2 = r_6459;
		
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
int gen_kernel_numouts = 2;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 10; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2" };

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
		case 0: self->set_a_drywet(value); break;
		case 1: self->set_b_drive(value); break;
		case 2: self->set_c_dc(value); break;
		case 3: self->set_d_mode(value); break;
		case 4: self->set_e_celling(value); break;
		case 5: self->set_f_bypass(value); break;
		case 6: self->set_g_bits(value); break;
		case 7: self->set_h_bitsOn(value); break;
		case 8: self->set_i_tilt(value); break;
		case 9: self->set_j_gain(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_a_drywet_31; break;
		case 1: *value = self->m_b_drive_28; break;
		case 2: *value = self->m_c_dc_24; break;
		case 3: *value = self->m_d_mode_30; break;
		case 4: *value = self->m_e_celling_32; break;
		case 5: *value = self->m_f_bypass_25; break;
		case 6: *value = self->m_g_bits_33; break;
		case 7: *value = self->m_h_bitsOn_29; break;
		case 8: *value = self->m_i_tilt_26; break;
		case 9: *value = self->m_j_gain_27; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(10 * sizeof(ParamInfo));
	self->__commonstate.numparams = 10;
	// initialize parameter 0 ("m_a_drywet_31")
	pi = self->__commonstate.params + 0;
	pi->name = "a_drywet";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_a_drywet_31;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_b_drive_28")
	pi = self->__commonstate.params + 1;
	pi->name = "b_drive";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_b_drive_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 50;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_c_dc_24")
	pi = self->__commonstate.params + 2;
	pi->name = "c_dc";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_c_dc_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_d_mode_30")
	pi = self->__commonstate.params + 3;
	pi->name = "d_mode";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d_mode_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 10;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_e_celling_32")
	pi = self->__commonstate.params + 4;
	pi->name = "e_celling";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_e_celling_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -20;
	pi->outputmax = 6;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_f_bypass_25")
	pi = self->__commonstate.params + 5;
	pi->name = "f_bypass";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_f_bypass_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_g_bits_33")
	pi = self->__commonstate.params + 6;
	pi->name = "g_bits";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_g_bits_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 24;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_h_bitsOn_29")
	pi = self->__commonstate.params + 7;
	pi->name = "h_bitsOn";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_h_bitsOn_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_i_tilt_26")
	pi = self->__commonstate.params + 8;
	pi->name = "i_tilt";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_i_tilt_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -12;
	pi->outputmax = 12;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_j_gain_27")
	pi = self->__commonstate.params + 9;
	pi->name = "j_gain";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_j_gain_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -20;
	pi->outputmax = 6;
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


} // GEN_DSP::

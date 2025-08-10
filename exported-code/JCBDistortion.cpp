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
	DCBlock __m_dcblock_382;
	DCBlock __m_dcblock_373;
	DCBlock __m_dcblock_372;
	DCBlock __m_dcblock_376;
	DCBlock __m_dcblock_377;
	DCBlock __m_dcblock_381;
	int __exception;
	int vectorsize;
	Phasor __m_phasor_378;
	t_sample m_R_m1_y_204;
	t_sample m_R_m1_y_203;
	t_sample m_R_m2_x_202;
	t_sample m_R_m2_y_201;
	t_sample m_R_ap2_lp2_x_5;
	t_sample m_R_h2_y_206;
	t_sample m_R_m1_x_205;
	t_sample m_R_h2_y_207;
	t_sample m_R_m2_y_200;
	t_sample m_R_u1_x_199;
	t_sample m_R_u1_y_198;
	t_sample m_R_u2_y_194;
	t_sample m_R_ap_low_lp1_x_193;
	t_sample m_R_h2_x_208;
	t_sample m_R_u2_y_195;
	t_sample m_R_u1_y_197;
	t_sample m_R_u2_x_196;
	t_sample m_R_h1_y_209;
	t_sample m_R_h1_y_210;
	t_sample m_R_h1_x_211;
	t_sample m_L_ap2_hp1_y_222;
	t_sample m_L_ap2_hp1_y_221;
	t_sample m_L_ap2_hp2_x_220;
	t_sample m_L_ap2_hp1_x_223;
	t_sample m_L_ap2_lp2_y_225;
	t_sample m_L_ap2_lp2_y_224;
	t_sample m_L_ap2_lp2_x_226;
	t_sample m_R_ap_low_lp1_y_192;
	t_sample m_L_ap2_hp2_y_219;
	t_sample m_R_l1_x_217;
	t_sample m_R_l2_y_213;
	t_sample m_R_l2_y_212;
	t_sample m_L_ap2_hp2_y_218;
	t_sample m_R_l2_x_214;
	t_sample m_R_l1_y_216;
	t_sample m_R_l1_y_215;
	t_sample m_R_ap_low_lp1_y_191;
	t_sample m_R_ap_low_lp2_x_190;
	t_sample m_R_ap_low_lp2_y_189;
	t_sample m_R_ap2_lp2_x_166;
	t_sample m_R_ap2_lp2_y_165;
	t_sample m_R_ap2_lp2_y_164;
	t_sample m_R_ap2_lp1_y_167;
	t_sample m_R_ap2_lp1_x_169;
	t_sample m_R_ap2_lp1_y_168;
	t_sample m_R_ap1_hp2_y_170;
	t_sample m_R_ap1_hp2_y_171;
	t_sample m_R_ap2_hp1_x_163;
	t_sample m_R_ap2_hp1_y_161;
	t_sample m_l1_x_157;
	t_sample m_l1_x_156;
	t_sample m_R_ap2_hp1_y_162;
	t_sample m_R_ap2_hp2_y_158;
	t_sample m_R_ap2_hp2_x_160;
	t_sample m_R_ap2_hp2_y_159;
	t_sample m_L_ap2_lp1_y_227;
	t_sample m_R_ap1_hp2_x_172;
	t_sample m_R_ap1_hp1_y_174;
	t_sample m_R_ap_low_hp1_y_185;
	t_sample m_R_ap_low_hp2_x_184;
	t_sample m_R_ap_low_hp2_y_183;
	t_sample m_R_ap_low_hp1_y_186;
	t_sample m_R_ap_low_lp2_y_188;
	t_sample m_R_ap_low_hp1_x_187;
	t_sample m_R_ap1_hp1_y_173;
	t_sample m_R_ap_low_hp2_y_182;
	t_sample m_R_ap1_lp1_y_180;
	t_sample m_R_ap1_lp2_y_176;
	t_sample m_R_ap1_hp1_x_175;
	t_sample m_R_ap1_lp1_x_181;
	t_sample m_R_ap1_lp2_y_177;
	t_sample m_R_ap1_lp1_y_179;
	t_sample m_R_ap1_lp2_x_178;
	t_sample m_L_ap2_lp1_y_228;
	t_sample m_L_ap2_lp1_x_229;
	t_sample m_L_ap1_hp2_y_230;
	t_sample m_o_BAND_278;
	t_sample m_L_l1_x_277;
	t_sample m_L_l1_y_276;
	t_sample m_n_DOWNSAMPLEON_279;
	t_sample m_l_OUTPUT_281;
	t_sample m_m_DOWNSAMPLE_280;
	t_sample m_k_INPUT_282;
	t_sample m_l_SC_283;
	t_sample m_L_l1_y_275;
	t_sample m_L_l2_y_273;
	t_sample m_L_h1_y_269;
	t_sample m_L_h2_x_268;
	t_sample m_L_l2_x_274;
	t_sample m_L_h1_y_270;
	t_sample m_L_l2_y_272;
	t_sample m_L_h1_x_271;
	t_sample m_L_h2_y_267;
	t_sample m_k_LPF_284;
	t_sample m_i_TILT_286;
	t_sample samplerate;
	t_sample m_R_ap2_hp2_x_1;
	t_sample m_L_ap2_hp2_x_2;
	t_sample samples_to_seconds;
	t_sample __m_latch_380;
	t_sample __m_latch_379;
	t_sample m_j_HPF_285;
	t_sample m_a_DRYWET_294;
	t_sample m_c_DC_292;
	t_sample m_g_BITS_288;
	t_sample m_h_BITSON_287;
	t_sample m_b_DRIVE_293;
	t_sample m_f_BYPASS_289;
	t_sample m_d_MODE_291;
	t_sample m_e_CEILING_290;
	t_sample m_l1_y_155;
	t_sample m_L_h2_y_266;
	t_sample m_L_m1_y_264;
	t_sample m_L_ap1_lp1_x_241;
	t_sample m_L_ap1_lp1_y_240;
	t_sample m_L_ap1_lp1_y_239;
	t_sample m_L_ap_low_hp2_y_242;
	t_sample m_L_ap_low_hp2_x_244;
	t_sample m_L_ap_low_hp2_y_243;
	t_sample m_L_ap_low_hp1_y_245;
	t_sample m_L_ap_low_hp1_y_246;
	t_sample m_L_ap1_lp2_x_238;
	t_sample m_L_ap1_lp2_y_236;
	t_sample m_L_ap1_hp2_x_232;
	t_sample m_L_ap1_hp2_y_231;
	t_sample m_L_ap1_lp2_y_237;
	t_sample m_L_ap1_hp1_y_233;
	t_sample m_L_ap1_hp1_x_235;
	t_sample m_L_ap1_hp1_y_234;
	t_sample m_L_m1_x_265;
	t_sample m_L_ap_low_hp1_x_247;
	t_sample m_L_ap_low_lp2_y_249;
	t_sample m_L_m2_y_260;
	t_sample m_L_u1_x_259;
	t_sample m_L_u1_y_258;
	t_sample m_L_m2_y_261;
	t_sample m_L_m1_y_263;
	t_sample m_L_m2_x_262;
	t_sample m_L_ap_low_lp2_y_248;
	t_sample m_L_u1_y_257;
	t_sample m_L_u2_y_255;
	t_sample m_L_ap_low_lp1_y_251;
	t_sample m_L_ap_low_lp2_x_250;
	t_sample m_L_u2_x_256;
	t_sample m_L_ap_low_lp1_y_252;
	t_sample m_L_u2_y_254;
	t_sample m_L_ap_low_lp1_x_253;
	t_sample m_L_ap2_hp1_x_4;
	t_sample m_l1_y_154;
	t_sample m_l2_x_152;
	t_sample m_tiltLsL_53;
	t_sample m_tiltLsR_52;
	t_sample m_tiltLsR_51;
	t_sample m_tiltLsL_54;
	t_sample m_tiltLsL_56;
	t_sample m_tiltLsL_55;
	t_sample m_dsPhasor_57;
	t_sample m_scEnableHistory_58;
	t_sample m_tiltLsR_50;
	t_sample m_tiltHsL_48;
	t_sample m_tiltHsR_44;
	t_sample m_tiltHsR_43;
	t_sample m_tiltLsR_49;
	t_sample m_tiltHsL_45;
	t_sample m_tiltHsL_47;
	t_sample m_tiltHsL_46;
	t_sample m_tiltHsR_42;
	t_sample m_lpfFreqHistory_59;
	t_sample m_lpfR_z_61;
	t_sample m_hBitson_72;
	t_sample m_hTilt_71;
	t_sample m_hInput_70;
	t_sample m_hBits_73;
	t_sample m_hDc_75;
	t_sample m_hDrywet_74;
	t_sample m_hDrive_76;
	t_sample m_hpfFreqHistory_60;
	t_sample m_hOutput_69;
	t_sample m_hDownsample_67;
	t_sample m_hpfR_z_63;
	t_sample m_lpfL_z_62;
	t_sample m_hMode_68;
	t_sample m_hpfL_z_64;
	t_sample m_hDownsampleOn_66;
	t_sample m_hBypass_65;
	t_sample m_hBand_77;
	t_sample m_tiltHsR_41;
	t_sample m_R_l1_x_39;
	t_sample m_L_ap1_lp1_x_16;
	t_sample m_R_ap1_lp1_x_15;
	t_sample m_L_ap1_lp2_x_14;
	t_sample m_R_ap_low_hp2_x_17;
	t_sample m_R_ap_low_hp1_x_19;
	t_sample m_L_ap_low_hp2_x_18;
	t_sample m_L_ap_low_hp1_x_20;
	t_sample m_R_ap_low_lp2_x_21;
	t_sample m_R_ap1_lp2_x_13;
	t_sample m_R_ap1_hp1_x_11;
	t_sample m_R_ap2_lp1_x_7;
	t_sample m_L_ap2_lp2_x_6;
	t_sample m_L_ap1_hp1_x_12;
	t_sample m_L_ap2_lp1_x_8;
	t_sample m_L_ap1_hp2_x_10;
	t_sample m_R_ap1_hp2_x_9;
	t_sample m_L_l1_x_40;
	t_sample m_L_ap_low_lp2_x_22;
	t_sample m_L_ap_low_lp1_x_24;
	t_sample m_R_h1_x_35;
	t_sample m_L_h2_x_34;
	t_sample m_R_h2_x_33;
	t_sample m_L_h1_x_36;
	t_sample m_L_l2_x_38;
	t_sample m_R_l2_x_37;
	t_sample m_R_ap_low_lp1_x_23;
	t_sample m_L_m1_x_32;
	t_sample m_L_m2_x_30;
	t_sample m_L_u2_x_26;
	t_sample m_R_u2_x_25;
	t_sample m_R_m1_x_31;
	t_sample m_R_u1_x_27;
	t_sample m_R_m2_x_29;
	t_sample m_L_u1_x_28;
	t_sample m_l2_x_153;
	t_sample m_ap2_hp2_y_78;
	t_sample m_ap2_hp2_x_80;
	t_sample m_u2_x_128;
	t_sample m_u2_y_127;
	t_sample m_u2_y_126;
	t_sample m_u2_x_129;
	t_sample m_u1_y_131;
	t_sample m_u1_y_130;
	t_sample m_u1_x_132;
	t_sample m_u1_x_133;
	t_sample m_ap_low_lp1_x_125;
	t_sample m_ap_low_lp1_y_123;
	t_sample m_ap_low_lp2_y_119;
	t_sample m_ap_low_lp2_y_118;
	t_sample m_ap_low_lp1_x_124;
	t_sample m_ap_low_lp2_x_120;
	t_sample m_ap_low_lp1_y_122;
	t_sample m_ap_low_lp2_x_121;
	t_sample m_ap_low_hp1_x_117;
	t_sample m_m2_y_134;
	t_sample m_m2_x_136;
	t_sample m_h1_y_147;
	t_sample m_h1_y_146;
	t_sample m_h2_x_145;
	t_sample m_h1_x_148;
	t_sample m_l2_y_150;
	t_sample m_h1_x_149;
	t_sample m_R_ap2_hp1_x_3;
	t_sample m_m2_y_135;
	t_sample m_h2_x_144;
	t_sample m_h2_y_142;
	t_sample m_m1_y_138;
	t_sample m_m2_x_137;
	t_sample m_h2_y_143;
	t_sample m_m1_y_139;
	t_sample m_m1_x_141;
	t_sample m_m1_x_140;
	t_sample m_ap2_hp2_y_79;
	t_sample m_ap_low_hp1_x_116;
	t_sample m_ap_low_hp1_y_114;
	t_sample m_ap2_lp1_y_91;
	t_sample m_ap2_lp1_y_90;
	t_sample m_ap2_lp2_x_89;
	t_sample m_ap2_lp1_x_92;
	t_sample m_ap1_hp2_y_94;
	t_sample m_ap2_lp1_x_93;
	t_sample m_ap1_hp2_y_95;
	t_sample m_ap1_hp2_x_96;
	t_sample m_ap2_lp2_x_88;
	t_sample m_ap2_lp2_y_86;
	t_sample m_ap2_hp1_y_82;
	t_sample m_ap2_hp2_x_81;
	t_sample m_ap2_lp2_y_87;
	t_sample m_ap2_hp1_y_83;
	t_sample m_ap2_hp1_x_85;
	t_sample m_ap2_hp1_x_84;
	t_sample m_ap_low_hp1_y_115;
	t_sample m_ap1_hp2_x_97;
	t_sample m_ap1_hp1_y_99;
	t_sample m_ap_low_hp2_y_110;
	t_sample m_ap1_lp1_x_109;
	t_sample m_ap1_lp1_x_108;
	t_sample m_ap_low_hp2_y_111;
	t_sample m_ap_low_hp2_x_113;
	t_sample m_ap_low_hp2_x_112;
	t_sample m_ap1_hp1_y_98;
	t_sample m_ap1_lp1_y_107;
	t_sample m_ap1_lp2_x_105;
	t_sample m_ap1_hp1_x_101;
	t_sample m_ap1_hp1_x_100;
	t_sample m_ap1_lp1_y_106;
	t_sample m_ap1_lp2_y_102;
	t_sample m_ap1_lp2_x_104;
	t_sample m_ap1_lp2_y_103;
	t_sample m_l2_y_151;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_R_ap2_hp2_x_1 = ((int)0);
		m_L_ap2_hp2_x_2 = ((int)0);
		m_R_ap2_hp1_x_3 = ((int)0);
		m_L_ap2_hp1_x_4 = ((int)0);
		m_R_ap2_lp2_x_5 = ((int)0);
		m_L_ap2_lp2_x_6 = ((int)0);
		m_R_ap2_lp1_x_7 = ((int)0);
		m_L_ap2_lp1_x_8 = ((int)0);
		m_R_ap1_hp2_x_9 = ((int)0);
		m_L_ap1_hp2_x_10 = ((int)0);
		m_R_ap1_hp1_x_11 = ((int)0);
		m_L_ap1_hp1_x_12 = ((int)0);
		m_R_ap1_lp2_x_13 = ((int)0);
		m_L_ap1_lp2_x_14 = ((int)0);
		m_R_ap1_lp1_x_15 = ((int)0);
		m_L_ap1_lp1_x_16 = ((int)0);
		m_R_ap_low_hp2_x_17 = ((int)0);
		m_L_ap_low_hp2_x_18 = ((int)0);
		m_R_ap_low_hp1_x_19 = ((int)0);
		m_L_ap_low_hp1_x_20 = ((int)0);
		m_R_ap_low_lp2_x_21 = ((int)0);
		m_L_ap_low_lp2_x_22 = ((int)0);
		m_R_ap_low_lp1_x_23 = ((int)0);
		m_L_ap_low_lp1_x_24 = ((int)0);
		m_R_u2_x_25 = ((int)0);
		m_L_u2_x_26 = ((int)0);
		m_R_u1_x_27 = ((int)0);
		m_L_u1_x_28 = ((int)0);
		m_R_m2_x_29 = ((int)0);
		m_L_m2_x_30 = ((int)0);
		m_R_m1_x_31 = ((int)0);
		m_L_m1_x_32 = ((int)0);
		m_R_h2_x_33 = ((int)0);
		m_L_h2_x_34 = ((int)0);
		m_R_h1_x_35 = ((int)0);
		m_L_h1_x_36 = ((int)0);
		m_R_l2_x_37 = ((int)0);
		m_L_l2_x_38 = ((int)0);
		m_R_l1_x_39 = ((int)0);
		m_L_l1_x_40 = ((int)0);
		m_tiltHsR_41 = ((int)0);
		m_tiltHsR_42 = ((int)0);
		m_tiltHsR_43 = ((int)0);
		m_tiltHsR_44 = ((int)0);
		m_tiltHsL_45 = ((int)0);
		m_tiltHsL_46 = ((int)0);
		m_tiltHsL_47 = ((int)0);
		m_tiltHsL_48 = ((int)0);
		m_tiltLsR_49 = ((int)0);
		m_tiltLsR_50 = ((int)0);
		m_tiltLsR_51 = ((int)0);
		m_tiltLsR_52 = ((int)0);
		m_tiltLsL_53 = ((int)0);
		m_tiltLsL_54 = ((int)0);
		m_tiltLsL_55 = ((int)0);
		m_tiltLsL_56 = ((int)0);
		m_dsPhasor_57 = ((int)0);
		m_scEnableHistory_58 = ((int)0);
		m_lpfFreqHistory_59 = ((int)0);
		m_hpfFreqHistory_60 = ((int)0);
		m_lpfR_z_61 = ((int)0);
		m_lpfL_z_62 = ((int)0);
		m_hpfR_z_63 = ((int)0);
		m_hpfL_z_64 = ((int)0);
		m_hBypass_65 = ((int)0);
		m_hDownsampleOn_66 = ((int)0);
		m_hDownsample_67 = ((int)0);
		m_hMode_68 = ((int)0);
		m_hOutput_69 = ((int)0);
		m_hInput_70 = ((int)0);
		m_hTilt_71 = ((int)0);
		m_hBitson_72 = ((int)0);
		m_hBits_73 = ((int)0);
		m_hDrywet_74 = ((int)0);
		m_hDc_75 = ((int)0);
		m_hDrive_76 = ((int)0);
		m_hBand_77 = ((int)1);
		m_ap2_hp2_y_78 = ((int)0);
		m_ap2_hp2_y_79 = ((int)0);
		m_ap2_hp2_x_80 = ((int)0);
		m_ap2_hp2_x_81 = ((int)0);
		m_ap2_hp1_y_82 = ((int)0);
		m_ap2_hp1_y_83 = ((int)0);
		m_ap2_hp1_x_84 = ((int)0);
		m_ap2_hp1_x_85 = ((int)0);
		m_ap2_lp2_y_86 = ((int)0);
		m_ap2_lp2_y_87 = ((int)0);
		m_ap2_lp2_x_88 = ((int)0);
		m_ap2_lp2_x_89 = ((int)0);
		m_ap2_lp1_y_90 = ((int)0);
		m_ap2_lp1_y_91 = ((int)0);
		m_ap2_lp1_x_92 = ((int)0);
		m_ap2_lp1_x_93 = ((int)0);
		m_ap1_hp2_y_94 = ((int)0);
		m_ap1_hp2_y_95 = ((int)0);
		m_ap1_hp2_x_96 = ((int)0);
		m_ap1_hp2_x_97 = ((int)0);
		m_ap1_hp1_y_98 = ((int)0);
		m_ap1_hp1_y_99 = ((int)0);
		m_ap1_hp1_x_100 = ((int)0);
		m_ap1_hp1_x_101 = ((int)0);
		m_ap1_lp2_y_102 = ((int)0);
		m_ap1_lp2_y_103 = ((int)0);
		m_ap1_lp2_x_104 = ((int)0);
		m_ap1_lp2_x_105 = ((int)0);
		m_ap1_lp1_y_106 = ((int)0);
		m_ap1_lp1_y_107 = ((int)0);
		m_ap1_lp1_x_108 = ((int)0);
		m_ap1_lp1_x_109 = ((int)0);
		m_ap_low_hp2_y_110 = ((int)0);
		m_ap_low_hp2_y_111 = ((int)0);
		m_ap_low_hp2_x_112 = ((int)0);
		m_ap_low_hp2_x_113 = ((int)0);
		m_ap_low_hp1_y_114 = ((int)0);
		m_ap_low_hp1_y_115 = ((int)0);
		m_ap_low_hp1_x_116 = ((int)0);
		m_ap_low_hp1_x_117 = ((int)0);
		m_ap_low_lp2_y_118 = ((int)0);
		m_ap_low_lp2_y_119 = ((int)0);
		m_ap_low_lp2_x_120 = ((int)0);
		m_ap_low_lp2_x_121 = ((int)0);
		m_ap_low_lp1_y_122 = ((int)0);
		m_ap_low_lp1_y_123 = ((int)0);
		m_ap_low_lp1_x_124 = ((int)0);
		m_ap_low_lp1_x_125 = ((int)0);
		m_u2_y_126 = ((int)0);
		m_u2_y_127 = ((int)0);
		m_u2_x_128 = ((int)0);
		m_u2_x_129 = ((int)0);
		m_u1_y_130 = ((int)0);
		m_u1_y_131 = ((int)0);
		m_u1_x_132 = ((int)0);
		m_u1_x_133 = ((int)0);
		m_m2_y_134 = ((int)0);
		m_m2_y_135 = ((int)0);
		m_m2_x_136 = ((int)0);
		m_m2_x_137 = ((int)0);
		m_m1_y_138 = ((int)0);
		m_m1_y_139 = ((int)0);
		m_m1_x_140 = ((int)0);
		m_m1_x_141 = ((int)0);
		m_h2_y_142 = ((int)0);
		m_h2_y_143 = ((int)0);
		m_h2_x_144 = ((int)0);
		m_h2_x_145 = ((int)0);
		m_h1_y_146 = ((int)0);
		m_h1_y_147 = ((int)0);
		m_h1_x_148 = ((int)0);
		m_h1_x_149 = ((int)0);
		m_l2_y_150 = ((int)0);
		m_l2_y_151 = ((int)0);
		m_l2_x_152 = ((int)0);
		m_l2_x_153 = ((int)0);
		m_l1_y_154 = ((int)0);
		m_l1_y_155 = ((int)0);
		m_l1_x_156 = ((int)0);
		m_l1_x_157 = ((int)0);
		m_R_ap2_hp2_y_158 = ((int)0);
		m_R_ap2_hp2_y_159 = ((int)0);
		m_R_ap2_hp2_x_160 = ((int)0);
		m_R_ap2_hp1_y_161 = ((int)0);
		m_R_ap2_hp1_y_162 = ((int)0);
		m_R_ap2_hp1_x_163 = ((int)0);
		m_R_ap2_lp2_y_164 = ((int)0);
		m_R_ap2_lp2_y_165 = ((int)0);
		m_R_ap2_lp2_x_166 = ((int)0);
		m_R_ap2_lp1_y_167 = ((int)0);
		m_R_ap2_lp1_y_168 = ((int)0);
		m_R_ap2_lp1_x_169 = ((int)0);
		m_R_ap1_hp2_y_170 = ((int)0);
		m_R_ap1_hp2_y_171 = ((int)0);
		m_R_ap1_hp2_x_172 = ((int)0);
		m_R_ap1_hp1_y_173 = ((int)0);
		m_R_ap1_hp1_y_174 = ((int)0);
		m_R_ap1_hp1_x_175 = ((int)0);
		m_R_ap1_lp2_y_176 = ((int)0);
		m_R_ap1_lp2_y_177 = ((int)0);
		m_R_ap1_lp2_x_178 = ((int)0);
		m_R_ap1_lp1_y_179 = ((int)0);
		m_R_ap1_lp1_y_180 = ((int)0);
		m_R_ap1_lp1_x_181 = ((int)0);
		m_R_ap_low_hp2_y_182 = ((int)0);
		m_R_ap_low_hp2_y_183 = ((int)0);
		m_R_ap_low_hp2_x_184 = ((int)0);
		m_R_ap_low_hp1_y_185 = ((int)0);
		m_R_ap_low_hp1_y_186 = ((int)0);
		m_R_ap_low_hp1_x_187 = ((int)0);
		m_R_ap_low_lp2_y_188 = ((int)0);
		m_R_ap_low_lp2_y_189 = ((int)0);
		m_R_ap_low_lp2_x_190 = ((int)0);
		m_R_ap_low_lp1_y_191 = ((int)0);
		m_R_ap_low_lp1_y_192 = ((int)0);
		m_R_ap_low_lp1_x_193 = ((int)0);
		m_R_u2_y_194 = ((int)0);
		m_R_u2_y_195 = ((int)0);
		m_R_u2_x_196 = ((int)0);
		m_R_u1_y_197 = ((int)0);
		m_R_u1_y_198 = ((int)0);
		m_R_u1_x_199 = ((int)0);
		m_R_m2_y_200 = ((int)0);
		m_R_m2_y_201 = ((int)0);
		m_R_m2_x_202 = ((int)0);
		m_R_m1_y_203 = ((int)0);
		m_R_m1_y_204 = ((int)0);
		m_R_m1_x_205 = ((int)0);
		m_R_h2_y_206 = ((int)0);
		m_R_h2_y_207 = ((int)0);
		m_R_h2_x_208 = ((int)0);
		m_R_h1_y_209 = ((int)0);
		m_R_h1_y_210 = ((int)0);
		m_R_h1_x_211 = ((int)0);
		m_R_l2_y_212 = ((int)0);
		m_R_l2_y_213 = ((int)0);
		m_R_l2_x_214 = ((int)0);
		m_R_l1_y_215 = ((int)0);
		m_R_l1_y_216 = ((int)0);
		m_R_l1_x_217 = ((int)0);
		m_L_ap2_hp2_y_218 = ((int)0);
		m_L_ap2_hp2_y_219 = ((int)0);
		m_L_ap2_hp2_x_220 = ((int)0);
		m_L_ap2_hp1_y_221 = ((int)0);
		m_L_ap2_hp1_y_222 = ((int)0);
		m_L_ap2_hp1_x_223 = ((int)0);
		m_L_ap2_lp2_y_224 = ((int)0);
		m_L_ap2_lp2_y_225 = ((int)0);
		m_L_ap2_lp2_x_226 = ((int)0);
		m_L_ap2_lp1_y_227 = ((int)0);
		m_L_ap2_lp1_y_228 = ((int)0);
		m_L_ap2_lp1_x_229 = ((int)0);
		m_L_ap1_hp2_y_230 = ((int)0);
		m_L_ap1_hp2_y_231 = ((int)0);
		m_L_ap1_hp2_x_232 = ((int)0);
		m_L_ap1_hp1_y_233 = ((int)0);
		m_L_ap1_hp1_y_234 = ((int)0);
		m_L_ap1_hp1_x_235 = ((int)0);
		m_L_ap1_lp2_y_236 = ((int)0);
		m_L_ap1_lp2_y_237 = ((int)0);
		m_L_ap1_lp2_x_238 = ((int)0);
		m_L_ap1_lp1_y_239 = ((int)0);
		m_L_ap1_lp1_y_240 = ((int)0);
		m_L_ap1_lp1_x_241 = ((int)0);
		m_L_ap_low_hp2_y_242 = ((int)0);
		m_L_ap_low_hp2_y_243 = ((int)0);
		m_L_ap_low_hp2_x_244 = ((int)0);
		m_L_ap_low_hp1_y_245 = ((int)0);
		m_L_ap_low_hp1_y_246 = ((int)0);
		m_L_ap_low_hp1_x_247 = ((int)0);
		m_L_ap_low_lp2_y_248 = ((int)0);
		m_L_ap_low_lp2_y_249 = ((int)0);
		m_L_ap_low_lp2_x_250 = ((int)0);
		m_L_ap_low_lp1_y_251 = ((int)0);
		m_L_ap_low_lp1_y_252 = ((int)0);
		m_L_ap_low_lp1_x_253 = ((int)0);
		m_L_u2_y_254 = ((int)0);
		m_L_u2_y_255 = ((int)0);
		m_L_u2_x_256 = ((int)0);
		m_L_u1_y_257 = ((int)0);
		m_L_u1_y_258 = ((int)0);
		m_L_u1_x_259 = ((int)0);
		m_L_m2_y_260 = ((int)0);
		m_L_m2_y_261 = ((int)0);
		m_L_m2_x_262 = ((int)0);
		m_L_m1_y_263 = ((int)0);
		m_L_m1_y_264 = ((int)0);
		m_L_m1_x_265 = ((int)0);
		m_L_h2_y_266 = ((int)0);
		m_L_h2_y_267 = ((int)0);
		m_L_h2_x_268 = ((int)0);
		m_L_h1_y_269 = ((int)0);
		m_L_h1_y_270 = ((int)0);
		m_L_h1_x_271 = ((int)0);
		m_L_l2_y_272 = ((int)0);
		m_L_l2_y_273 = ((int)0);
		m_L_l2_x_274 = ((int)0);
		m_L_l1_y_275 = ((int)0);
		m_L_l1_y_276 = ((int)0);
		m_L_l1_x_277 = ((int)0);
		m_o_BAND_278 = 1;
		m_n_DOWNSAMPLEON_279 = 0;
		m_m_DOWNSAMPLE_280 = 0;
		m_l_OUTPUT_281 = 0;
		m_k_INPUT_282 = 0;
		m_l_SC_283 = 0;
		m_k_LPF_284 = 5000;
		m_j_HPF_285 = 250;
		m_i_TILT_286 = 0;
		m_h_BITSON_287 = 0;
		m_g_BITS_288 = 16;
		m_f_BYPASS_289 = 0;
		m_e_CEILING_290 = 0;
		m_d_MODE_291 = 0;
		m_c_DC_292 = 0;
		m_b_DRIVE_293 = 1;
		m_a_DRYWET_294 = 1;
		__m_dcblock_372.reset();
		__m_dcblock_373.reset();
		__m_dcblock_376.reset();
		__m_dcblock_377.reset();
		samples_to_seconds = (1 / samplerate);
		__m_phasor_378.reset(0);
		__m_latch_379 = 0;
		__m_latch_380 = 0;
		__m_dcblock_381.reset();
		__m_dcblock_382.reset();
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
		t_sample ceiling = dbtoa(m_e_CEILING_290);
		int L_sr = samplerate;
		t_sample minb_295 = (((t_sample)0.45) * L_sr);
		t_sample minb_297 = (((t_sample)0.45) * L_sr);
		int R_sr = samplerate;
		t_sample minb_300 = (((t_sample)0.45) * R_sr);
		t_sample minb_302 = (((t_sample)0.45) * R_sr);
		int L_sr_12348 = samplerate;
		t_sample minb_309 = (((t_sample)0.45) * L_sr_12348);
		t_sample minb_311 = (((t_sample)0.45) * L_sr_12348);
		int R_sr_12391 = samplerate;
		t_sample minb_314 = (((t_sample)0.45) * R_sr_12391);
		t_sample minb_316 = (((t_sample)0.45) * R_sr_12391);
		t_sample omega = safediv(((t_sample)6283.1853071796), samplerate);
		t_sample sn = sin(omega);
		t_sample cs = cos(omega);
		t_sample cos2 = ((cs * cs) - (sn * sn));
		t_sample sin2 = ((((int)2) * sn) * cs);
		samples_to_seconds = (1 / samplerate);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample lIn = in1;
			t_sample rIn = in2;
			m_hDrive_76 = ((m_hDrive_76 * ((t_sample)0.999)) + (m_b_DRIVE_293 * ((t_sample)0.001)));
			t_sample drive = m_hDrive_76;
			m_hDc_75 = ((m_hDc_75 * ((t_sample)0.999)) + (m_c_DC_292 * ((t_sample)0.001)));
			t_sample dc = m_hDc_75;
			m_hDrywet_74 = ((m_hDrywet_74 * ((t_sample)0.999)) + (m_a_DRYWET_294 * ((t_sample)0.001)));
			t_sample drywet = m_hDrywet_74;
			m_hBits_73 = ((m_hBits_73 * ((t_sample)0.999)) + (m_g_BITS_288 * ((t_sample)0.001)));
			t_sample bits = m_hBits_73;
			m_hBitson_72 = ((m_hBitson_72 * ((t_sample)0.999)) + (m_h_BITSON_287 * ((t_sample)0.001)));
			t_sample bitson = m_hBitson_72;
			m_hTilt_71 = ((m_hTilt_71 * ((t_sample)0.999)) + (m_i_TILT_286 * ((t_sample)0.001)));
			t_sample tiltDb = m_hTilt_71;
			m_hInput_70 = ((m_hInput_70 * ((t_sample)0.999)) + (m_k_INPUT_282 * ((t_sample)0.001)));
			t_sample inputTrimDb = m_hInput_70;
			m_hOutput_69 = ((m_hOutput_69 * ((t_sample)0.999)) + (m_l_OUTPUT_281 * ((t_sample)0.001)));
			t_sample outputMakeupDb = m_hOutput_69;
			m_hBand_77 = ((m_hBand_77 * ((t_sample)0.999)) + (m_o_BAND_278 * ((t_sample)0.001)));
			t_sample smoothedBand = m_hBand_77;
			m_hMode_68 = ((m_hMode_68 * ((t_sample)0.99)) + (m_d_MODE_291 * ((t_sample)0.01)));
			t_sample smoothedMode = m_hMode_68;
			m_hDownsample_67 = ((m_hDownsample_67 * ((t_sample)0.999)) + (m_m_DOWNSAMPLE_280 * ((t_sample)0.001)));
			m_hDownsampleOn_66 = ((m_hDownsampleOn_66 * ((t_sample)0.999)) + (m_n_DOWNSAMPLEON_279 * ((t_sample)0.001)));
			t_sample downsampleOn = m_hDownsampleOn_66;
			m_hBypass_65 = ((m_hBypass_65 * ((t_sample)0.999)) + ((((int)1) - m_f_BYPASS_289) * ((t_sample)0.001)));
			t_sample bypass = m_hBypass_65;
			t_sample smoothHpfFreq = ((m_hpfFreqHistory_60 * ((t_sample)0.999)) + (m_j_HPF_285 * ((t_sample)0.001)));
			m_hpfFreqHistory_60 = fixdenorm(smoothHpfFreq);
			t_sample smoothLpfFreq = ((m_lpfFreqHistory_59 * ((t_sample)0.999)) + (m_k_LPF_284 * ((t_sample)0.001)));
			m_lpfFreqHistory_59 = fixdenorm(smoothLpfFreq);
			t_sample smoothScEnable = ((m_scEnableHistory_58 * ((t_sample)0.999)) + (m_l_SC_283 * ((t_sample)0.001)));
			m_scEnableHistory_58 = fixdenorm(smoothScEnable);
			t_sample inputTrimLinear = dbtoa(inputTrimDb);
			t_sample outputMakeupLinear = dbtoa(outputMakeupDb);
			t_sample lTrimmed = (lIn * inputTrimLinear);
			t_sample rTrimmed = (rIn * inputTrimLinear);
			t_sample scSm = smoothScEnable;
			t_sample L_loF = smoothHpfFreq;
			t_sample L_hiF = smoothLpfFreq;
			t_sample L_x = lTrimmed;
			t_sample maxb_296 = ((minb_295 < L_loF) ? minb_295 : L_loF);
			t_sample L_loF_12335 = ((((int)10) < maxb_296) ? maxb_296 : ((int)10));
			t_sample maxb_298 = ((minb_297 < L_hiF) ? minb_297 : L_hiF);
			t_sample L_hiFr = ((((int)10) < maxb_298) ? maxb_298 : ((int)10));
			t_sample maxb_299 = (L_loF_12335 + ((int)1));
			t_sample L_hiF_12336 = ((L_hiFr < maxb_299) ? maxb_299 : L_hiFr);
			t_sample L_w0_lo = safediv((((t_sample)6.2831853071796) * L_loF_12335), L_sr);
			t_sample L_cos_lo = cos(L_w0_lo);
			t_sample L_sin_lo = sin(L_w0_lo);
			t_sample L_alpha_lo = (L_sin_lo * ((t_sample)0.70710678118655));
			t_sample L_a0_lo = (((int)1) + L_alpha_lo);
			t_sample L_a1_lo = (((int)-2) * L_cos_lo);
			t_sample L_a2_lo = (((int)1) - L_alpha_lo);
			t_sample L_lp_b0_l = safediv(((((int)1) - L_cos_lo) * ((t_sample)0.5)), L_a0_lo);
			t_sample L_lp_b1_l = safediv((((int)1) - L_cos_lo), L_a0_lo);
			t_sample L_lp_b2_l = L_lp_b0_l;
			t_sample L_lp_a1_l = safediv(L_a1_lo, L_a0_lo);
			t_sample L_lp_a2_l = safediv(L_a2_lo, L_a0_lo);
			t_sample L_hp_b0_l = safediv(((((int)1) + L_cos_lo) * ((t_sample)0.5)), L_a0_lo);
			t_sample L_hp_b1_l = safediv((-(((int)1) + L_cos_lo)), L_a0_lo);
			t_sample L_hp_b2_l = L_hp_b0_l;
			t_sample L_hp_a1_l = L_lp_a1_l;
			t_sample L_hp_a2_l = L_lp_a2_l;
			t_sample L_w0_hi = safediv((((t_sample)6.2831853071796) * L_hiF_12336), L_sr);
			t_sample L_cos_hi = cos(L_w0_hi);
			t_sample L_sin_hi = sin(L_w0_hi);
			t_sample L_alpha_hi = (L_sin_hi * ((t_sample)0.70710678118655));
			t_sample L_a0_hi = (((int)1) + L_alpha_hi);
			t_sample L_a1_hi = (((int)-2) * L_cos_hi);
			t_sample L_a2_hi = (((int)1) - L_alpha_hi);
			t_sample L_lp_b0_h = safediv(((((int)1) - L_cos_hi) * ((t_sample)0.5)), L_a0_hi);
			t_sample L_lp_b1_h = safediv((((int)1) - L_cos_hi), L_a0_hi);
			t_sample L_lp_b2_h = L_lp_b0_h;
			t_sample L_lp_a1_h = safediv(L_a1_hi, L_a0_hi);
			t_sample L_lp_a2_h = safediv(L_a2_hi, L_a0_hi);
			t_sample L_hp_b0_h = safediv(((((int)1) + L_cos_hi) * ((t_sample)0.5)), L_a0_hi);
			t_sample L_hp_b1_h = safediv((-(((int)1) + L_cos_hi)), L_a0_hi);
			t_sample L_hp_b2_h = L_hp_b0_h;
			t_sample L_hp_a1_h = L_lp_a1_h;
			t_sample L_hp_a2_h = L_lp_a2_h;
			t_sample L_l1_x1p = m_L_l1_x_40;
			t_sample L_l1_x2p = m_L_l1_x_277;
			t_sample L_l1_y1p = m_L_l1_y_276;
			t_sample L_l1_y2p = m_L_l1_y_275;
			t_sample L_low_s1 = (((((L_lp_b0_l * L_x) + (L_lp_b1_l * L_l1_x1p)) + (L_lp_b2_l * L_l1_x2p)) - (L_lp_a1_l * L_l1_y1p)) - (L_lp_a2_l * L_l1_y2p));
			m_L_l1_x_277 = L_l1_x1p;
			m_L_l1_x_40 = L_x;
			m_L_l1_y_275 = L_l1_y1p;
			m_L_l1_y_276 = L_low_s1;
			t_sample L_l2_x1p = m_L_l2_x_38;
			t_sample L_l2_x2p = m_L_l2_x_274;
			t_sample L_l2_y1p = m_L_l2_y_273;
			t_sample L_l2_y2p = m_L_l2_y_272;
			t_sample L_low_raw = (((((L_lp_b0_l * L_low_s1) + (L_lp_b1_l * L_l2_x1p)) + (L_lp_b2_l * L_l2_x2p)) - (L_lp_a1_l * L_l2_y1p)) - (L_lp_a2_l * L_l2_y2p));
			m_L_l2_x_274 = L_l2_x1p;
			m_L_l2_x_38 = L_low_s1;
			m_L_l2_y_272 = L_l2_y1p;
			m_L_l2_y_273 = L_low_raw;
			t_sample L_h1_x1p = m_L_h1_x_36;
			t_sample L_h1_x2p = m_L_h1_x_271;
			t_sample L_h1_y1p = m_L_h1_y_270;
			t_sample L_h1_y2p = m_L_h1_y_269;
			t_sample L_rest_s1 = (((((L_hp_b0_l * L_x) + (L_hp_b1_l * L_h1_x1p)) + (L_hp_b2_l * L_h1_x2p)) - (L_hp_a1_l * L_h1_y1p)) - (L_hp_a2_l * L_h1_y2p));
			m_L_h1_x_271 = L_h1_x1p;
			m_L_h1_x_36 = L_x;
			m_L_h1_y_269 = L_h1_y1p;
			m_L_h1_y_270 = L_rest_s1;
			t_sample L_h2_x1p = m_L_h2_x_34;
			t_sample L_h2_x2p = m_L_h2_x_268;
			t_sample L_h2_y1p = m_L_h2_y_267;
			t_sample L_h2_y2p = m_L_h2_y_266;
			t_sample L_rest = (((((L_hp_b0_l * L_rest_s1) + (L_hp_b1_l * L_h2_x1p)) + (L_hp_b2_l * L_h2_x2p)) - (L_hp_a1_l * L_h2_y1p)) - (L_hp_a2_l * L_h2_y2p));
			m_L_h2_x_268 = L_h2_x1p;
			m_L_h2_x_34 = L_rest_s1;
			m_L_h2_y_266 = L_h2_y1p;
			m_L_h2_y_267 = L_rest;
			t_sample L_ap_low_lp1_x1p = m_L_ap_low_lp1_x_24;
			t_sample L_ap_low_lp1_x2p = m_L_ap_low_lp1_x_253;
			t_sample L_ap_low_lp1_y1p = m_L_ap_low_lp1_y_252;
			t_sample L_ap_low_lp1_y2p = m_L_ap_low_lp1_y_251;
			t_sample L_ap_low_lp_s1 = (((((L_lp_b0_h * L_low_raw) + (L_lp_b1_h * L_ap_low_lp1_x1p)) + (L_lp_b2_h * L_ap_low_lp1_x2p)) - (L_lp_a1_h * L_ap_low_lp1_y1p)) - (L_lp_a2_h * L_ap_low_lp1_y2p));
			m_L_ap_low_lp1_x_253 = L_ap_low_lp1_x1p;
			m_L_ap_low_lp1_x_24 = L_low_raw;
			m_L_ap_low_lp1_y_251 = L_ap_low_lp1_y1p;
			m_L_ap_low_lp1_y_252 = L_ap_low_lp_s1;
			t_sample L_ap_low_lp2_x1p = m_L_ap_low_lp2_x_22;
			t_sample L_ap_low_lp2_x2p = m_L_ap_low_lp2_x_250;
			t_sample L_ap_low_lp2_y1p = m_L_ap_low_lp2_y_249;
			t_sample L_ap_low_lp2_y2p = m_L_ap_low_lp2_y_248;
			t_sample L_ap_low_lp = (((((L_lp_b0_h * L_ap_low_lp_s1) + (L_lp_b1_h * L_ap_low_lp2_x1p)) + (L_lp_b2_h * L_ap_low_lp2_x2p)) - (L_lp_a1_h * L_ap_low_lp2_y1p)) - (L_lp_a2_h * L_ap_low_lp2_y2p));
			m_L_ap_low_lp2_x_250 = L_ap_low_lp2_x1p;
			m_L_ap_low_lp2_x_22 = L_ap_low_lp_s1;
			m_L_ap_low_lp2_y_248 = L_ap_low_lp2_y1p;
			m_L_ap_low_lp2_y_249 = L_ap_low_lp;
			t_sample L_ap_low_hp1_x1p = m_L_ap_low_hp1_x_20;
			t_sample L_ap_low_hp1_x2p = m_L_ap_low_hp1_x_247;
			t_sample L_ap_low_hp1_y1p = m_L_ap_low_hp1_y_246;
			t_sample L_ap_low_hp1_y2p = m_L_ap_low_hp1_y_245;
			t_sample L_ap_low_hp_s1 = (((((L_hp_b0_h * L_low_raw) + (L_hp_b1_h * L_ap_low_hp1_x1p)) + (L_hp_b2_h * L_ap_low_hp1_x2p)) - (L_hp_a1_h * L_ap_low_hp1_y1p)) - (L_hp_a2_h * L_ap_low_hp1_y2p));
			m_L_ap_low_hp1_x_247 = L_ap_low_hp1_x1p;
			m_L_ap_low_hp1_x_20 = L_low_raw;
			m_L_ap_low_hp1_y_245 = L_ap_low_hp1_y1p;
			m_L_ap_low_hp1_y_246 = L_ap_low_hp_s1;
			t_sample L_ap_low_hp2_x1p = m_L_ap_low_hp2_x_18;
			t_sample L_ap_low_hp2_x2p = m_L_ap_low_hp2_x_244;
			t_sample L_ap_low_hp2_y1p = m_L_ap_low_hp2_y_243;
			t_sample L_ap_low_hp2_y2p = m_L_ap_low_hp2_y_242;
			t_sample L_ap_low_hp = (((((L_hp_b0_h * L_ap_low_hp_s1) + (L_hp_b1_h * L_ap_low_hp2_x1p)) + (L_hp_b2_h * L_ap_low_hp2_x2p)) - (L_hp_a1_h * L_ap_low_hp2_y1p)) - (L_hp_a2_h * L_ap_low_hp2_y2p));
			m_L_ap_low_hp2_x_244 = L_ap_low_hp2_x1p;
			m_L_ap_low_hp2_x_18 = L_ap_low_hp_s1;
			m_L_ap_low_hp2_y_242 = L_ap_low_hp2_y1p;
			m_L_ap_low_hp2_y_243 = L_ap_low_hp;
			t_sample L_low = (L_ap_low_lp + L_ap_low_hp);
			t_sample L_m1_x1p = m_L_m1_x_32;
			t_sample L_m1_x2p = m_L_m1_x_265;
			t_sample L_m1_y1p = m_L_m1_y_264;
			t_sample L_m1_y2p = m_L_m1_y_263;
			t_sample L_mid_s1 = (((((L_lp_b0_h * L_rest) + (L_lp_b1_h * L_m1_x1p)) + (L_lp_b2_h * L_m1_x2p)) - (L_lp_a1_h * L_m1_y1p)) - (L_lp_a2_h * L_m1_y2p));
			m_L_m1_x_265 = L_m1_x1p;
			m_L_m1_x_32 = L_rest;
			m_L_m1_y_263 = L_m1_y1p;
			m_L_m1_y_264 = L_mid_s1;
			t_sample L_m2_x1p = m_L_m2_x_30;
			t_sample L_m2_x2p = m_L_m2_x_262;
			t_sample L_m2_y1p = m_L_m2_y_261;
			t_sample L_m2_y2p = m_L_m2_y_260;
			t_sample L_mid = (((((L_lp_b0_h * L_mid_s1) + (L_lp_b1_h * L_m2_x1p)) + (L_lp_b2_h * L_m2_x2p)) - (L_lp_a1_h * L_m2_y1p)) - (L_lp_a2_h * L_m2_y2p));
			m_L_m2_x_262 = L_m2_x1p;
			m_L_m2_x_30 = L_mid_s1;
			m_L_m2_y_260 = L_m2_y1p;
			m_L_m2_y_261 = L_mid;
			t_sample L_u1_x1p = m_L_u1_x_28;
			t_sample L_u1_x2p = m_L_u1_x_259;
			t_sample L_u1_y1p = m_L_u1_y_258;
			t_sample L_u1_y2p = m_L_u1_y_257;
			t_sample L_high_s1 = (((((L_hp_b0_h * L_rest) + (L_hp_b1_h * L_u1_x1p)) + (L_hp_b2_h * L_u1_x2p)) - (L_hp_a1_h * L_u1_y1p)) - (L_hp_a2_h * L_u1_y2p));
			m_L_u1_x_259 = L_u1_x1p;
			m_L_u1_x_28 = L_rest;
			m_L_u1_y_257 = L_u1_y1p;
			m_L_u1_y_258 = L_high_s1;
			t_sample L_u2_x1p = m_L_u2_x_26;
			t_sample L_u2_x2p = m_L_u2_x_256;
			t_sample L_u2_y1p = m_L_u2_y_255;
			t_sample L_u2_y2p = m_L_u2_y_254;
			t_sample L_high = (((((L_hp_b0_h * L_high_s1) + (L_hp_b1_h * L_u2_x1p)) + (L_hp_b2_h * L_u2_x2p)) - (L_hp_a1_h * L_u2_y1p)) - (L_hp_a2_h * L_u2_y2p));
			m_L_u2_x_256 = L_u2_x1p;
			m_L_u2_x_26 = L_high_s1;
			m_L_u2_y_254 = L_u2_y1p;
			m_L_u2_y_255 = L_high;
			t_sample lowL = L_low;
			t_sample midL = L_mid;
			t_sample highL = L_high;
			t_sample R_loF = smoothHpfFreq;
			t_sample R_hiF = smoothLpfFreq;
			t_sample R_x = rTrimmed;
			t_sample maxb_301 = ((minb_300 < R_loF) ? minb_300 : R_loF);
			t_sample R_loF_12337 = ((((int)10) < maxb_301) ? maxb_301 : ((int)10));
			t_sample maxb_303 = ((minb_302 < R_hiF) ? minb_302 : R_hiF);
			t_sample R_hiFr = ((((int)10) < maxb_303) ? maxb_303 : ((int)10));
			t_sample maxb_304 = (R_loF_12337 + ((int)1));
			t_sample R_hiF_12338 = ((R_hiFr < maxb_304) ? maxb_304 : R_hiFr);
			t_sample R_w0_lo = safediv((((t_sample)6.2831853071796) * R_loF_12337), R_sr);
			t_sample R_cos_lo = cos(R_w0_lo);
			t_sample R_sin_lo = sin(R_w0_lo);
			t_sample R_alpha_lo = (R_sin_lo * ((t_sample)0.70710678118655));
			t_sample R_a0_lo = (((int)1) + R_alpha_lo);
			t_sample R_a1_lo = (((int)-2) * R_cos_lo);
			t_sample R_a2_lo = (((int)1) - R_alpha_lo);
			t_sample R_lp_b0_l = safediv(((((int)1) - R_cos_lo) * ((t_sample)0.5)), R_a0_lo);
			t_sample R_lp_b1_l = safediv((((int)1) - R_cos_lo), R_a0_lo);
			t_sample R_lp_b2_l = R_lp_b0_l;
			t_sample R_lp_a1_l = safediv(R_a1_lo, R_a0_lo);
			t_sample R_lp_a2_l = safediv(R_a2_lo, R_a0_lo);
			t_sample R_hp_b0_l = safediv(((((int)1) + R_cos_lo) * ((t_sample)0.5)), R_a0_lo);
			t_sample R_hp_b1_l = safediv((-(((int)1) + R_cos_lo)), R_a0_lo);
			t_sample R_hp_b2_l = R_hp_b0_l;
			t_sample R_hp_a1_l = R_lp_a1_l;
			t_sample R_hp_a2_l = R_lp_a2_l;
			t_sample R_w0_hi = safediv((((t_sample)6.2831853071796) * R_hiF_12338), R_sr);
			t_sample R_cos_hi = cos(R_w0_hi);
			t_sample R_sin_hi = sin(R_w0_hi);
			t_sample R_alpha_hi = (R_sin_hi * ((t_sample)0.70710678118655));
			t_sample R_a0_hi = (((int)1) + R_alpha_hi);
			t_sample R_a1_hi = (((int)-2) * R_cos_hi);
			t_sample R_a2_hi = (((int)1) - R_alpha_hi);
			t_sample R_lp_b0_h = safediv(((((int)1) - R_cos_hi) * ((t_sample)0.5)), R_a0_hi);
			t_sample R_lp_b1_h = safediv((((int)1) - R_cos_hi), R_a0_hi);
			t_sample R_lp_b2_h = R_lp_b0_h;
			t_sample R_lp_a1_h = safediv(R_a1_hi, R_a0_hi);
			t_sample R_lp_a2_h = safediv(R_a2_hi, R_a0_hi);
			t_sample R_hp_b0_h = safediv(((((int)1) + R_cos_hi) * ((t_sample)0.5)), R_a0_hi);
			t_sample R_hp_b1_h = safediv((-(((int)1) + R_cos_hi)), R_a0_hi);
			t_sample R_hp_b2_h = R_hp_b0_h;
			t_sample R_hp_a1_h = R_lp_a1_h;
			t_sample R_hp_a2_h = R_lp_a2_h;
			t_sample R_l1_x1p = m_R_l1_x_39;
			t_sample R_l1_x2p = m_R_l1_x_217;
			t_sample R_l1_y1p = m_R_l1_y_216;
			t_sample R_l1_y2p = m_R_l1_y_215;
			t_sample R_low_s1 = (((((R_lp_b0_l * R_x) + (R_lp_b1_l * R_l1_x1p)) + (R_lp_b2_l * R_l1_x2p)) - (R_lp_a1_l * R_l1_y1p)) - (R_lp_a2_l * R_l1_y2p));
			m_R_l1_x_217 = R_l1_x1p;
			m_R_l1_x_39 = R_x;
			m_R_l1_y_215 = R_l1_y1p;
			m_R_l1_y_216 = R_low_s1;
			t_sample R_l2_x1p = m_R_l2_x_37;
			t_sample R_l2_x2p = m_R_l2_x_214;
			t_sample R_l2_y1p = m_R_l2_y_213;
			t_sample R_l2_y2p = m_R_l2_y_212;
			t_sample R_low_raw = (((((R_lp_b0_l * R_low_s1) + (R_lp_b1_l * R_l2_x1p)) + (R_lp_b2_l * R_l2_x2p)) - (R_lp_a1_l * R_l2_y1p)) - (R_lp_a2_l * R_l2_y2p));
			m_R_l2_x_214 = R_l2_x1p;
			m_R_l2_x_37 = R_low_s1;
			m_R_l2_y_212 = R_l2_y1p;
			m_R_l2_y_213 = R_low_raw;
			t_sample R_h1_x1p = m_R_h1_x_35;
			t_sample R_h1_x2p = m_R_h1_x_211;
			t_sample R_h1_y1p = m_R_h1_y_210;
			t_sample R_h1_y2p = m_R_h1_y_209;
			t_sample R_rest_s1 = (((((R_hp_b0_l * R_x) + (R_hp_b1_l * R_h1_x1p)) + (R_hp_b2_l * R_h1_x2p)) - (R_hp_a1_l * R_h1_y1p)) - (R_hp_a2_l * R_h1_y2p));
			m_R_h1_x_211 = R_h1_x1p;
			m_R_h1_x_35 = R_x;
			m_R_h1_y_209 = R_h1_y1p;
			m_R_h1_y_210 = R_rest_s1;
			t_sample R_h2_x1p = m_R_h2_x_33;
			t_sample R_h2_x2p = m_R_h2_x_208;
			t_sample R_h2_y1p = m_R_h2_y_207;
			t_sample R_h2_y2p = m_R_h2_y_206;
			t_sample R_rest = (((((R_hp_b0_l * R_rest_s1) + (R_hp_b1_l * R_h2_x1p)) + (R_hp_b2_l * R_h2_x2p)) - (R_hp_a1_l * R_h2_y1p)) - (R_hp_a2_l * R_h2_y2p));
			m_R_h2_x_208 = R_h2_x1p;
			m_R_h2_x_33 = R_rest_s1;
			m_R_h2_y_206 = R_h2_y1p;
			m_R_h2_y_207 = R_rest;
			t_sample R_ap_low_lp1_x1p = m_R_ap_low_lp1_x_23;
			t_sample R_ap_low_lp1_x2p = m_R_ap_low_lp1_x_193;
			t_sample R_ap_low_lp1_y1p = m_R_ap_low_lp1_y_192;
			t_sample R_ap_low_lp1_y2p = m_R_ap_low_lp1_y_191;
			t_sample R_ap_low_lp_s1 = (((((R_lp_b0_h * R_low_raw) + (R_lp_b1_h * R_ap_low_lp1_x1p)) + (R_lp_b2_h * R_ap_low_lp1_x2p)) - (R_lp_a1_h * R_ap_low_lp1_y1p)) - (R_lp_a2_h * R_ap_low_lp1_y2p));
			m_R_ap_low_lp1_x_193 = R_ap_low_lp1_x1p;
			m_R_ap_low_lp1_x_23 = R_low_raw;
			m_R_ap_low_lp1_y_191 = R_ap_low_lp1_y1p;
			m_R_ap_low_lp1_y_192 = R_ap_low_lp_s1;
			t_sample R_ap_low_lp2_x1p = m_R_ap_low_lp2_x_21;
			t_sample R_ap_low_lp2_x2p = m_R_ap_low_lp2_x_190;
			t_sample R_ap_low_lp2_y1p = m_R_ap_low_lp2_y_189;
			t_sample R_ap_low_lp2_y2p = m_R_ap_low_lp2_y_188;
			t_sample R_ap_low_lp = (((((R_lp_b0_h * R_ap_low_lp_s1) + (R_lp_b1_h * R_ap_low_lp2_x1p)) + (R_lp_b2_h * R_ap_low_lp2_x2p)) - (R_lp_a1_h * R_ap_low_lp2_y1p)) - (R_lp_a2_h * R_ap_low_lp2_y2p));
			m_R_ap_low_lp2_x_190 = R_ap_low_lp2_x1p;
			m_R_ap_low_lp2_x_21 = R_ap_low_lp_s1;
			m_R_ap_low_lp2_y_188 = R_ap_low_lp2_y1p;
			m_R_ap_low_lp2_y_189 = R_ap_low_lp;
			t_sample R_ap_low_hp1_x1p = m_R_ap_low_hp1_x_19;
			t_sample R_ap_low_hp1_x2p = m_R_ap_low_hp1_x_187;
			t_sample R_ap_low_hp1_y1p = m_R_ap_low_hp1_y_186;
			t_sample R_ap_low_hp1_y2p = m_R_ap_low_hp1_y_185;
			t_sample R_ap_low_hp_s1 = (((((R_hp_b0_h * R_low_raw) + (R_hp_b1_h * R_ap_low_hp1_x1p)) + (R_hp_b2_h * R_ap_low_hp1_x2p)) - (R_hp_a1_h * R_ap_low_hp1_y1p)) - (R_hp_a2_h * R_ap_low_hp1_y2p));
			m_R_ap_low_hp1_x_187 = R_ap_low_hp1_x1p;
			m_R_ap_low_hp1_x_19 = R_low_raw;
			m_R_ap_low_hp1_y_185 = R_ap_low_hp1_y1p;
			m_R_ap_low_hp1_y_186 = R_ap_low_hp_s1;
			t_sample R_ap_low_hp2_x1p = m_R_ap_low_hp2_x_17;
			t_sample R_ap_low_hp2_x2p = m_R_ap_low_hp2_x_184;
			t_sample R_ap_low_hp2_y1p = m_R_ap_low_hp2_y_183;
			t_sample R_ap_low_hp2_y2p = m_R_ap_low_hp2_y_182;
			t_sample R_ap_low_hp = (((((R_hp_b0_h * R_ap_low_hp_s1) + (R_hp_b1_h * R_ap_low_hp2_x1p)) + (R_hp_b2_h * R_ap_low_hp2_x2p)) - (R_hp_a1_h * R_ap_low_hp2_y1p)) - (R_hp_a2_h * R_ap_low_hp2_y2p));
			m_R_ap_low_hp2_x_184 = R_ap_low_hp2_x1p;
			m_R_ap_low_hp2_x_17 = R_ap_low_hp_s1;
			m_R_ap_low_hp2_y_182 = R_ap_low_hp2_y1p;
			m_R_ap_low_hp2_y_183 = R_ap_low_hp;
			t_sample R_low = (R_ap_low_lp + R_ap_low_hp);
			t_sample R_m1_x1p = m_R_m1_x_31;
			t_sample R_m1_x2p = m_R_m1_x_205;
			t_sample R_m1_y1p = m_R_m1_y_204;
			t_sample R_m1_y2p = m_R_m1_y_203;
			t_sample R_mid_s1 = (((((R_lp_b0_h * R_rest) + (R_lp_b1_h * R_m1_x1p)) + (R_lp_b2_h * R_m1_x2p)) - (R_lp_a1_h * R_m1_y1p)) - (R_lp_a2_h * R_m1_y2p));
			m_R_m1_x_205 = R_m1_x1p;
			m_R_m1_x_31 = R_rest;
			m_R_m1_y_203 = R_m1_y1p;
			m_R_m1_y_204 = R_mid_s1;
			t_sample R_m2_x1p = m_R_m2_x_29;
			t_sample R_m2_x2p = m_R_m2_x_202;
			t_sample R_m2_y1p = m_R_m2_y_201;
			t_sample R_m2_y2p = m_R_m2_y_200;
			t_sample R_mid = (((((R_lp_b0_h * R_mid_s1) + (R_lp_b1_h * R_m2_x1p)) + (R_lp_b2_h * R_m2_x2p)) - (R_lp_a1_h * R_m2_y1p)) - (R_lp_a2_h * R_m2_y2p));
			m_R_m2_x_202 = R_m2_x1p;
			m_R_m2_x_29 = R_mid_s1;
			m_R_m2_y_200 = R_m2_y1p;
			m_R_m2_y_201 = R_mid;
			t_sample R_u1_x1p = m_R_u1_x_27;
			t_sample R_u1_x2p = m_R_u1_x_199;
			t_sample R_u1_y1p = m_R_u1_y_198;
			t_sample R_u1_y2p = m_R_u1_y_197;
			t_sample R_high_s1 = (((((R_hp_b0_h * R_rest) + (R_hp_b1_h * R_u1_x1p)) + (R_hp_b2_h * R_u1_x2p)) - (R_hp_a1_h * R_u1_y1p)) - (R_hp_a2_h * R_u1_y2p));
			m_R_u1_x_199 = R_u1_x1p;
			m_R_u1_x_27 = R_rest;
			m_R_u1_y_197 = R_u1_y1p;
			m_R_u1_y_198 = R_high_s1;
			t_sample R_u2_x1p = m_R_u2_x_25;
			t_sample R_u2_x2p = m_R_u2_x_196;
			t_sample R_u2_y1p = m_R_u2_y_195;
			t_sample R_u2_y2p = m_R_u2_y_194;
			t_sample R_high = (((((R_hp_b0_h * R_high_s1) + (R_hp_b1_h * R_u2_x1p)) + (R_hp_b2_h * R_u2_x2p)) - (R_hp_a1_h * R_u2_y1p)) - (R_hp_a2_h * R_u2_y2p));
			m_R_u2_x_196 = R_u2_x1p;
			m_R_u2_x_25 = R_high_s1;
			m_R_u2_y_194 = R_u2_y1p;
			m_R_u2_y_195 = R_high;
			t_sample lowR = R_low;
			t_sample midR = R_mid;
			t_sample highR = R_high;
			t_sample maxb_305 = (((int)1) - fabs((smoothedBand - ((int)0))));
			t_sample wLow = ((((int)0) < maxb_305) ? maxb_305 : ((int)0));
			t_sample maxb_306 = (((int)1) - fabs((smoothedBand - ((int)1))));
			t_sample wMid = ((((int)0) < maxb_306) ? maxb_306 : ((int)0));
			t_sample maxb_307 = (((int)1) - fabs((smoothedBand - ((int)2))));
			t_sample wHigh = ((((int)0) < maxb_307) ? maxb_307 : ((int)0));
			t_sample maxb_308 = ((wLow + wMid) + wHigh);
			t_sample wSum = ((((t_sample)1e-09) < maxb_308) ? maxb_308 : ((t_sample)1e-09));
			t_sample wLow_12340 = safediv(wLow, wSum);
			t_sample wMid_12341 = safediv(wMid, wSum);
			t_sample wHigh_12342 = safediv(wHigh, wSum);
			t_sample preBandL = (((wLow_12340 * lowL) + (wMid_12341 * midL)) + (wHigh_12342 * highL));
			t_sample preBandR = (((wLow_12340 * lowR) + (wMid_12341 * midR)) + (wHigh_12342 * highR));
			t_sample sumBandsL = ((lowL + midL) + highL);
			t_sample sumBandsR = ((lowR + midR) + highR);
			t_sample bypassWhenActiveL = (sumBandsL - preBandL);
			t_sample bypassWhenActiveR = (sumBandsR - preBandR);
			t_sample mix_12456 = (lTrimmed + (scSm * (preBandL - lTrimmed)));
			t_sample preDistInL = mix_12456;
			t_sample mix_12457 = (rTrimmed + (scSm * (preBandR - rTrimmed)));
			t_sample preDistInR = mix_12457;
			t_sample L_loF_12343 = smoothHpfFreq;
			t_sample L_hiF_12344 = smoothLpfFreq;
			t_sample L_x_12345 = lTrimmed;
			t_sample maxb_310 = ((minb_309 < L_loF_12343) ? minb_309 : L_loF_12343);
			t_sample L_loF_12349 = ((((int)10) < maxb_310) ? maxb_310 : ((int)10));
			t_sample maxb_312 = ((minb_311 < L_hiF_12344) ? minb_311 : L_hiF_12344);
			t_sample L_hiFr_12350 = ((((int)10) < maxb_312) ? maxb_312 : ((int)10));
			t_sample maxb_313 = (L_loF_12349 + ((int)1));
			t_sample L_hiF_12351 = ((L_hiFr_12350 < maxb_313) ? maxb_313 : L_hiFr_12350);
			t_sample L_w0_lo_12352 = safediv((((t_sample)6.2831853071796) * L_loF_12349), L_sr_12348);
			t_sample L_cos_lo_12353 = cos(L_w0_lo_12352);
			t_sample L_sin_lo_12354 = sin(L_w0_lo_12352);
			t_sample L_alpha_lo_12355 = (L_sin_lo_12354 * ((t_sample)0.70710678118655));
			t_sample L_a0_lo_12356 = (((int)1) + L_alpha_lo_12355);
			t_sample L_a1_lo_12357 = (((int)-2) * L_cos_lo_12353);
			t_sample L_a2_lo_12358 = (((int)1) - L_alpha_lo_12355);
			t_sample L_lp_b0_l_12359 = safediv(((((int)1) - L_cos_lo_12353) * ((t_sample)0.5)), L_a0_lo_12356);
			t_sample L_lp_b1_l_12360 = safediv((((int)1) - L_cos_lo_12353), L_a0_lo_12356);
			t_sample L_lp_b2_l_12361 = L_lp_b0_l_12359;
			t_sample L_lp_a1_l_12362 = safediv(L_a1_lo_12357, L_a0_lo_12356);
			t_sample L_lp_a2_l_12363 = safediv(L_a2_lo_12358, L_a0_lo_12356);
			t_sample L_hp_b0_l_12364 = safediv(((((int)1) + L_cos_lo_12353) * ((t_sample)0.5)), L_a0_lo_12356);
			t_sample L_hp_b1_l_12365 = safediv((-(((int)1) + L_cos_lo_12353)), L_a0_lo_12356);
			t_sample L_hp_b2_l_12366 = L_hp_b0_l_12364;
			t_sample L_hp_a1_l_12367 = L_lp_a1_l_12362;
			t_sample L_hp_a2_l_12368 = L_lp_a2_l_12363;
			t_sample L_w0_hi_12369 = safediv((((t_sample)6.2831853071796) * L_hiF_12351), L_sr_12348);
			t_sample L_cos_hi_12370 = cos(L_w0_hi_12369);
			t_sample L_sin_hi_12371 = sin(L_w0_hi_12369);
			t_sample L_alpha_hi_12372 = (L_sin_hi_12371 * ((t_sample)0.70710678118655));
			t_sample L_a0_hi_12373 = (((int)1) + L_alpha_hi_12372);
			t_sample L_a1_hi_12374 = (((int)-2) * L_cos_hi_12370);
			t_sample L_a2_hi_12375 = (((int)1) - L_alpha_hi_12372);
			t_sample L_lp_b0_h_12376 = safediv(((((int)1) - L_cos_hi_12370) * ((t_sample)0.5)), L_a0_hi_12373);
			t_sample L_lp_b1_h_12377 = safediv((((int)1) - L_cos_hi_12370), L_a0_hi_12373);
			t_sample L_lp_b2_h_12378 = L_lp_b0_h_12376;
			t_sample L_lp_a1_h_12379 = safediv(L_a1_hi_12374, L_a0_hi_12373);
			t_sample L_lp_a2_h_12380 = safediv(L_a2_hi_12375, L_a0_hi_12373);
			t_sample L_hp_b0_h_12381 = safediv(((((int)1) + L_cos_hi_12370) * ((t_sample)0.5)), L_a0_hi_12373);
			t_sample L_hp_b1_h_12382 = safediv((-(((int)1) + L_cos_hi_12370)), L_a0_hi_12373);
			t_sample L_hp_b2_h_12383 = L_hp_b0_h_12381;
			t_sample L_hp_a1_h_12384 = L_lp_a1_h_12379;
			t_sample L_hp_a2_h_12385 = L_lp_a2_h_12380;
			t_sample L_ap1_lp1_x1p = m_L_ap1_lp1_x_16;
			t_sample L_ap1_lp1_x2p = m_L_ap1_lp1_x_241;
			t_sample L_ap1_lp1_y1p = m_L_ap1_lp1_y_240;
			t_sample L_ap1_lp1_y2p = m_L_ap1_lp1_y_239;
			t_sample L_ap1_lp_s1 = (((((L_lp_b0_l_12359 * L_x_12345) + (L_lp_b1_l_12360 * L_ap1_lp1_x1p)) + (L_lp_b2_l_12361 * L_ap1_lp1_x2p)) - (L_lp_a1_l_12362 * L_ap1_lp1_y1p)) - (L_lp_a2_l_12363 * L_ap1_lp1_y2p));
			m_L_ap1_lp1_x_241 = L_ap1_lp1_x1p;
			m_L_ap1_lp1_x_16 = L_x_12345;
			m_L_ap1_lp1_y_239 = L_ap1_lp1_y1p;
			m_L_ap1_lp1_y_240 = L_ap1_lp_s1;
			t_sample L_ap1_lp2_x1p = m_L_ap1_lp2_x_14;
			t_sample L_ap1_lp2_x2p = m_L_ap1_lp2_x_238;
			t_sample L_ap1_lp2_y1p = m_L_ap1_lp2_y_237;
			t_sample L_ap1_lp2_y2p = m_L_ap1_lp2_y_236;
			t_sample L_ap1_lp = (((((L_lp_b0_l_12359 * L_ap1_lp_s1) + (L_lp_b1_l_12360 * L_ap1_lp2_x1p)) + (L_lp_b2_l_12361 * L_ap1_lp2_x2p)) - (L_lp_a1_l_12362 * L_ap1_lp2_y1p)) - (L_lp_a2_l_12363 * L_ap1_lp2_y2p));
			m_L_ap1_lp2_x_238 = L_ap1_lp2_x1p;
			m_L_ap1_lp2_x_14 = L_ap1_lp_s1;
			m_L_ap1_lp2_y_236 = L_ap1_lp2_y1p;
			m_L_ap1_lp2_y_237 = L_ap1_lp;
			t_sample L_ap1_hp1_x1p = m_L_ap1_hp1_x_12;
			t_sample L_ap1_hp1_x2p = m_L_ap1_hp1_x_235;
			t_sample L_ap1_hp1_y1p = m_L_ap1_hp1_y_234;
			t_sample L_ap1_hp1_y2p = m_L_ap1_hp1_y_233;
			t_sample L_ap1_hp_s1 = (((((L_hp_b0_l_12364 * L_x_12345) + (L_hp_b1_l_12365 * L_ap1_hp1_x1p)) + (L_hp_b2_l_12366 * L_ap1_hp1_x2p)) - (L_hp_a1_l_12367 * L_ap1_hp1_y1p)) - (L_hp_a2_l_12368 * L_ap1_hp1_y2p));
			m_L_ap1_hp1_x_235 = L_ap1_hp1_x1p;
			m_L_ap1_hp1_x_12 = L_x_12345;
			m_L_ap1_hp1_y_233 = L_ap1_hp1_y1p;
			m_L_ap1_hp1_y_234 = L_ap1_hp_s1;
			t_sample L_ap1_hp2_x1p = m_L_ap1_hp2_x_10;
			t_sample L_ap1_hp2_x2p = m_L_ap1_hp2_x_232;
			t_sample L_ap1_hp2_y1p = m_L_ap1_hp2_y_231;
			t_sample L_ap1_hp2_y2p = m_L_ap1_hp2_y_230;
			t_sample L_ap1_hp = (((((L_hp_b0_l_12364 * L_ap1_hp_s1) + (L_hp_b1_l_12365 * L_ap1_hp2_x1p)) + (L_hp_b2_l_12366 * L_ap1_hp2_x2p)) - (L_hp_a1_l_12367 * L_ap1_hp2_y1p)) - (L_hp_a2_l_12368 * L_ap1_hp2_y2p));
			m_L_ap1_hp2_x_232 = L_ap1_hp2_x1p;
			m_L_ap1_hp2_x_10 = L_ap1_hp_s1;
			m_L_ap1_hp2_y_230 = L_ap1_hp2_y1p;
			m_L_ap1_hp2_y_231 = L_ap1_hp;
			t_sample L_stage1_out = (L_ap1_lp + L_ap1_hp);
			t_sample L_ap2_lp1_x1p = m_L_ap2_lp1_x_8;
			t_sample L_ap2_lp1_x2p = m_L_ap2_lp1_x_229;
			t_sample L_ap2_lp1_y1p = m_L_ap2_lp1_y_228;
			t_sample L_ap2_lp1_y2p = m_L_ap2_lp1_y_227;
			t_sample L_ap2_lp_s1 = (((((L_lp_b0_h_12376 * L_stage1_out) + (L_lp_b1_h_12377 * L_ap2_lp1_x1p)) + (L_lp_b2_h_12378 * L_ap2_lp1_x2p)) - (L_lp_a1_h_12379 * L_ap2_lp1_y1p)) - (L_lp_a2_h_12380 * L_ap2_lp1_y2p));
			m_L_ap2_lp1_x_229 = L_ap2_lp1_x1p;
			m_L_ap2_lp1_x_8 = L_stage1_out;
			m_L_ap2_lp1_y_227 = L_ap2_lp1_y1p;
			m_L_ap2_lp1_y_228 = L_ap2_lp_s1;
			t_sample L_ap2_lp2_x1p = m_L_ap2_lp2_x_6;
			t_sample L_ap2_lp2_x2p = m_L_ap2_lp2_x_226;
			t_sample L_ap2_lp2_y1p = m_L_ap2_lp2_y_225;
			t_sample L_ap2_lp2_y2p = m_L_ap2_lp2_y_224;
			t_sample L_ap2_lp = (((((L_lp_b0_h_12376 * L_ap2_lp_s1) + (L_lp_b1_h_12377 * L_ap2_lp2_x1p)) + (L_lp_b2_h_12378 * L_ap2_lp2_x2p)) - (L_lp_a1_h_12379 * L_ap2_lp2_y1p)) - (L_lp_a2_h_12380 * L_ap2_lp2_y2p));
			m_L_ap2_lp2_x_226 = L_ap2_lp2_x1p;
			m_L_ap2_lp2_x_6 = L_ap2_lp_s1;
			m_L_ap2_lp2_y_224 = L_ap2_lp2_y1p;
			m_L_ap2_lp2_y_225 = L_ap2_lp;
			t_sample L_ap2_hp1_x1p = m_L_ap2_hp1_x_4;
			t_sample L_ap2_hp1_x2p = m_L_ap2_hp1_x_223;
			t_sample L_ap2_hp1_y1p = m_L_ap2_hp1_y_222;
			t_sample L_ap2_hp1_y2p = m_L_ap2_hp1_y_221;
			t_sample L_ap2_hp_s1 = (((((L_hp_b0_h_12381 * L_stage1_out) + (L_hp_b1_h_12382 * L_ap2_hp1_x1p)) + (L_hp_b2_h_12383 * L_ap2_hp1_x2p)) - (L_hp_a1_h_12384 * L_ap2_hp1_y1p)) - (L_hp_a2_h_12385 * L_ap2_hp1_y2p));
			m_L_ap2_hp1_x_223 = L_ap2_hp1_x1p;
			m_L_ap2_hp1_x_4 = L_stage1_out;
			m_L_ap2_hp1_y_221 = L_ap2_hp1_y1p;
			m_L_ap2_hp1_y_222 = L_ap2_hp_s1;
			t_sample L_ap2_hp2_x1p = m_L_ap2_hp2_x_2;
			t_sample L_ap2_hp2_x2p = m_L_ap2_hp2_x_220;
			t_sample L_ap2_hp2_y1p = m_L_ap2_hp2_y_219;
			t_sample L_ap2_hp2_y2p = m_L_ap2_hp2_y_218;
			t_sample L_ap2_hp = (((((L_hp_b0_h_12381 * L_ap2_hp_s1) + (L_hp_b1_h_12382 * L_ap2_hp2_x1p)) + (L_hp_b2_h_12383 * L_ap2_hp2_x2p)) - (L_hp_a1_h_12384 * L_ap2_hp2_y1p)) - (L_hp_a2_h_12385 * L_ap2_hp2_y2p));
			m_L_ap2_hp2_x_220 = L_ap2_hp2_x1p;
			m_L_ap2_hp2_x_2 = L_ap2_hp_s1;
			m_L_ap2_hp2_y_218 = L_ap2_hp2_y1p;
			m_L_ap2_hp2_y_219 = L_ap2_hp;
			t_sample dryCompL = (L_ap2_lp + L_ap2_hp);
			t_sample R_loF_12386 = smoothHpfFreq;
			t_sample R_hiF_12387 = smoothLpfFreq;
			t_sample R_x_12388 = rTrimmed;
			t_sample maxb_315 = ((minb_314 < R_loF_12386) ? minb_314 : R_loF_12386);
			t_sample R_loF_12392 = ((((int)10) < maxb_315) ? maxb_315 : ((int)10));
			t_sample maxb_317 = ((minb_316 < R_hiF_12387) ? minb_316 : R_hiF_12387);
			t_sample R_hiFr_12393 = ((((int)10) < maxb_317) ? maxb_317 : ((int)10));
			t_sample maxb_318 = (R_loF_12392 + ((int)1));
			t_sample R_hiF_12394 = ((R_hiFr_12393 < maxb_318) ? maxb_318 : R_hiFr_12393);
			t_sample R_w0_lo_12395 = safediv((((t_sample)6.2831853071796) * R_loF_12392), R_sr_12391);
			t_sample R_cos_lo_12396 = cos(R_w0_lo_12395);
			t_sample R_sin_lo_12397 = sin(R_w0_lo_12395);
			t_sample R_alpha_lo_12398 = (R_sin_lo_12397 * ((t_sample)0.70710678118655));
			t_sample R_a0_lo_12399 = (((int)1) + R_alpha_lo_12398);
			t_sample R_a1_lo_12400 = (((int)-2) * R_cos_lo_12396);
			t_sample R_a2_lo_12401 = (((int)1) - R_alpha_lo_12398);
			t_sample R_lp_b0_l_12402 = safediv(((((int)1) - R_cos_lo_12396) * ((t_sample)0.5)), R_a0_lo_12399);
			t_sample R_lp_b1_l_12403 = safediv((((int)1) - R_cos_lo_12396), R_a0_lo_12399);
			t_sample R_lp_b2_l_12404 = R_lp_b0_l_12402;
			t_sample R_lp_a1_l_12405 = safediv(R_a1_lo_12400, R_a0_lo_12399);
			t_sample R_lp_a2_l_12406 = safediv(R_a2_lo_12401, R_a0_lo_12399);
			t_sample R_hp_b0_l_12407 = safediv(((((int)1) + R_cos_lo_12396) * ((t_sample)0.5)), R_a0_lo_12399);
			t_sample R_hp_b1_l_12408 = safediv((-(((int)1) + R_cos_lo_12396)), R_a0_lo_12399);
			t_sample R_hp_b2_l_12409 = R_hp_b0_l_12407;
			t_sample R_hp_a1_l_12410 = R_lp_a1_l_12405;
			t_sample R_hp_a2_l_12411 = R_lp_a2_l_12406;
			t_sample R_w0_hi_12412 = safediv((((t_sample)6.2831853071796) * R_hiF_12394), R_sr_12391);
			t_sample R_cos_hi_12413 = cos(R_w0_hi_12412);
			t_sample R_sin_hi_12414 = sin(R_w0_hi_12412);
			t_sample R_alpha_hi_12415 = (R_sin_hi_12414 * ((t_sample)0.70710678118655));
			t_sample R_a0_hi_12416 = (((int)1) + R_alpha_hi_12415);
			t_sample R_a1_hi_12417 = (((int)-2) * R_cos_hi_12413);
			t_sample R_a2_hi_12418 = (((int)1) - R_alpha_hi_12415);
			t_sample R_lp_b0_h_12419 = safediv(((((int)1) - R_cos_hi_12413) * ((t_sample)0.5)), R_a0_hi_12416);
			t_sample R_lp_b1_h_12420 = safediv((((int)1) - R_cos_hi_12413), R_a0_hi_12416);
			t_sample R_lp_b2_h_12421 = R_lp_b0_h_12419;
			t_sample R_lp_a1_h_12422 = safediv(R_a1_hi_12417, R_a0_hi_12416);
			t_sample R_lp_a2_h_12423 = safediv(R_a2_hi_12418, R_a0_hi_12416);
			t_sample R_hp_b0_h_12424 = safediv(((((int)1) + R_cos_hi_12413) * ((t_sample)0.5)), R_a0_hi_12416);
			t_sample R_hp_b1_h_12425 = safediv((-(((int)1) + R_cos_hi_12413)), R_a0_hi_12416);
			t_sample R_hp_b2_h_12426 = R_hp_b0_h_12424;
			t_sample R_hp_a1_h_12427 = R_lp_a1_h_12422;
			t_sample R_hp_a2_h_12428 = R_lp_a2_h_12423;
			t_sample R_ap1_lp1_x1p = m_R_ap1_lp1_x_15;
			t_sample R_ap1_lp1_x2p = m_R_ap1_lp1_x_181;
			t_sample R_ap1_lp1_y1p = m_R_ap1_lp1_y_180;
			t_sample R_ap1_lp1_y2p = m_R_ap1_lp1_y_179;
			t_sample R_ap1_lp_s1 = (((((R_lp_b0_l_12402 * R_x_12388) + (R_lp_b1_l_12403 * R_ap1_lp1_x1p)) + (R_lp_b2_l_12404 * R_ap1_lp1_x2p)) - (R_lp_a1_l_12405 * R_ap1_lp1_y1p)) - (R_lp_a2_l_12406 * R_ap1_lp1_y2p));
			m_R_ap1_lp1_x_181 = R_ap1_lp1_x1p;
			m_R_ap1_lp1_x_15 = R_x_12388;
			m_R_ap1_lp1_y_179 = R_ap1_lp1_y1p;
			m_R_ap1_lp1_y_180 = R_ap1_lp_s1;
			t_sample R_ap1_lp2_x1p = m_R_ap1_lp2_x_13;
			t_sample R_ap1_lp2_x2p = m_R_ap1_lp2_x_178;
			t_sample R_ap1_lp2_y1p = m_R_ap1_lp2_y_177;
			t_sample R_ap1_lp2_y2p = m_R_ap1_lp2_y_176;
			t_sample R_ap1_lp = (((((R_lp_b0_l_12402 * R_ap1_lp_s1) + (R_lp_b1_l_12403 * R_ap1_lp2_x1p)) + (R_lp_b2_l_12404 * R_ap1_lp2_x2p)) - (R_lp_a1_l_12405 * R_ap1_lp2_y1p)) - (R_lp_a2_l_12406 * R_ap1_lp2_y2p));
			m_R_ap1_lp2_x_178 = R_ap1_lp2_x1p;
			m_R_ap1_lp2_x_13 = R_ap1_lp_s1;
			m_R_ap1_lp2_y_176 = R_ap1_lp2_y1p;
			m_R_ap1_lp2_y_177 = R_ap1_lp;
			t_sample R_ap1_hp1_x1p = m_R_ap1_hp1_x_11;
			t_sample R_ap1_hp1_x2p = m_R_ap1_hp1_x_175;
			t_sample R_ap1_hp1_y1p = m_R_ap1_hp1_y_174;
			t_sample R_ap1_hp1_y2p = m_R_ap1_hp1_y_173;
			t_sample R_ap1_hp_s1 = (((((R_hp_b0_l_12407 * R_x_12388) + (R_hp_b1_l_12408 * R_ap1_hp1_x1p)) + (R_hp_b2_l_12409 * R_ap1_hp1_x2p)) - (R_hp_a1_l_12410 * R_ap1_hp1_y1p)) - (R_hp_a2_l_12411 * R_ap1_hp1_y2p));
			m_R_ap1_hp1_x_175 = R_ap1_hp1_x1p;
			m_R_ap1_hp1_x_11 = R_x_12388;
			m_R_ap1_hp1_y_173 = R_ap1_hp1_y1p;
			m_R_ap1_hp1_y_174 = R_ap1_hp_s1;
			t_sample R_ap1_hp2_x1p = m_R_ap1_hp2_x_9;
			t_sample R_ap1_hp2_x2p = m_R_ap1_hp2_x_172;
			t_sample R_ap1_hp2_y1p = m_R_ap1_hp2_y_171;
			t_sample R_ap1_hp2_y2p = m_R_ap1_hp2_y_170;
			t_sample R_ap1_hp = (((((R_hp_b0_l_12407 * R_ap1_hp_s1) + (R_hp_b1_l_12408 * R_ap1_hp2_x1p)) + (R_hp_b2_l_12409 * R_ap1_hp2_x2p)) - (R_hp_a1_l_12410 * R_ap1_hp2_y1p)) - (R_hp_a2_l_12411 * R_ap1_hp2_y2p));
			m_R_ap1_hp2_x_172 = R_ap1_hp2_x1p;
			m_R_ap1_hp2_x_9 = R_ap1_hp_s1;
			m_R_ap1_hp2_y_170 = R_ap1_hp2_y1p;
			m_R_ap1_hp2_y_171 = R_ap1_hp;
			t_sample R_stage1_out = (R_ap1_lp + R_ap1_hp);
			t_sample R_ap2_lp1_x1p = m_R_ap2_lp1_x_7;
			t_sample R_ap2_lp1_x2p = m_R_ap2_lp1_x_169;
			t_sample R_ap2_lp1_y1p = m_R_ap2_lp1_y_168;
			t_sample R_ap2_lp1_y2p = m_R_ap2_lp1_y_167;
			t_sample R_ap2_lp_s1 = (((((R_lp_b0_h_12419 * R_stage1_out) + (R_lp_b1_h_12420 * R_ap2_lp1_x1p)) + (R_lp_b2_h_12421 * R_ap2_lp1_x2p)) - (R_lp_a1_h_12422 * R_ap2_lp1_y1p)) - (R_lp_a2_h_12423 * R_ap2_lp1_y2p));
			m_R_ap2_lp1_x_169 = R_ap2_lp1_x1p;
			m_R_ap2_lp1_x_7 = R_stage1_out;
			m_R_ap2_lp1_y_167 = R_ap2_lp1_y1p;
			m_R_ap2_lp1_y_168 = R_ap2_lp_s1;
			t_sample R_ap2_lp2_x1p = m_R_ap2_lp2_x_5;
			t_sample R_ap2_lp2_x2p = m_R_ap2_lp2_x_166;
			t_sample R_ap2_lp2_y1p = m_R_ap2_lp2_y_165;
			t_sample R_ap2_lp2_y2p = m_R_ap2_lp2_y_164;
			t_sample R_ap2_lp = (((((R_lp_b0_h_12419 * R_ap2_lp_s1) + (R_lp_b1_h_12420 * R_ap2_lp2_x1p)) + (R_lp_b2_h_12421 * R_ap2_lp2_x2p)) - (R_lp_a1_h_12422 * R_ap2_lp2_y1p)) - (R_lp_a2_h_12423 * R_ap2_lp2_y2p));
			m_R_ap2_lp2_x_166 = R_ap2_lp2_x1p;
			m_R_ap2_lp2_x_5 = R_ap2_lp_s1;
			m_R_ap2_lp2_y_164 = R_ap2_lp2_y1p;
			m_R_ap2_lp2_y_165 = R_ap2_lp;
			t_sample R_ap2_hp1_x1p = m_R_ap2_hp1_x_3;
			t_sample R_ap2_hp1_x2p = m_R_ap2_hp1_x_163;
			t_sample R_ap2_hp1_y1p = m_R_ap2_hp1_y_162;
			t_sample R_ap2_hp1_y2p = m_R_ap2_hp1_y_161;
			t_sample R_ap2_hp_s1 = (((((R_hp_b0_h_12424 * R_stage1_out) + (R_hp_b1_h_12425 * R_ap2_hp1_x1p)) + (R_hp_b2_h_12426 * R_ap2_hp1_x2p)) - (R_hp_a1_h_12427 * R_ap2_hp1_y1p)) - (R_hp_a2_h_12428 * R_ap2_hp1_y2p));
			m_R_ap2_hp1_x_163 = R_ap2_hp1_x1p;
			m_R_ap2_hp1_x_3 = R_stage1_out;
			m_R_ap2_hp1_y_161 = R_ap2_hp1_y1p;
			m_R_ap2_hp1_y_162 = R_ap2_hp_s1;
			t_sample R_ap2_hp2_x1p = m_R_ap2_hp2_x_1;
			t_sample R_ap2_hp2_x2p = m_R_ap2_hp2_x_160;
			t_sample R_ap2_hp2_y1p = m_R_ap2_hp2_y_159;
			t_sample R_ap2_hp2_y2p = m_R_ap2_hp2_y_158;
			t_sample R_ap2_hp = (((((R_hp_b0_h_12424 * R_ap2_hp_s1) + (R_hp_b1_h_12425 * R_ap2_hp2_x1p)) + (R_hp_b2_h_12426 * R_ap2_hp2_x2p)) - (R_hp_a1_h_12427 * R_ap2_hp2_y1p)) - (R_hp_a2_h_12428 * R_ap2_hp2_y2p));
			m_R_ap2_hp2_x_160 = R_ap2_hp2_x1p;
			m_R_ap2_hp2_x_1 = R_ap2_hp_s1;
			m_R_ap2_hp2_y_158 = R_ap2_hp2_y1p;
			m_R_ap2_hp2_y_159 = R_ap2_hp;
			t_sample dryCompR = (R_ap2_lp + R_ap2_hp);
			t_sample mix_12458 = (lIn + (scSm * (dryCompL - lIn)));
			t_sample mix_12459 = (rIn + (scSm * (dryCompR - rIn)));
			t_sample lFiltered = preDistInL;
			t_sample rFiltered = preDistInR;
			t_sample Gls = (-tiltDb);
			t_sample Ghs = tiltDb;
			t_sample Als = sqrt(dbtoa(Gls));
			t_sample Ahs = sqrt(dbtoa(Ghs));
			t_sample alphaLs = ((((t_sample)0.5) * sn) * sqrt((((Als + safediv(((int)1), Als)) * ((int)0)) + ((int)2))));
			t_sample alphaHs = ((((t_sample)0.5) * sn) * sqrt((((Ahs + safediv(((int)1), Ahs)) * ((int)0)) + ((int)2))));
			t_sample sqrtAls = sqrt(Als);
			t_sample sqrtAhs = sqrt(Ahs);
			t_sample b0_ls = (Als * (((Als + ((int)1)) - ((Als - ((int)1)) * cs)) + ((((int)2) * sqrtAls) * alphaLs)));
			t_sample b1_ls = ((((int)2) * Als) * ((Als - ((int)1)) - ((Als + ((int)1)) * cs)));
			t_sample b2_ls = (Als * (((Als + ((int)1)) - ((Als - ((int)1)) * cs)) - ((((int)2) * sqrtAls) * alphaLs)));
			t_sample a0_ls = (((Als + ((int)1)) + ((Als - ((int)1)) * cs)) + ((((int)2) * sqrtAls) * alphaLs));
			t_sample a1_ls = (((int)-2) * ((Als - ((int)1)) + ((Als + ((int)1)) * cs)));
			t_sample a2_ls = (((Als + ((int)1)) + ((Als - ((int)1)) * cs)) - ((((int)2) * sqrtAls) * alphaLs));
			t_sample inv_a0_ls = safediv(((int)1), a0_ls);
			t_sample a0Ls = (b0_ls * inv_a0_ls);
			t_sample a1Ls = (b1_ls * inv_a0_ls);
			t_sample a2Ls = (b2_ls * inv_a0_ls);
			t_sample b1Ls = (a1_ls * inv_a0_ls);
			t_sample b2Ls = (a2_ls * inv_a0_ls);
			t_sample lLs_12429 = (((((a0Ls * lFiltered) + (a1Ls * m_tiltLsL_55)) + (a2Ls * m_tiltLsL_56)) - (b1Ls * m_tiltLsL_53)) - (b2Ls * m_tiltLsL_54));
			m_tiltLsL_56 = m_tiltLsL_55;
			m_tiltLsL_55 = lFiltered;
			m_tiltLsL_54 = m_tiltLsL_53;
			m_tiltLsL_53 = lLs_12429;
			t_sample rLs_12430 = (((((a0Ls * rFiltered) + (a1Ls * m_tiltLsR_51)) + (a2Ls * m_tiltLsR_52)) - (b1Ls * m_tiltLsR_49)) - (b2Ls * m_tiltLsR_50));
			m_tiltLsR_52 = m_tiltLsR_51;
			m_tiltLsR_51 = rFiltered;
			m_tiltLsR_50 = m_tiltLsR_49;
			m_tiltLsR_49 = rLs_12430;
			t_sample b0_hs = (Ahs * (((Ahs + ((int)1)) + ((Ahs - ((int)1)) * cs)) + ((((int)2) * sqrtAhs) * alphaHs)));
			t_sample b1_hs = ((((int)-2) * Ahs) * ((Ahs - ((int)1)) + ((Ahs + ((int)1)) * cs)));
			t_sample b2_hs = (Ahs * (((Ahs + ((int)1)) + ((Ahs - ((int)1)) * cs)) - ((((int)2) * sqrtAhs) * alphaHs)));
			t_sample a0_hs = (((Ahs + ((int)1)) - ((Ahs - ((int)1)) * cs)) + ((((int)2) * sqrtAhs) * alphaHs));
			t_sample a1_hs = (((int)2) * ((Ahs - ((int)1)) - ((Ahs + ((int)1)) * cs)));
			t_sample a2_hs = (((Ahs + ((int)1)) - ((Ahs - ((int)1)) * cs)) - ((((int)2) * sqrtAhs) * alphaHs));
			t_sample inv_a0_hs = safediv(((int)1), a0_hs);
			t_sample a0Hs = (b0_hs * inv_a0_hs);
			t_sample a1Hs = (b1_hs * inv_a0_hs);
			t_sample a2Hs = (b2_hs * inv_a0_hs);
			t_sample b1Hs = (a1_hs * inv_a0_hs);
			t_sample b2Hs = (a2_hs * inv_a0_hs);
			t_sample lTiltRaw = (((((a0Hs * lLs_12429) + (a1Hs * m_tiltHsL_47)) + (a2Hs * m_tiltHsL_48)) - (b1Hs * m_tiltHsL_45)) - (b2Hs * m_tiltHsL_46));
			m_tiltHsL_48 = m_tiltHsL_47;
			m_tiltHsL_47 = lLs_12429;
			m_tiltHsL_46 = m_tiltHsL_45;
			m_tiltHsL_45 = lTiltRaw;
			t_sample rTiltRaw = (((((a0Hs * rLs_12430) + (a1Hs * m_tiltHsR_43)) + (a2Hs * m_tiltHsR_44)) - (b1Hs * m_tiltHsR_41)) - (b2Hs * m_tiltHsR_42));
			m_tiltHsR_44 = m_tiltHsR_43;
			m_tiltHsR_43 = rLs_12430;
			m_tiltHsR_42 = m_tiltHsR_41;
			m_tiltHsR_41 = rTiltRaw;
			t_sample nr_ls = ((a0Ls + (a1Ls * cs)) + (a2Ls * cos2));
			t_sample ni_ls = (-((a1Ls * sn) + (a2Ls * sin2)));
			t_sample dr_ls = ((((int)1) + (b1Ls * cs)) + (b2Ls * cos2));
			t_sample di_ls = (-((b1Ls * sn) + (b2Ls * sin2)));
			t_sample maxb_319 = ((dr_ls * dr_ls) + (di_ls * di_ls));
			t_sample mag2_ls = safediv(((nr_ls * nr_ls) + (ni_ls * ni_ls)), ((((t_sample)1e-12) < maxb_319) ? maxb_319 : ((t_sample)1e-12)));
			t_sample mag_ls = sqrt(mag2_ls);
			t_sample nr_hs = ((a0Hs + (a1Hs * cs)) + (a2Hs * cos2));
			t_sample ni_hs = (-((a1Hs * sn) + (a2Hs * sin2)));
			t_sample dr_hs = ((((int)1) + (b1Hs * cs)) + (b2Hs * cos2));
			t_sample di_hs = (-((b1Hs * sn) + (b2Hs * sin2)));
			t_sample maxb_320 = ((dr_hs * dr_hs) + (di_hs * di_hs));
			t_sample mag2_hs = safediv(((nr_hs * nr_hs) + (ni_hs * ni_hs)), ((((t_sample)1e-12) < maxb_320) ? maxb_320 : ((t_sample)1e-12)));
			t_sample mag_hs = sqrt(mag2_hs);
			t_sample maxb_321 = (mag_ls * mag_hs);
			t_sample gPivot = safediv(((int)1), ((((t_sample)1e-09) < maxb_321) ? maxb_321 : ((t_sample)1e-09)));
			t_sample lTilt = (lTiltRaw * gPivot);
			t_sample rTilt = (rTiltRaw * gPivot);
			t_sample return_324;
			t_sample return_325;
			softclip_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_324, return_325);
			t_sample softL = return_324;
			t_sample softR = return_325;
			t_sample return_330;
			t_sample return_331;
			sigmoid_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_330, return_331);
			t_sample sigmL = return_330;
			t_sample sigmR = return_331;
			t_sample return_334;
			t_sample return_335;
			rectF_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_334, return_335);
			t_sample rectL = return_334;
			t_sample rectR = return_335;
			t_sample return_338;
			t_sample return_339;
			fuzzExp1_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_338, return_339);
			t_sample fuzz1L = return_338;
			t_sample fuzz1R = return_339;
			t_sample return_344;
			t_sample return_345;
			tangenteHiperbolica_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_344, return_345);
			t_sample tanhL = return_344;
			t_sample tanhR = return_345;
			t_sample return_350;
			t_sample return_351;
			rectH_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_350, return_351);
			t_sample recthL = return_350;
			t_sample recthR = return_351;
			t_sample return_352;
			t_sample return_353;
			arctangent_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_352, return_353);
			t_sample atanL = return_352;
			t_sample atanR = return_353;
			t_sample return_362;
			t_sample return_363;
			hardClip_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_362, return_363);
			t_sample hardL = return_362;
			t_sample hardR = return_363;
			t_sample maxb_364 = (((int)1) - fabs((smoothedMode - ((int)0))));
			t_sample w0 = ((((int)0) < maxb_364) ? maxb_364 : ((int)0));
			t_sample maxb_365 = (((int)1) - fabs((smoothedMode - ((int)1))));
			t_sample w1 = ((((int)0) < maxb_365) ? maxb_365 : ((int)0));
			t_sample maxb_366 = (((int)1) - fabs((smoothedMode - ((int)2))));
			t_sample w2 = ((((int)0) < maxb_366) ? maxb_366 : ((int)0));
			t_sample maxb_367 = (((int)1) - fabs((smoothedMode - ((int)3))));
			t_sample w3 = ((((int)0) < maxb_367) ? maxb_367 : ((int)0));
			t_sample maxb_368 = (((int)1) - fabs((smoothedMode - ((int)4))));
			t_sample w4 = ((((int)0) < maxb_368) ? maxb_368 : ((int)0));
			t_sample maxb_369 = (((int)1) - fabs((smoothedMode - ((int)5))));
			t_sample w5 = ((((int)0) < maxb_369) ? maxb_369 : ((int)0));
			t_sample maxb_370 = (((int)1) - fabs((smoothedMode - ((int)6))));
			t_sample w6 = ((((int)0) < maxb_370) ? maxb_370 : ((int)0));
			t_sample maxb_371 = (((int)1) - fabs((smoothedMode - ((int)7))));
			t_sample w7 = ((((int)0) < maxb_371) ? maxb_371 : ((int)0));
			t_sample sumWeights = ((((((((w0 + w1) + w2) + w3) + w4) + w5) + w6) + w7) + ((t_sample)0.0001));
			t_sample w_12431 = safediv(w0, sumWeights);
			t_sample w_12432 = safediv(w1, sumWeights);
			t_sample w_12433 = safediv(w2, sumWeights);
			t_sample w_12434 = safediv(w3, sumWeights);
			t_sample w_12435 = safediv(w4, sumWeights);
			t_sample w_12436 = safediv(w5, sumWeights);
			t_sample w_12437 = safediv(w6, sumWeights);
			t_sample w_12438 = safediv(w7, sumWeights);
			t_sample distL = ((((((((softL * w_12431) + (sigmL * w_12432)) + (rectL * w_12433)) + (fuzz1L * w_12434)) + (tanhL * w_12435)) + (recthL * w_12436)) + (atanL * w_12437)) + (hardL * w_12438));
			t_sample distR = ((((((((softR * w_12431) + (sigmR * w_12432)) + (rectR * w_12433)) + (fuzz1R * w_12434)) + (tanhR * w_12435)) + (recthR * w_12436)) + (atanR * w_12437)) + (hardR * w_12438));
			t_sample processedL = __m_dcblock_372(distL);
			t_sample processedR = __m_dcblock_373(distR);
			t_sample return_374;
			t_sample return_375;
			bitCrusher_d_d_d(processedL, processedR, bits, return_374, return_375);
			t_sample bitL = return_374;
			t_sample bitR = return_375;
			t_sample bcL = __m_dcblock_376(bitL);
			t_sample bcR = __m_dcblock_377(bitR);
			t_sample mix_12460 = (processedL + (bitson * (bcL - processedL)));
			t_sample mix_12461 = (processedR + (bitson * (bcR - processedR)));
			t_sample deciFactor = (m_hDownsample_67 + ((int)1));
			t_sample deciFreq = safediv((samplerate * ((t_sample)0.5)), deciFactor);
			m_dsPhasor_57 = __m_phasor_378(deciFreq, samples_to_seconds);
			int dsTrigger = (m_dsPhasor_57 > ((t_sample)0.5));
			__m_latch_379 = ((dsTrigger != 0) ? mix_12460 : __m_latch_379);
			t_sample dsHeldL = __m_latch_379;
			__m_latch_380 = ((dsTrigger != 0) ? mix_12461 : __m_latch_380);
			t_sample dsHeldR = __m_latch_380;
			t_sample mix_12462 = (mix_12460 + (downsampleOn * (dsHeldL - mix_12460)));
			t_sample mix_12463 = (mix_12461 + (downsampleOn * (dsHeldR - mix_12461)));
			t_sample wetWithMakeupL = ((mix_12462 * outputMakeupLinear) + (bypassWhenActiveL * scSm));
			t_sample wetWithMakeupR = ((mix_12463 * outputMakeupLinear) + (bypassWhenActiveR * scSm));
			t_sample mix_12464 = (mix_12458 + (drywet * (wetWithMakeupL - mix_12458)));
			t_sample mix_12465 = (mix_12459 + (drywet * (wetWithMakeupR - mix_12459)));
			t_sample finalDcBlockedL = __m_dcblock_381(mix_12464);
			t_sample finalDcBlockedR = __m_dcblock_382(mix_12465);
			t_sample mix_12466 = (lIn + (bypass * (finalDcBlockedL - lIn)));
			t_sample mix_12467 = (rIn + (bypass * (finalDcBlockedR - rIn)));
			t_sample out2 = mix_12467;
			t_sample out3 = ((int)0);
			t_sample out1 = mix_12466;
			t_sample out5 = rTrimmed;
			t_sample out4 = lTrimmed;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			(*(__out4++)) = out4;
			(*(__out5++)) = out5;
			
		};
		return __exception;
		
	};
	inline void set_o_BAND(t_param _value) {
		m_o_BAND_278 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_n_DOWNSAMPLEON(t_param _value) {
		m_n_DOWNSAMPLEON_279 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_m_DOWNSAMPLE(t_param _value) {
		m_m_DOWNSAMPLE_280 = (_value < 0 ? 0 : (_value > 99 ? 99 : _value));
	};
	inline void set_l_OUTPUT(t_param _value) {
		m_l_OUTPUT_281 = (_value < -12 ? -12 : (_value > 12 ? 12 : _value));
	};
	inline void set_k_INPUT(t_param _value) {
		m_k_INPUT_282 = (_value < -12 ? -12 : (_value > 12 ? 12 : _value));
	};
	inline void set_l_SC(t_param _value) {
		m_l_SC_283 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_k_LPF(t_param _value) {
		m_k_LPF_284 = (_value < 1000 ? 1000 : (_value > 20000 ? 20000 : _value));
	};
	inline void set_j_HPF(t_param _value) {
		m_j_HPF_285 = (_value < 20 ? 20 : (_value > 1000 ? 1000 : _value));
	};
	inline void set_i_TILT(t_param _value) {
		m_i_TILT_286 = (_value < -6 ? -6 : (_value > 6 ? 6 : _value));
	};
	inline void set_h_BITSON(t_param _value) {
		m_h_BITSON_287 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_g_BITS(t_param _value) {
		m_g_BITS_288 = (_value < 3 ? 3 : (_value > 16 ? 16 : _value));
	};
	inline void set_f_BYPASS(t_param _value) {
		m_f_BYPASS_289 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_e_CEILING(t_param _value) {
		m_e_CEILING_290 = (_value < -20 ? -20 : (_value > 6 ? 6 : _value));
	};
	inline void set_d_MODE(t_param _value) {
		m_d_MODE_291 = (_value < 0 ? 0 : (_value > 7 ? 7 : _value));
	};
	inline void set_c_DC(t_param _value) {
		m_c_DC_292 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_b_DRIVE(t_param _value) {
		m_b_DRIVE_293 = (_value < 1 ? 1 : (_value > 50 ? 50 : _value));
	};
	inline void set_a_DRYWET(t_param _value) {
		m_a_DRYWET_294 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		int cond_322 = (fabs(lNorm) <= ((int)1));
		t_sample lOut = (cond_322 ? lCubic : lLimited);
		int cond_323 = (fabs(rNorm) <= ((int)1));
		t_sample rOut = (cond_323 ? rCubic : rLimited);
		out1 = (lOut * cell);
		out2 = (rOut * cell);
		
	};
	inline void sigmoid_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample factor = ((-((int)1)) * dr);
		t_sample l = ((((int)2) * safediv(((int)1), (((int)1) + exp((factor * lWithDC))))) - ((int)1));
		t_sample r = ((((int)2) * safediv(((int)1), (((int)1) + exp((factor * rWithDC))))) - ((int)1));
		t_sample v_326 = (l * cell);
		t_sample min_327 = (-cell);
		t_sample lOut = ((v_326 <= min_327) ? min_327 : ((v_326 >= cell) ? cell : v_326));
		t_sample v_328 = (r * cell);
		t_sample min_329 = (-cell);
		t_sample rOut = ((v_328 <= min_329) ? min_329 : ((v_328 >= cell) ? cell : v_328));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void rectF_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample l = ((((lWithDC > 0) ? 1 : ((lWithDC < 0) ? -1 : 0)) * fabs((lWithDC * dr))) * ((t_sample)0.707));
		t_sample r = ((((rWithDC > 0) ? 1 : ((rWithDC < 0) ? -1 : 0)) * fabs((rWithDC * dr))) * ((t_sample)0.707));
		t_sample min_332 = (-cell);
		t_sample lOut = ((l <= min_332) ? min_332 : ((l >= cell) ? cell : l));
		t_sample min_333 = (-cell);
		t_sample rOut = ((r <= min_333) ? min_333 : ((r >= cell) ? cell : r));
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
		t_sample min_336 = (-cell);
		t_sample lOut = ((l <= min_336) ? min_336 : ((l >= cell) ? cell : l));
		t_sample min_337 = (-cell);
		t_sample rOut = ((r <= min_337) ? min_337 : ((r >= cell) ? cell : r));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void tangenteHiperbolica_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample v_340 = (lWithDC * dr);
		t_sample min_341 = (-cell);
		t_sample l = ((v_340 <= min_341) ? min_341 : ((v_340 >= cell) ? cell : v_340));
		t_sample v_342 = (rWithDC * dr);
		t_sample min_343 = (-cell);
		t_sample r = ((v_342 <= min_343) ? min_343 : ((v_342 >= cell) ? cell : v_342));
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
		t_sample v_346 = ((lPositive * dr) * ((t_sample)0.5));
		t_sample min_347 = (-cell);
		t_sample l = ((v_346 <= min_347) ? min_347 : ((v_346 >= cell) ? cell : v_346));
		t_sample v_348 = ((rPositive * dr) * ((t_sample)0.5));
		t_sample min_349 = (-cell);
		t_sample r = ((v_348 <= min_349) ? min_349 : ((v_348 >= cell) ? cell : v_348));
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
		int cond_354 = (lDriven > cell);
		int cond_355 = (lDriven < (-cell));
		t_sample iftrue_356 = (-cell);
		t_sample iffalse_357 = (cond_355 ? iftrue_356 : lDriven);
		t_sample l = (cond_354 ? cell : iffalse_357);
		int cond_358 = (rDriven > cell);
		int cond_359 = (rDriven < (-cell));
		t_sample iftrue_360 = (-cell);
		t_sample iffalse_361 = (cond_359 ? iftrue_360 : rDriven);
		t_sample r = (cond_358 ? cell : iffalse_361);
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
int num_params() { return 17; }

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
		case 16: self->set_o_BAND(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_a_DRYWET_294; break;
		case 1: *value = self->m_b_DRIVE_293; break;
		case 2: *value = self->m_c_DC_292; break;
		case 3: *value = self->m_d_MODE_291; break;
		case 4: *value = self->m_e_CEILING_290; break;
		case 5: *value = self->m_f_BYPASS_289; break;
		case 6: *value = self->m_g_BITS_288; break;
		case 7: *value = self->m_h_BITSON_287; break;
		case 8: *value = self->m_i_TILT_286; break;
		case 9: *value = self->m_j_HPF_285; break;
		case 10: *value = self->m_k_INPUT_282; break;
		case 11: *value = self->m_k_LPF_284; break;
		case 12: *value = self->m_l_OUTPUT_281; break;
		case 13: *value = self->m_l_SC_283; break;
		case 14: *value = self->m_m_DOWNSAMPLE_280; break;
		case 15: *value = self->m_n_DOWNSAMPLEON_279; break;
		case 16: *value = self->m_o_BAND_278; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(17 * sizeof(ParamInfo));
	self->__commonstate.numparams = 17;
	// initialize parameter 0 ("m_a_DRYWET_294")
	pi = self->__commonstate.params + 0;
	pi->name = "a_DRYWET";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_a_DRYWET_294;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_b_DRIVE_293")
	pi = self->__commonstate.params + 1;
	pi->name = "b_DRIVE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_b_DRIVE_293;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 50;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_c_DC_292")
	pi = self->__commonstate.params + 2;
	pi->name = "c_DC";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_c_DC_292;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_d_MODE_291")
	pi = self->__commonstate.params + 3;
	pi->name = "d_MODE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d_MODE_291;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 7;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_e_CEILING_290")
	pi = self->__commonstate.params + 4;
	pi->name = "e_CEILING";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_e_CEILING_290;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -20;
	pi->outputmax = 6;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_f_BYPASS_289")
	pi = self->__commonstate.params + 5;
	pi->name = "f_BYPASS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_f_BYPASS_289;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_g_BITS_288")
	pi = self->__commonstate.params + 6;
	pi->name = "g_BITS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_g_BITS_288;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 3;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_h_BITSON_287")
	pi = self->__commonstate.params + 7;
	pi->name = "h_BITSON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_h_BITSON_287;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_i_TILT_286")
	pi = self->__commonstate.params + 8;
	pi->name = "i_TILT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_i_TILT_286;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -6;
	pi->outputmax = 6;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_j_HPF_285")
	pi = self->__commonstate.params + 9;
	pi->name = "j_HPF";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_j_HPF_285;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 20;
	pi->outputmax = 1000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_k_INPUT_282")
	pi = self->__commonstate.params + 10;
	pi->name = "k_INPUT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_k_INPUT_282;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -12;
	pi->outputmax = 12;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_k_LPF_284")
	pi = self->__commonstate.params + 11;
	pi->name = "k_LPF";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_k_LPF_284;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1000;
	pi->outputmax = 20000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_l_OUTPUT_281")
	pi = self->__commonstate.params + 12;
	pi->name = "l_OUTPUT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_l_OUTPUT_281;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -12;
	pi->outputmax = 12;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_l_SC_283")
	pi = self->__commonstate.params + 13;
	pi->name = "l_SC";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_l_SC_283;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_m_DOWNSAMPLE_280")
	pi = self->__commonstate.params + 14;
	pi->name = "m_DOWNSAMPLE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_m_DOWNSAMPLE_280;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_n_DOWNSAMPLEON_279")
	pi = self->__commonstate.params + 15;
	pi->name = "n_DOWNSAMPLEON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_n_DOWNSAMPLEON_279;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 16 ("m_o_BAND_278")
	pi = self->__commonstate.params + 16;
	pi->name = "o_BAND";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_o_BAND_278;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2;
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

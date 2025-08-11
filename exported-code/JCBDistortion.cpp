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
	DCBlock __m_dcblock_386;
	DCBlock __m_dcblock_376;
	DCBlock __m_dcblock_375;
	DCBlock __m_dcblock_379;
	DCBlock __m_dcblock_380;
	DCBlock __m_dcblock_385;
	int __exception;
	int vectorsize;
	t_sample m_R_ap2_lp2_x_5;
	t_sample m_R_m2_y_204;
	t_sample m_R_m2_y_203;
	t_sample m_R_m2_x_205;
	t_sample m_R_m1_y_206;
	t_sample m_R_m1_y_207;
	t_sample m_R_u1_x_202;
	t_sample m_R_m1_x_208;
	t_sample m_R_h2_y_209;
	t_sample m_R_u1_y_201;
	t_sample m_R_u2_x_199;
	t_sample m_R_ap_low_lp1_y_195;
	t_sample m_R_ap_low_lp1_y_194;
	t_sample m_R_u1_y_200;
	t_sample m_R_ap_low_lp1_x_196;
	t_sample m_R_u2_y_198;
	t_sample m_R_u2_y_197;
	t_sample m_R_h2_y_210;
	t_sample m_R_h2_x_211;
	t_sample m_R_h1_y_212;
	t_sample m_L_ap2_hp2_x_223;
	t_sample m_L_ap2_hp2_y_222;
	t_sample m_L_ap2_hp2_y_221;
	t_sample m_L_ap2_hp1_y_224;
	t_sample m_L_ap2_hp1_x_226;
	t_sample m_L_ap2_hp1_y_225;
	t_sample m_L_ap2_lp2_y_227;
	t_sample m_R_ap_low_lp2_x_193;
	t_sample m_R_l1_x_220;
	t_sample m_R_l1_y_218;
	t_sample m_R_h1_x_214;
	t_sample m_R_h1_y_213;
	t_sample m_R_l1_y_219;
	t_sample m_R_l2_y_215;
	t_sample m_R_l2_x_217;
	t_sample m_R_l2_y_216;
	t_sample m_L_ap2_lp2_y_228;
	t_sample m_R_ap_low_lp2_y_192;
	t_sample m_R_ap_low_hp1_x_190;
	t_sample m_R_ap2_lp2_y_167;
	t_sample m_R_ap2_hp1_x_166;
	t_sample m_R_ap2_hp1_y_165;
	t_sample m_R_ap2_lp2_y_168;
	t_sample m_R_ap2_lp1_y_170;
	t_sample m_R_ap2_lp2_x_169;
	t_sample m_R_ap2_lp1_y_171;
	t_sample m_R_ap2_lp1_x_172;
	t_sample m_R_ap2_hp1_y_164;
	t_sample m_R_ap2_hp2_y_162;
	t_sample m_l1_y_158;
	t_sample m_l1_y_157;
	t_sample m_R_ap2_hp2_x_163;
	t_sample m_l1_x_159;
	t_sample m_R_ap2_hp2_y_161;
	t_sample m_l1_x_160;
	t_sample m_R_ap_low_lp2_y_191;
	t_sample m_R_ap1_hp2_y_173;
	t_sample m_R_ap1_hp2_x_175;
	t_sample m_R_ap_low_hp2_y_186;
	t_sample m_R_ap_low_hp2_y_185;
	t_sample m_R_ap1_lp1_x_184;
	t_sample m_R_ap_low_hp2_x_187;
	t_sample m_R_ap_low_hp1_y_189;
	t_sample m_R_ap_low_hp1_y_188;
	t_sample m_R_ap1_hp2_y_174;
	t_sample m_R_ap1_lp1_y_183;
	t_sample m_R_ap1_lp2_x_181;
	t_sample m_R_ap1_hp1_y_177;
	t_sample m_R_ap1_hp1_y_176;
	t_sample m_R_ap1_lp1_y_182;
	t_sample m_R_ap1_hp1_x_178;
	t_sample m_R_ap1_lp2_y_180;
	t_sample m_R_ap1_lp2_y_179;
	t_sample m_L_ap2_lp2_x_229;
	t_sample m_L_ap2_lp1_y_230;
	t_sample m_L_ap2_lp1_y_231;
	t_sample m_L_l1_y_279;
	t_sample m_L_l1_y_278;
	t_sample m_L_l2_x_277;
	t_sample m_L_l1_x_280;
	t_sample m_n_DOWNSAMPLEON_282;
	t_sample m_o_BAND_281;
	t_sample m_m_DOWNSAMPLE_283;
	t_sample m_l_OUTPUT_284;
	t_sample m_L_l2_y_276;
	t_sample m_L_h1_x_274;
	t_sample m_L_h2_y_270;
	t_sample m_L_h2_y_269;
	t_sample m_L_l2_y_275;
	t_sample m_L_h2_x_271;
	t_sample m_L_h1_y_273;
	t_sample m_L_h1_y_272;
	t_sample m_L_m1_x_268;
	t_sample m_k_INPUT_285;
	t_sample m_k_LPF_287;
	t_sample m_L_ap2_hp2_x_2;
	t_sample m_a_DRYWET_297;
	t_sample m_b_DRIVE_296;
	t_sample m_R_ap2_hp2_x_1;
	t_sample __m_latch_383;
	t_sample samplerate;
	t_sample __m_latch_384;
	t_sample m_l_SC_286;
	t_sample m_c_DC_295;
	t_sample m_e_CEILING_293;
	t_sample m_i_TILT_289;
	t_sample m_j_HPF_288;
	t_sample m_d_MODE_294;
	t_sample m_h_BITSON_290;
	t_sample m_f_BYPASS_292;
	t_sample m_g_BITS_291;
	t_sample m_l2_x_156;
	t_sample m_L_m1_y_267;
	t_sample m_L_m2_x_265;
	t_sample m_L_ap1_lp1_y_242;
	t_sample m_L_ap1_lp2_x_241;
	t_sample m_L_ap1_lp2_y_240;
	t_sample m_L_ap1_lp1_y_243;
	t_sample m_L_ap_low_hp2_y_245;
	t_sample m_L_ap1_lp1_x_244;
	t_sample m_L_ap_low_hp2_y_246;
	t_sample m_L_ap_low_hp2_x_247;
	t_sample m_L_ap1_lp2_y_239;
	t_sample m_L_ap1_hp1_y_237;
	t_sample m_L_ap1_hp2_y_233;
	t_sample m_L_ap2_lp1_x_232;
	t_sample m_L_ap1_hp1_x_238;
	t_sample m_L_ap1_hp2_y_234;
	t_sample m_L_ap1_hp1_y_236;
	t_sample m_L_ap1_hp2_x_235;
	t_sample m_L_m1_y_266;
	t_sample m_L_ap_low_hp1_y_248;
	t_sample m_L_ap_low_hp1_x_250;
	t_sample m_L_u1_y_261;
	t_sample m_L_u1_y_260;
	t_sample m_L_u2_x_259;
	t_sample m_L_u1_x_262;
	t_sample m_L_m2_y_264;
	t_sample m_L_m2_y_263;
	t_sample m_L_ap_low_hp1_y_249;
	t_sample m_L_u2_y_258;
	t_sample m_L_ap_low_lp1_x_256;
	t_sample m_L_ap_low_lp2_y_252;
	t_sample m_L_ap_low_lp2_y_251;
	t_sample m_L_u2_y_257;
	t_sample m_L_ap_low_lp2_x_253;
	t_sample m_L_ap_low_lp1_y_255;
	t_sample m_L_ap_low_lp1_y_254;
	t_sample m_L_ap2_hp1_x_4;
	t_sample m_l2_x_155;
	t_sample m_l2_y_153;
	t_sample m_tiltLsL_54;
	t_sample m_tiltLsL_53;
	t_sample m_tiltLsR_52;
	t_sample m_tiltLsL_55;
	t_sample m_dsEnablePrev_57;
	t_sample m_tiltLsL_56;
	t_sample m_dsTrigPrev_58;
	t_sample m_dsPhase_59;
	t_sample m_tiltLsR_51;
	t_sample m_tiltLsR_49;
	t_sample m_tiltHsL_45;
	t_sample m_tiltHsR_44;
	t_sample m_tiltLsR_50;
	t_sample m_tiltHsL_46;
	t_sample m_tiltHsL_48;
	t_sample m_tiltHsL_47;
	t_sample m_tiltHsR_43;
	t_sample m_dsPhasor_60;
	t_sample m_lpfFreqHistory_62;
	t_sample m_hInput_73;
	t_sample m_hOutput_72;
	t_sample m_hMode_71;
	t_sample m_hTilt_74;
	t_sample m_hBits_76;
	t_sample m_hBitson_75;
	t_sample m_hDrywet_77;
	t_sample m_scEnableHistory_61;
	t_sample m_hDownsample_70;
	t_sample m_hBypass_68;
	t_sample m_lpfR_z_64;
	t_sample m_hpfFreqHistory_63;
	t_sample m_hDownsampleOn_69;
	t_sample m_lpfL_z_65;
	t_sample m_hpfL_z_67;
	t_sample m_hpfR_z_66;
	t_sample m_hDc_78;
	t_sample m_tiltHsR_42;
	t_sample m_L_l1_x_40;
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
	t_sample m_tiltHsR_41;
	t_sample m_L_ap_low_lp2_x_22;
	t_sample m_L_ap_low_lp1_x_24;
	t_sample m_R_h1_x_35;
	t_sample m_L_h2_x_34;
	t_sample m_R_h2_x_33;
	t_sample m_L_h1_x_36;
	t_sample m_L_l2_x_38;
	t_sample m_R_l2_x_37;
	t_sample m_R_l1_x_39;
	t_sample m_R_ap_low_lp1_x_23;
	t_sample m_L_m1_x_32;
	t_sample m_L_m2_x_30;
	t_sample m_L_u2_x_26;
	t_sample m_R_u2_x_25;
	t_sample m_R_m1_x_31;
	t_sample m_R_u1_x_27;
	t_sample m_R_m2_x_29;
	t_sample m_L_u1_x_28;
	t_sample m_l2_y_154;
	t_sample m_hDrive_79;
	t_sample m_ap2_hp2_y_81;
	t_sample m_u2_y_129;
	t_sample m_ap_low_lp1_x_128;
	t_sample m_ap_low_lp1_x_127;
	t_sample m_u2_y_130;
	t_sample m_u2_x_132;
	t_sample m_u2_x_131;
	t_sample m_u1_y_133;
	t_sample m_u1_y_134;
	t_sample m_ap_low_lp1_y_126;
	t_sample m_ap_low_lp2_x_124;
	t_sample m_ap_low_hp1_x_120;
	t_sample m_ap_low_hp1_x_119;
	t_sample m_ap_low_lp1_y_125;
	t_sample m_ap_low_lp2_y_121;
	t_sample m_ap_low_lp2_x_123;
	t_sample m_ap_low_lp2_y_122;
	t_sample m_ap_low_hp1_y_118;
	t_sample m_u1_x_135;
	t_sample m_m2_y_137;
	t_sample m_h2_x_148;
	t_sample m_h2_x_147;
	t_sample m_h2_y_146;
	t_sample m_h1_y_149;
	t_sample m_R_ap2_hp1_x_3;
	t_sample m_h1_y_150;
	t_sample m_h1_x_152;
	t_sample m_u1_x_136;
	t_sample m_h2_y_145;
	t_sample m_m1_x_143;
	t_sample m_m2_x_139;
	t_sample m_m2_y_138;
	t_sample m_m1_x_144;
	t_sample m_m2_x_140;
	t_sample m_m1_y_142;
	t_sample m_m1_y_141;
	t_sample m_hBand_80;
	t_sample m_ap_low_hp1_y_117;
	t_sample m_ap_low_hp2_x_115;
	t_sample m_ap2_lp2_x_92;
	t_sample m_ap2_lp2_x_91;
	t_sample m_ap2_lp2_y_90;
	t_sample m_ap2_lp1_y_93;
	t_sample m_ap2_lp1_x_95;
	t_sample m_ap2_lp1_y_94;
	t_sample m_ap2_lp1_x_96;
	t_sample m_ap1_hp2_y_97;
	t_sample m_ap2_lp2_y_89;
	t_sample m_ap2_hp1_x_87;
	t_sample m_ap2_hp2_x_83;
	t_sample m_ap2_hp2_y_82;
	t_sample m_ap2_hp1_x_88;
	t_sample m_ap2_hp2_x_84;
	t_sample m_ap2_hp1_y_86;
	t_sample m_ap2_hp1_y_85;
	t_sample m_ap_low_hp2_x_116;
	t_sample m_ap1_hp2_y_98;
	t_sample m_ap1_hp2_x_100;
	t_sample m_ap1_lp1_x_111;
	t_sample m_ap1_lp1_y_110;
	t_sample m_ap1_lp1_y_109;
	t_sample m_ap1_lp1_x_112;
	t_sample m_ap_low_hp2_y_114;
	t_sample m_ap_low_hp2_y_113;
	t_sample m_ap1_hp2_x_99;
	t_sample m_ap1_lp2_x_108;
	t_sample m_ap1_lp2_y_106;
	t_sample m_ap1_hp1_y_102;
	t_sample m_ap1_hp1_y_101;
	t_sample m_ap1_lp2_x_107;
	t_sample m_ap1_hp1_x_103;
	t_sample m_ap1_lp2_y_105;
	t_sample m_ap1_hp1_x_104;
	t_sample m_h1_x_151;
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
		m_dsEnablePrev_57 = ((int)0);
		m_dsTrigPrev_58 = ((int)0);
		m_dsPhase_59 = ((int)0);
		m_dsPhasor_60 = ((int)0);
		m_scEnableHistory_61 = ((int)0);
		m_lpfFreqHistory_62 = ((int)0);
		m_hpfFreqHistory_63 = ((int)0);
		m_lpfR_z_64 = ((int)0);
		m_lpfL_z_65 = ((int)0);
		m_hpfR_z_66 = ((int)0);
		m_hpfL_z_67 = ((int)0);
		m_hBypass_68 = ((int)0);
		m_hDownsampleOn_69 = ((int)0);
		m_hDownsample_70 = ((int)0);
		m_hMode_71 = ((int)0);
		m_hOutput_72 = ((int)0);
		m_hInput_73 = ((int)0);
		m_hTilt_74 = ((int)0);
		m_hBitson_75 = ((int)0);
		m_hBits_76 = ((int)0);
		m_hDrywet_77 = ((int)0);
		m_hDc_78 = ((int)0);
		m_hDrive_79 = ((int)0);
		m_hBand_80 = ((int)1);
		m_ap2_hp2_y_81 = ((int)0);
		m_ap2_hp2_y_82 = ((int)0);
		m_ap2_hp2_x_83 = ((int)0);
		m_ap2_hp2_x_84 = ((int)0);
		m_ap2_hp1_y_85 = ((int)0);
		m_ap2_hp1_y_86 = ((int)0);
		m_ap2_hp1_x_87 = ((int)0);
		m_ap2_hp1_x_88 = ((int)0);
		m_ap2_lp2_y_89 = ((int)0);
		m_ap2_lp2_y_90 = ((int)0);
		m_ap2_lp2_x_91 = ((int)0);
		m_ap2_lp2_x_92 = ((int)0);
		m_ap2_lp1_y_93 = ((int)0);
		m_ap2_lp1_y_94 = ((int)0);
		m_ap2_lp1_x_95 = ((int)0);
		m_ap2_lp1_x_96 = ((int)0);
		m_ap1_hp2_y_97 = ((int)0);
		m_ap1_hp2_y_98 = ((int)0);
		m_ap1_hp2_x_99 = ((int)0);
		m_ap1_hp2_x_100 = ((int)0);
		m_ap1_hp1_y_101 = ((int)0);
		m_ap1_hp1_y_102 = ((int)0);
		m_ap1_hp1_x_103 = ((int)0);
		m_ap1_hp1_x_104 = ((int)0);
		m_ap1_lp2_y_105 = ((int)0);
		m_ap1_lp2_y_106 = ((int)0);
		m_ap1_lp2_x_107 = ((int)0);
		m_ap1_lp2_x_108 = ((int)0);
		m_ap1_lp1_y_109 = ((int)0);
		m_ap1_lp1_y_110 = ((int)0);
		m_ap1_lp1_x_111 = ((int)0);
		m_ap1_lp1_x_112 = ((int)0);
		m_ap_low_hp2_y_113 = ((int)0);
		m_ap_low_hp2_y_114 = ((int)0);
		m_ap_low_hp2_x_115 = ((int)0);
		m_ap_low_hp2_x_116 = ((int)0);
		m_ap_low_hp1_y_117 = ((int)0);
		m_ap_low_hp1_y_118 = ((int)0);
		m_ap_low_hp1_x_119 = ((int)0);
		m_ap_low_hp1_x_120 = ((int)0);
		m_ap_low_lp2_y_121 = ((int)0);
		m_ap_low_lp2_y_122 = ((int)0);
		m_ap_low_lp2_x_123 = ((int)0);
		m_ap_low_lp2_x_124 = ((int)0);
		m_ap_low_lp1_y_125 = ((int)0);
		m_ap_low_lp1_y_126 = ((int)0);
		m_ap_low_lp1_x_127 = ((int)0);
		m_ap_low_lp1_x_128 = ((int)0);
		m_u2_y_129 = ((int)0);
		m_u2_y_130 = ((int)0);
		m_u2_x_131 = ((int)0);
		m_u2_x_132 = ((int)0);
		m_u1_y_133 = ((int)0);
		m_u1_y_134 = ((int)0);
		m_u1_x_135 = ((int)0);
		m_u1_x_136 = ((int)0);
		m_m2_y_137 = ((int)0);
		m_m2_y_138 = ((int)0);
		m_m2_x_139 = ((int)0);
		m_m2_x_140 = ((int)0);
		m_m1_y_141 = ((int)0);
		m_m1_y_142 = ((int)0);
		m_m1_x_143 = ((int)0);
		m_m1_x_144 = ((int)0);
		m_h2_y_145 = ((int)0);
		m_h2_y_146 = ((int)0);
		m_h2_x_147 = ((int)0);
		m_h2_x_148 = ((int)0);
		m_h1_y_149 = ((int)0);
		m_h1_y_150 = ((int)0);
		m_h1_x_151 = ((int)0);
		m_h1_x_152 = ((int)0);
		m_l2_y_153 = ((int)0);
		m_l2_y_154 = ((int)0);
		m_l2_x_155 = ((int)0);
		m_l2_x_156 = ((int)0);
		m_l1_y_157 = ((int)0);
		m_l1_y_158 = ((int)0);
		m_l1_x_159 = ((int)0);
		m_l1_x_160 = ((int)0);
		m_R_ap2_hp2_y_161 = ((int)0);
		m_R_ap2_hp2_y_162 = ((int)0);
		m_R_ap2_hp2_x_163 = ((int)0);
		m_R_ap2_hp1_y_164 = ((int)0);
		m_R_ap2_hp1_y_165 = ((int)0);
		m_R_ap2_hp1_x_166 = ((int)0);
		m_R_ap2_lp2_y_167 = ((int)0);
		m_R_ap2_lp2_y_168 = ((int)0);
		m_R_ap2_lp2_x_169 = ((int)0);
		m_R_ap2_lp1_y_170 = ((int)0);
		m_R_ap2_lp1_y_171 = ((int)0);
		m_R_ap2_lp1_x_172 = ((int)0);
		m_R_ap1_hp2_y_173 = ((int)0);
		m_R_ap1_hp2_y_174 = ((int)0);
		m_R_ap1_hp2_x_175 = ((int)0);
		m_R_ap1_hp1_y_176 = ((int)0);
		m_R_ap1_hp1_y_177 = ((int)0);
		m_R_ap1_hp1_x_178 = ((int)0);
		m_R_ap1_lp2_y_179 = ((int)0);
		m_R_ap1_lp2_y_180 = ((int)0);
		m_R_ap1_lp2_x_181 = ((int)0);
		m_R_ap1_lp1_y_182 = ((int)0);
		m_R_ap1_lp1_y_183 = ((int)0);
		m_R_ap1_lp1_x_184 = ((int)0);
		m_R_ap_low_hp2_y_185 = ((int)0);
		m_R_ap_low_hp2_y_186 = ((int)0);
		m_R_ap_low_hp2_x_187 = ((int)0);
		m_R_ap_low_hp1_y_188 = ((int)0);
		m_R_ap_low_hp1_y_189 = ((int)0);
		m_R_ap_low_hp1_x_190 = ((int)0);
		m_R_ap_low_lp2_y_191 = ((int)0);
		m_R_ap_low_lp2_y_192 = ((int)0);
		m_R_ap_low_lp2_x_193 = ((int)0);
		m_R_ap_low_lp1_y_194 = ((int)0);
		m_R_ap_low_lp1_y_195 = ((int)0);
		m_R_ap_low_lp1_x_196 = ((int)0);
		m_R_u2_y_197 = ((int)0);
		m_R_u2_y_198 = ((int)0);
		m_R_u2_x_199 = ((int)0);
		m_R_u1_y_200 = ((int)0);
		m_R_u1_y_201 = ((int)0);
		m_R_u1_x_202 = ((int)0);
		m_R_m2_y_203 = ((int)0);
		m_R_m2_y_204 = ((int)0);
		m_R_m2_x_205 = ((int)0);
		m_R_m1_y_206 = ((int)0);
		m_R_m1_y_207 = ((int)0);
		m_R_m1_x_208 = ((int)0);
		m_R_h2_y_209 = ((int)0);
		m_R_h2_y_210 = ((int)0);
		m_R_h2_x_211 = ((int)0);
		m_R_h1_y_212 = ((int)0);
		m_R_h1_y_213 = ((int)0);
		m_R_h1_x_214 = ((int)0);
		m_R_l2_y_215 = ((int)0);
		m_R_l2_y_216 = ((int)0);
		m_R_l2_x_217 = ((int)0);
		m_R_l1_y_218 = ((int)0);
		m_R_l1_y_219 = ((int)0);
		m_R_l1_x_220 = ((int)0);
		m_L_ap2_hp2_y_221 = ((int)0);
		m_L_ap2_hp2_y_222 = ((int)0);
		m_L_ap2_hp2_x_223 = ((int)0);
		m_L_ap2_hp1_y_224 = ((int)0);
		m_L_ap2_hp1_y_225 = ((int)0);
		m_L_ap2_hp1_x_226 = ((int)0);
		m_L_ap2_lp2_y_227 = ((int)0);
		m_L_ap2_lp2_y_228 = ((int)0);
		m_L_ap2_lp2_x_229 = ((int)0);
		m_L_ap2_lp1_y_230 = ((int)0);
		m_L_ap2_lp1_y_231 = ((int)0);
		m_L_ap2_lp1_x_232 = ((int)0);
		m_L_ap1_hp2_y_233 = ((int)0);
		m_L_ap1_hp2_y_234 = ((int)0);
		m_L_ap1_hp2_x_235 = ((int)0);
		m_L_ap1_hp1_y_236 = ((int)0);
		m_L_ap1_hp1_y_237 = ((int)0);
		m_L_ap1_hp1_x_238 = ((int)0);
		m_L_ap1_lp2_y_239 = ((int)0);
		m_L_ap1_lp2_y_240 = ((int)0);
		m_L_ap1_lp2_x_241 = ((int)0);
		m_L_ap1_lp1_y_242 = ((int)0);
		m_L_ap1_lp1_y_243 = ((int)0);
		m_L_ap1_lp1_x_244 = ((int)0);
		m_L_ap_low_hp2_y_245 = ((int)0);
		m_L_ap_low_hp2_y_246 = ((int)0);
		m_L_ap_low_hp2_x_247 = ((int)0);
		m_L_ap_low_hp1_y_248 = ((int)0);
		m_L_ap_low_hp1_y_249 = ((int)0);
		m_L_ap_low_hp1_x_250 = ((int)0);
		m_L_ap_low_lp2_y_251 = ((int)0);
		m_L_ap_low_lp2_y_252 = ((int)0);
		m_L_ap_low_lp2_x_253 = ((int)0);
		m_L_ap_low_lp1_y_254 = ((int)0);
		m_L_ap_low_lp1_y_255 = ((int)0);
		m_L_ap_low_lp1_x_256 = ((int)0);
		m_L_u2_y_257 = ((int)0);
		m_L_u2_y_258 = ((int)0);
		m_L_u2_x_259 = ((int)0);
		m_L_u1_y_260 = ((int)0);
		m_L_u1_y_261 = ((int)0);
		m_L_u1_x_262 = ((int)0);
		m_L_m2_y_263 = ((int)0);
		m_L_m2_y_264 = ((int)0);
		m_L_m2_x_265 = ((int)0);
		m_L_m1_y_266 = ((int)0);
		m_L_m1_y_267 = ((int)0);
		m_L_m1_x_268 = ((int)0);
		m_L_h2_y_269 = ((int)0);
		m_L_h2_y_270 = ((int)0);
		m_L_h2_x_271 = ((int)0);
		m_L_h1_y_272 = ((int)0);
		m_L_h1_y_273 = ((int)0);
		m_L_h1_x_274 = ((int)0);
		m_L_l2_y_275 = ((int)0);
		m_L_l2_y_276 = ((int)0);
		m_L_l2_x_277 = ((int)0);
		m_L_l1_y_278 = ((int)0);
		m_L_l1_y_279 = ((int)0);
		m_L_l1_x_280 = ((int)0);
		m_o_BAND_281 = 1;
		m_n_DOWNSAMPLEON_282 = 0;
		m_m_DOWNSAMPLE_283 = 0;
		m_l_OUTPUT_284 = 0;
		m_k_INPUT_285 = 0;
		m_l_SC_286 = 0;
		m_k_LPF_287 = 5000;
		m_j_HPF_288 = 250;
		m_i_TILT_289 = 0;
		m_h_BITSON_290 = 0;
		m_g_BITS_291 = 16;
		m_f_BYPASS_292 = 0;
		m_e_CEILING_293 = 0;
		m_d_MODE_294 = 0;
		m_c_DC_295 = 0;
		m_b_DRIVE_296 = 1;
		m_a_DRYWET_297 = 1;
		__m_dcblock_375.reset();
		__m_dcblock_376.reset();
		__m_dcblock_379.reset();
		__m_dcblock_380.reset();
		__m_latch_383 = 0;
		__m_latch_384 = 0;
		__m_dcblock_385.reset();
		__m_dcblock_386.reset();
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
		t_sample ceiling = dbtoa(m_e_CEILING_293);
		int L_sr = samplerate;
		t_sample minb_298 = (((t_sample)0.45) * L_sr);
		t_sample minb_300 = (((t_sample)0.45) * L_sr);
		int R_sr = samplerate;
		t_sample minb_303 = (((t_sample)0.45) * R_sr);
		t_sample minb_305 = (((t_sample)0.45) * R_sr);
		int L_sr_2098 = samplerate;
		t_sample minb_312 = (((t_sample)0.45) * L_sr_2098);
		t_sample minb_314 = (((t_sample)0.45) * L_sr_2098);
		int R_sr_2141 = samplerate;
		t_sample minb_317 = (((t_sample)0.45) * R_sr_2141);
		t_sample minb_319 = (((t_sample)0.45) * R_sr_2141);
		t_sample omega = safediv(((t_sample)6283.1853071796), samplerate);
		t_sample sn = sin(omega);
		t_sample cs = cos(omega);
		t_sample cos2 = ((cs * cs) - (sn * sn));
		t_sample sin2 = ((((int)2) * sn) * cs);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample lIn = in1;
			t_sample rIn = in2;
			m_hDrive_79 = ((m_hDrive_79 * ((t_sample)0.999)) + (m_b_DRIVE_296 * ((t_sample)0.001)));
			t_sample drive = m_hDrive_79;
			m_hDc_78 = ((m_hDc_78 * ((t_sample)0.999)) + (m_c_DC_295 * ((t_sample)0.001)));
			t_sample dc = m_hDc_78;
			m_hDrywet_77 = ((m_hDrywet_77 * ((t_sample)0.999)) + (m_a_DRYWET_297 * ((t_sample)0.001)));
			t_sample drywet = m_hDrywet_77;
			m_hBits_76 = ((m_hBits_76 * ((t_sample)0.999)) + (m_g_BITS_291 * ((t_sample)0.001)));
			t_sample bits = m_hBits_76;
			m_hBitson_75 = ((m_hBitson_75 * ((t_sample)0.999)) + (m_h_BITSON_290 * ((t_sample)0.001)));
			t_sample bitson = m_hBitson_75;
			m_hTilt_74 = ((m_hTilt_74 * ((t_sample)0.999)) + (m_i_TILT_289 * ((t_sample)0.001)));
			t_sample tiltDb = m_hTilt_74;
			m_hInput_73 = ((m_hInput_73 * ((t_sample)0.999)) + (m_k_INPUT_285 * ((t_sample)0.001)));
			t_sample inputTrimDb = m_hInput_73;
			m_hOutput_72 = ((m_hOutput_72 * ((t_sample)0.999)) + (m_l_OUTPUT_284 * ((t_sample)0.001)));
			t_sample outputMakeupDb = m_hOutput_72;
			m_hBand_80 = ((m_hBand_80 * ((t_sample)0.999)) + (m_o_BAND_281 * ((t_sample)0.001)));
			t_sample smoothedBand = m_hBand_80;
			m_hMode_71 = ((m_hMode_71 * ((t_sample)0.99)) + (m_d_MODE_294 * ((t_sample)0.01)));
			t_sample smoothedMode = m_hMode_71;
			m_hDownsample_70 = ((m_hDownsample_70 * ((t_sample)0.999)) + (m_m_DOWNSAMPLE_283 * ((t_sample)0.001)));
			m_hDownsampleOn_69 = ((m_hDownsampleOn_69 * ((t_sample)0.9)) + (m_n_DOWNSAMPLEON_282 * ((t_sample)0.1)));
			t_sample downsampleOn = m_hDownsampleOn_69;
			m_hBypass_68 = ((m_hBypass_68 * ((t_sample)0.999)) + ((((int)1) - m_f_BYPASS_292) * ((t_sample)0.001)));
			t_sample bypass = m_hBypass_68;
			t_sample smoothHpfFreq = ((m_hpfFreqHistory_63 * ((t_sample)0.999)) + (m_j_HPF_288 * ((t_sample)0.001)));
			m_hpfFreqHistory_63 = fixdenorm(smoothHpfFreq);
			t_sample smoothLpfFreq = ((m_lpfFreqHistory_62 * ((t_sample)0.999)) + (m_k_LPF_287 * ((t_sample)0.001)));
			m_lpfFreqHistory_62 = fixdenorm(smoothLpfFreq);
			t_sample smoothScEnable = ((m_scEnableHistory_61 * ((t_sample)0.999)) + (m_l_SC_286 * ((t_sample)0.001)));
			m_scEnableHistory_61 = fixdenorm(smoothScEnable);
			t_sample inputTrimLinear = dbtoa(inputTrimDb);
			t_sample outputMakeupLinear = dbtoa(outputMakeupDb);
			t_sample lTrimmed = (lIn * inputTrimLinear);
			t_sample rTrimmed = (rIn * inputTrimLinear);
			t_sample scSm = smoothScEnable;
			t_sample L_loF = smoothHpfFreq;
			t_sample L_hiF = smoothLpfFreq;
			t_sample L_x = lTrimmed;
			t_sample maxb_299 = ((minb_298 < L_loF) ? minb_298 : L_loF);
			t_sample L_loF_2085 = ((((int)10) < maxb_299) ? maxb_299 : ((int)10));
			t_sample maxb_301 = ((minb_300 < L_hiF) ? minb_300 : L_hiF);
			t_sample L_hiFr = ((((int)10) < maxb_301) ? maxb_301 : ((int)10));
			t_sample maxb_302 = (L_loF_2085 + ((int)1));
			t_sample L_hiF_2086 = ((L_hiFr < maxb_302) ? maxb_302 : L_hiFr);
			t_sample L_w0_lo = safediv((((t_sample)6.2831853071796) * L_loF_2085), L_sr);
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
			t_sample L_w0_hi = safediv((((t_sample)6.2831853071796) * L_hiF_2086), L_sr);
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
			t_sample L_l1_x2p = m_L_l1_x_280;
			t_sample L_l1_y1p = m_L_l1_y_279;
			t_sample L_l1_y2p = m_L_l1_y_278;
			t_sample L_low_s1 = (((((L_lp_b0_l * L_x) + (L_lp_b1_l * L_l1_x1p)) + (L_lp_b2_l * L_l1_x2p)) - (L_lp_a1_l * L_l1_y1p)) - (L_lp_a2_l * L_l1_y2p));
			m_L_l1_x_280 = L_l1_x1p;
			m_L_l1_x_40 = L_x;
			m_L_l1_y_278 = L_l1_y1p;
			m_L_l1_y_279 = L_low_s1;
			t_sample L_l2_x1p = m_L_l2_x_38;
			t_sample L_l2_x2p = m_L_l2_x_277;
			t_sample L_l2_y1p = m_L_l2_y_276;
			t_sample L_l2_y2p = m_L_l2_y_275;
			t_sample L_low_raw = (((((L_lp_b0_l * L_low_s1) + (L_lp_b1_l * L_l2_x1p)) + (L_lp_b2_l * L_l2_x2p)) - (L_lp_a1_l * L_l2_y1p)) - (L_lp_a2_l * L_l2_y2p));
			m_L_l2_x_277 = L_l2_x1p;
			m_L_l2_x_38 = L_low_s1;
			m_L_l2_y_275 = L_l2_y1p;
			m_L_l2_y_276 = L_low_raw;
			t_sample L_h1_x1p = m_L_h1_x_36;
			t_sample L_h1_x2p = m_L_h1_x_274;
			t_sample L_h1_y1p = m_L_h1_y_273;
			t_sample L_h1_y2p = m_L_h1_y_272;
			t_sample L_rest_s1 = (((((L_hp_b0_l * L_x) + (L_hp_b1_l * L_h1_x1p)) + (L_hp_b2_l * L_h1_x2p)) - (L_hp_a1_l * L_h1_y1p)) - (L_hp_a2_l * L_h1_y2p));
			m_L_h1_x_274 = L_h1_x1p;
			m_L_h1_x_36 = L_x;
			m_L_h1_y_272 = L_h1_y1p;
			m_L_h1_y_273 = L_rest_s1;
			t_sample L_h2_x1p = m_L_h2_x_34;
			t_sample L_h2_x2p = m_L_h2_x_271;
			t_sample L_h2_y1p = m_L_h2_y_270;
			t_sample L_h2_y2p = m_L_h2_y_269;
			t_sample L_rest = (((((L_hp_b0_l * L_rest_s1) + (L_hp_b1_l * L_h2_x1p)) + (L_hp_b2_l * L_h2_x2p)) - (L_hp_a1_l * L_h2_y1p)) - (L_hp_a2_l * L_h2_y2p));
			m_L_h2_x_271 = L_h2_x1p;
			m_L_h2_x_34 = L_rest_s1;
			m_L_h2_y_269 = L_h2_y1p;
			m_L_h2_y_270 = L_rest;
			t_sample L_ap_low_lp1_x1p = m_L_ap_low_lp1_x_24;
			t_sample L_ap_low_lp1_x2p = m_L_ap_low_lp1_x_256;
			t_sample L_ap_low_lp1_y1p = m_L_ap_low_lp1_y_255;
			t_sample L_ap_low_lp1_y2p = m_L_ap_low_lp1_y_254;
			t_sample L_ap_low_lp_s1 = (((((L_lp_b0_h * L_low_raw) + (L_lp_b1_h * L_ap_low_lp1_x1p)) + (L_lp_b2_h * L_ap_low_lp1_x2p)) - (L_lp_a1_h * L_ap_low_lp1_y1p)) - (L_lp_a2_h * L_ap_low_lp1_y2p));
			m_L_ap_low_lp1_x_256 = L_ap_low_lp1_x1p;
			m_L_ap_low_lp1_x_24 = L_low_raw;
			m_L_ap_low_lp1_y_254 = L_ap_low_lp1_y1p;
			m_L_ap_low_lp1_y_255 = L_ap_low_lp_s1;
			t_sample L_ap_low_lp2_x1p = m_L_ap_low_lp2_x_22;
			t_sample L_ap_low_lp2_x2p = m_L_ap_low_lp2_x_253;
			t_sample L_ap_low_lp2_y1p = m_L_ap_low_lp2_y_252;
			t_sample L_ap_low_lp2_y2p = m_L_ap_low_lp2_y_251;
			t_sample L_ap_low_lp = (((((L_lp_b0_h * L_ap_low_lp_s1) + (L_lp_b1_h * L_ap_low_lp2_x1p)) + (L_lp_b2_h * L_ap_low_lp2_x2p)) - (L_lp_a1_h * L_ap_low_lp2_y1p)) - (L_lp_a2_h * L_ap_low_lp2_y2p));
			m_L_ap_low_lp2_x_253 = L_ap_low_lp2_x1p;
			m_L_ap_low_lp2_x_22 = L_ap_low_lp_s1;
			m_L_ap_low_lp2_y_251 = L_ap_low_lp2_y1p;
			m_L_ap_low_lp2_y_252 = L_ap_low_lp;
			t_sample L_ap_low_hp1_x1p = m_L_ap_low_hp1_x_20;
			t_sample L_ap_low_hp1_x2p = m_L_ap_low_hp1_x_250;
			t_sample L_ap_low_hp1_y1p = m_L_ap_low_hp1_y_249;
			t_sample L_ap_low_hp1_y2p = m_L_ap_low_hp1_y_248;
			t_sample L_ap_low_hp_s1 = (((((L_hp_b0_h * L_low_raw) + (L_hp_b1_h * L_ap_low_hp1_x1p)) + (L_hp_b2_h * L_ap_low_hp1_x2p)) - (L_hp_a1_h * L_ap_low_hp1_y1p)) - (L_hp_a2_h * L_ap_low_hp1_y2p));
			m_L_ap_low_hp1_x_250 = L_ap_low_hp1_x1p;
			m_L_ap_low_hp1_x_20 = L_low_raw;
			m_L_ap_low_hp1_y_248 = L_ap_low_hp1_y1p;
			m_L_ap_low_hp1_y_249 = L_ap_low_hp_s1;
			t_sample L_ap_low_hp2_x1p = m_L_ap_low_hp2_x_18;
			t_sample L_ap_low_hp2_x2p = m_L_ap_low_hp2_x_247;
			t_sample L_ap_low_hp2_y1p = m_L_ap_low_hp2_y_246;
			t_sample L_ap_low_hp2_y2p = m_L_ap_low_hp2_y_245;
			t_sample L_ap_low_hp = (((((L_hp_b0_h * L_ap_low_hp_s1) + (L_hp_b1_h * L_ap_low_hp2_x1p)) + (L_hp_b2_h * L_ap_low_hp2_x2p)) - (L_hp_a1_h * L_ap_low_hp2_y1p)) - (L_hp_a2_h * L_ap_low_hp2_y2p));
			m_L_ap_low_hp2_x_247 = L_ap_low_hp2_x1p;
			m_L_ap_low_hp2_x_18 = L_ap_low_hp_s1;
			m_L_ap_low_hp2_y_245 = L_ap_low_hp2_y1p;
			m_L_ap_low_hp2_y_246 = L_ap_low_hp;
			t_sample L_low = (L_ap_low_lp + L_ap_low_hp);
			t_sample L_m1_x1p = m_L_m1_x_32;
			t_sample L_m1_x2p = m_L_m1_x_268;
			t_sample L_m1_y1p = m_L_m1_y_267;
			t_sample L_m1_y2p = m_L_m1_y_266;
			t_sample L_mid_s1 = (((((L_lp_b0_h * L_rest) + (L_lp_b1_h * L_m1_x1p)) + (L_lp_b2_h * L_m1_x2p)) - (L_lp_a1_h * L_m1_y1p)) - (L_lp_a2_h * L_m1_y2p));
			m_L_m1_x_268 = L_m1_x1p;
			m_L_m1_x_32 = L_rest;
			m_L_m1_y_266 = L_m1_y1p;
			m_L_m1_y_267 = L_mid_s1;
			t_sample L_m2_x1p = m_L_m2_x_30;
			t_sample L_m2_x2p = m_L_m2_x_265;
			t_sample L_m2_y1p = m_L_m2_y_264;
			t_sample L_m2_y2p = m_L_m2_y_263;
			t_sample L_mid = (((((L_lp_b0_h * L_mid_s1) + (L_lp_b1_h * L_m2_x1p)) + (L_lp_b2_h * L_m2_x2p)) - (L_lp_a1_h * L_m2_y1p)) - (L_lp_a2_h * L_m2_y2p));
			m_L_m2_x_265 = L_m2_x1p;
			m_L_m2_x_30 = L_mid_s1;
			m_L_m2_y_263 = L_m2_y1p;
			m_L_m2_y_264 = L_mid;
			t_sample L_u1_x1p = m_L_u1_x_28;
			t_sample L_u1_x2p = m_L_u1_x_262;
			t_sample L_u1_y1p = m_L_u1_y_261;
			t_sample L_u1_y2p = m_L_u1_y_260;
			t_sample L_high_s1 = (((((L_hp_b0_h * L_rest) + (L_hp_b1_h * L_u1_x1p)) + (L_hp_b2_h * L_u1_x2p)) - (L_hp_a1_h * L_u1_y1p)) - (L_hp_a2_h * L_u1_y2p));
			m_L_u1_x_262 = L_u1_x1p;
			m_L_u1_x_28 = L_rest;
			m_L_u1_y_260 = L_u1_y1p;
			m_L_u1_y_261 = L_high_s1;
			t_sample L_u2_x1p = m_L_u2_x_26;
			t_sample L_u2_x2p = m_L_u2_x_259;
			t_sample L_u2_y1p = m_L_u2_y_258;
			t_sample L_u2_y2p = m_L_u2_y_257;
			t_sample L_high = (((((L_hp_b0_h * L_high_s1) + (L_hp_b1_h * L_u2_x1p)) + (L_hp_b2_h * L_u2_x2p)) - (L_hp_a1_h * L_u2_y1p)) - (L_hp_a2_h * L_u2_y2p));
			m_L_u2_x_259 = L_u2_x1p;
			m_L_u2_x_26 = L_high_s1;
			m_L_u2_y_257 = L_u2_y1p;
			m_L_u2_y_258 = L_high;
			t_sample lowL = L_low;
			t_sample midL = L_mid;
			t_sample highL = L_high;
			t_sample R_loF = smoothHpfFreq;
			t_sample R_hiF = smoothLpfFreq;
			t_sample R_x = rTrimmed;
			t_sample maxb_304 = ((minb_303 < R_loF) ? minb_303 : R_loF);
			t_sample R_loF_2087 = ((((int)10) < maxb_304) ? maxb_304 : ((int)10));
			t_sample maxb_306 = ((minb_305 < R_hiF) ? minb_305 : R_hiF);
			t_sample R_hiFr = ((((int)10) < maxb_306) ? maxb_306 : ((int)10));
			t_sample maxb_307 = (R_loF_2087 + ((int)1));
			t_sample R_hiF_2088 = ((R_hiFr < maxb_307) ? maxb_307 : R_hiFr);
			t_sample R_w0_lo = safediv((((t_sample)6.2831853071796) * R_loF_2087), R_sr);
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
			t_sample R_w0_hi = safediv((((t_sample)6.2831853071796) * R_hiF_2088), R_sr);
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
			t_sample R_l1_x2p = m_R_l1_x_220;
			t_sample R_l1_y1p = m_R_l1_y_219;
			t_sample R_l1_y2p = m_R_l1_y_218;
			t_sample R_low_s1 = (((((R_lp_b0_l * R_x) + (R_lp_b1_l * R_l1_x1p)) + (R_lp_b2_l * R_l1_x2p)) - (R_lp_a1_l * R_l1_y1p)) - (R_lp_a2_l * R_l1_y2p));
			m_R_l1_x_220 = R_l1_x1p;
			m_R_l1_x_39 = R_x;
			m_R_l1_y_218 = R_l1_y1p;
			m_R_l1_y_219 = R_low_s1;
			t_sample R_l2_x1p = m_R_l2_x_37;
			t_sample R_l2_x2p = m_R_l2_x_217;
			t_sample R_l2_y1p = m_R_l2_y_216;
			t_sample R_l2_y2p = m_R_l2_y_215;
			t_sample R_low_raw = (((((R_lp_b0_l * R_low_s1) + (R_lp_b1_l * R_l2_x1p)) + (R_lp_b2_l * R_l2_x2p)) - (R_lp_a1_l * R_l2_y1p)) - (R_lp_a2_l * R_l2_y2p));
			m_R_l2_x_217 = R_l2_x1p;
			m_R_l2_x_37 = R_low_s1;
			m_R_l2_y_215 = R_l2_y1p;
			m_R_l2_y_216 = R_low_raw;
			t_sample R_h1_x1p = m_R_h1_x_35;
			t_sample R_h1_x2p = m_R_h1_x_214;
			t_sample R_h1_y1p = m_R_h1_y_213;
			t_sample R_h1_y2p = m_R_h1_y_212;
			t_sample R_rest_s1 = (((((R_hp_b0_l * R_x) + (R_hp_b1_l * R_h1_x1p)) + (R_hp_b2_l * R_h1_x2p)) - (R_hp_a1_l * R_h1_y1p)) - (R_hp_a2_l * R_h1_y2p));
			m_R_h1_x_214 = R_h1_x1p;
			m_R_h1_x_35 = R_x;
			m_R_h1_y_212 = R_h1_y1p;
			m_R_h1_y_213 = R_rest_s1;
			t_sample R_h2_x1p = m_R_h2_x_33;
			t_sample R_h2_x2p = m_R_h2_x_211;
			t_sample R_h2_y1p = m_R_h2_y_210;
			t_sample R_h2_y2p = m_R_h2_y_209;
			t_sample R_rest = (((((R_hp_b0_l * R_rest_s1) + (R_hp_b1_l * R_h2_x1p)) + (R_hp_b2_l * R_h2_x2p)) - (R_hp_a1_l * R_h2_y1p)) - (R_hp_a2_l * R_h2_y2p));
			m_R_h2_x_211 = R_h2_x1p;
			m_R_h2_x_33 = R_rest_s1;
			m_R_h2_y_209 = R_h2_y1p;
			m_R_h2_y_210 = R_rest;
			t_sample R_ap_low_lp1_x1p = m_R_ap_low_lp1_x_23;
			t_sample R_ap_low_lp1_x2p = m_R_ap_low_lp1_x_196;
			t_sample R_ap_low_lp1_y1p = m_R_ap_low_lp1_y_195;
			t_sample R_ap_low_lp1_y2p = m_R_ap_low_lp1_y_194;
			t_sample R_ap_low_lp_s1 = (((((R_lp_b0_h * R_low_raw) + (R_lp_b1_h * R_ap_low_lp1_x1p)) + (R_lp_b2_h * R_ap_low_lp1_x2p)) - (R_lp_a1_h * R_ap_low_lp1_y1p)) - (R_lp_a2_h * R_ap_low_lp1_y2p));
			m_R_ap_low_lp1_x_196 = R_ap_low_lp1_x1p;
			m_R_ap_low_lp1_x_23 = R_low_raw;
			m_R_ap_low_lp1_y_194 = R_ap_low_lp1_y1p;
			m_R_ap_low_lp1_y_195 = R_ap_low_lp_s1;
			t_sample R_ap_low_lp2_x1p = m_R_ap_low_lp2_x_21;
			t_sample R_ap_low_lp2_x2p = m_R_ap_low_lp2_x_193;
			t_sample R_ap_low_lp2_y1p = m_R_ap_low_lp2_y_192;
			t_sample R_ap_low_lp2_y2p = m_R_ap_low_lp2_y_191;
			t_sample R_ap_low_lp = (((((R_lp_b0_h * R_ap_low_lp_s1) + (R_lp_b1_h * R_ap_low_lp2_x1p)) + (R_lp_b2_h * R_ap_low_lp2_x2p)) - (R_lp_a1_h * R_ap_low_lp2_y1p)) - (R_lp_a2_h * R_ap_low_lp2_y2p));
			m_R_ap_low_lp2_x_193 = R_ap_low_lp2_x1p;
			m_R_ap_low_lp2_x_21 = R_ap_low_lp_s1;
			m_R_ap_low_lp2_y_191 = R_ap_low_lp2_y1p;
			m_R_ap_low_lp2_y_192 = R_ap_low_lp;
			t_sample R_ap_low_hp1_x1p = m_R_ap_low_hp1_x_19;
			t_sample R_ap_low_hp1_x2p = m_R_ap_low_hp1_x_190;
			t_sample R_ap_low_hp1_y1p = m_R_ap_low_hp1_y_189;
			t_sample R_ap_low_hp1_y2p = m_R_ap_low_hp1_y_188;
			t_sample R_ap_low_hp_s1 = (((((R_hp_b0_h * R_low_raw) + (R_hp_b1_h * R_ap_low_hp1_x1p)) + (R_hp_b2_h * R_ap_low_hp1_x2p)) - (R_hp_a1_h * R_ap_low_hp1_y1p)) - (R_hp_a2_h * R_ap_low_hp1_y2p));
			m_R_ap_low_hp1_x_190 = R_ap_low_hp1_x1p;
			m_R_ap_low_hp1_x_19 = R_low_raw;
			m_R_ap_low_hp1_y_188 = R_ap_low_hp1_y1p;
			m_R_ap_low_hp1_y_189 = R_ap_low_hp_s1;
			t_sample R_ap_low_hp2_x1p = m_R_ap_low_hp2_x_17;
			t_sample R_ap_low_hp2_x2p = m_R_ap_low_hp2_x_187;
			t_sample R_ap_low_hp2_y1p = m_R_ap_low_hp2_y_186;
			t_sample R_ap_low_hp2_y2p = m_R_ap_low_hp2_y_185;
			t_sample R_ap_low_hp = (((((R_hp_b0_h * R_ap_low_hp_s1) + (R_hp_b1_h * R_ap_low_hp2_x1p)) + (R_hp_b2_h * R_ap_low_hp2_x2p)) - (R_hp_a1_h * R_ap_low_hp2_y1p)) - (R_hp_a2_h * R_ap_low_hp2_y2p));
			m_R_ap_low_hp2_x_187 = R_ap_low_hp2_x1p;
			m_R_ap_low_hp2_x_17 = R_ap_low_hp_s1;
			m_R_ap_low_hp2_y_185 = R_ap_low_hp2_y1p;
			m_R_ap_low_hp2_y_186 = R_ap_low_hp;
			t_sample R_low = (R_ap_low_lp + R_ap_low_hp);
			t_sample R_m1_x1p = m_R_m1_x_31;
			t_sample R_m1_x2p = m_R_m1_x_208;
			t_sample R_m1_y1p = m_R_m1_y_207;
			t_sample R_m1_y2p = m_R_m1_y_206;
			t_sample R_mid_s1 = (((((R_lp_b0_h * R_rest) + (R_lp_b1_h * R_m1_x1p)) + (R_lp_b2_h * R_m1_x2p)) - (R_lp_a1_h * R_m1_y1p)) - (R_lp_a2_h * R_m1_y2p));
			m_R_m1_x_208 = R_m1_x1p;
			m_R_m1_x_31 = R_rest;
			m_R_m1_y_206 = R_m1_y1p;
			m_R_m1_y_207 = R_mid_s1;
			t_sample R_m2_x1p = m_R_m2_x_29;
			t_sample R_m2_x2p = m_R_m2_x_205;
			t_sample R_m2_y1p = m_R_m2_y_204;
			t_sample R_m2_y2p = m_R_m2_y_203;
			t_sample R_mid = (((((R_lp_b0_h * R_mid_s1) + (R_lp_b1_h * R_m2_x1p)) + (R_lp_b2_h * R_m2_x2p)) - (R_lp_a1_h * R_m2_y1p)) - (R_lp_a2_h * R_m2_y2p));
			m_R_m2_x_205 = R_m2_x1p;
			m_R_m2_x_29 = R_mid_s1;
			m_R_m2_y_203 = R_m2_y1p;
			m_R_m2_y_204 = R_mid;
			t_sample R_u1_x1p = m_R_u1_x_27;
			t_sample R_u1_x2p = m_R_u1_x_202;
			t_sample R_u1_y1p = m_R_u1_y_201;
			t_sample R_u1_y2p = m_R_u1_y_200;
			t_sample R_high_s1 = (((((R_hp_b0_h * R_rest) + (R_hp_b1_h * R_u1_x1p)) + (R_hp_b2_h * R_u1_x2p)) - (R_hp_a1_h * R_u1_y1p)) - (R_hp_a2_h * R_u1_y2p));
			m_R_u1_x_202 = R_u1_x1p;
			m_R_u1_x_27 = R_rest;
			m_R_u1_y_200 = R_u1_y1p;
			m_R_u1_y_201 = R_high_s1;
			t_sample R_u2_x1p = m_R_u2_x_25;
			t_sample R_u2_x2p = m_R_u2_x_199;
			t_sample R_u2_y1p = m_R_u2_y_198;
			t_sample R_u2_y2p = m_R_u2_y_197;
			t_sample R_high = (((((R_hp_b0_h * R_high_s1) + (R_hp_b1_h * R_u2_x1p)) + (R_hp_b2_h * R_u2_x2p)) - (R_hp_a1_h * R_u2_y1p)) - (R_hp_a2_h * R_u2_y2p));
			m_R_u2_x_199 = R_u2_x1p;
			m_R_u2_x_25 = R_high_s1;
			m_R_u2_y_197 = R_u2_y1p;
			m_R_u2_y_198 = R_high;
			t_sample lowR = R_low;
			t_sample midR = R_mid;
			t_sample highR = R_high;
			t_sample maxb_308 = (((int)1) - fabs((smoothedBand - ((int)0))));
			t_sample wLow = ((((int)0) < maxb_308) ? maxb_308 : ((int)0));
			t_sample maxb_309 = (((int)1) - fabs((smoothedBand - ((int)1))));
			t_sample wMid = ((((int)0) < maxb_309) ? maxb_309 : ((int)0));
			t_sample maxb_310 = (((int)1) - fabs((smoothedBand - ((int)2))));
			t_sample wHigh = ((((int)0) < maxb_310) ? maxb_310 : ((int)0));
			t_sample maxb_311 = ((wLow + wMid) + wHigh);
			t_sample wSum = ((((t_sample)1e-09) < maxb_311) ? maxb_311 : ((t_sample)1e-09));
			t_sample wLow_2090 = safediv(wLow, wSum);
			t_sample wMid_2091 = safediv(wMid, wSum);
			t_sample wHigh_2092 = safediv(wHigh, wSum);
			t_sample preBandL = (((wLow_2090 * lowL) + (wMid_2091 * midL)) + (wHigh_2092 * highL));
			t_sample preBandR = (((wLow_2090 * lowR) + (wMid_2091 * midR)) + (wHigh_2092 * highR));
			t_sample sumBandsL = ((lowL + midL) + highL);
			t_sample sumBandsR = ((lowR + midR) + highR);
			t_sample bypassWhenActiveL = (sumBandsL - preBandL);
			t_sample bypassWhenActiveR = (sumBandsR - preBandR);
			t_sample mix_2206 = (lTrimmed + (scSm * (preBandL - lTrimmed)));
			t_sample preDistInL = mix_2206;
			t_sample mix_2207 = (rTrimmed + (scSm * (preBandR - rTrimmed)));
			t_sample preDistInR = mix_2207;
			t_sample L_loF_2093 = smoothHpfFreq;
			t_sample L_hiF_2094 = smoothLpfFreq;
			t_sample L_x_2095 = lTrimmed;
			t_sample maxb_313 = ((minb_312 < L_loF_2093) ? minb_312 : L_loF_2093);
			t_sample L_loF_2099 = ((((int)10) < maxb_313) ? maxb_313 : ((int)10));
			t_sample maxb_315 = ((minb_314 < L_hiF_2094) ? minb_314 : L_hiF_2094);
			t_sample L_hiFr_2100 = ((((int)10) < maxb_315) ? maxb_315 : ((int)10));
			t_sample maxb_316 = (L_loF_2099 + ((int)1));
			t_sample L_hiF_2101 = ((L_hiFr_2100 < maxb_316) ? maxb_316 : L_hiFr_2100);
			t_sample L_w0_lo_2102 = safediv((((t_sample)6.2831853071796) * L_loF_2099), L_sr_2098);
			t_sample L_cos_lo_2103 = cos(L_w0_lo_2102);
			t_sample L_sin_lo_2104 = sin(L_w0_lo_2102);
			t_sample L_alpha_lo_2105 = (L_sin_lo_2104 * ((t_sample)0.70710678118655));
			t_sample L_a0_lo_2106 = (((int)1) + L_alpha_lo_2105);
			t_sample L_a1_lo_2107 = (((int)-2) * L_cos_lo_2103);
			t_sample L_a2_lo_2108 = (((int)1) - L_alpha_lo_2105);
			t_sample L_lp_b0_l_2109 = safediv(((((int)1) - L_cos_lo_2103) * ((t_sample)0.5)), L_a0_lo_2106);
			t_sample L_lp_b1_l_2110 = safediv((((int)1) - L_cos_lo_2103), L_a0_lo_2106);
			t_sample L_lp_b2_l_2111 = L_lp_b0_l_2109;
			t_sample L_lp_a1_l_2112 = safediv(L_a1_lo_2107, L_a0_lo_2106);
			t_sample L_lp_a2_l_2113 = safediv(L_a2_lo_2108, L_a0_lo_2106);
			t_sample L_hp_b0_l_2114 = safediv(((((int)1) + L_cos_lo_2103) * ((t_sample)0.5)), L_a0_lo_2106);
			t_sample L_hp_b1_l_2115 = safediv((-(((int)1) + L_cos_lo_2103)), L_a0_lo_2106);
			t_sample L_hp_b2_l_2116 = L_hp_b0_l_2114;
			t_sample L_hp_a1_l_2117 = L_lp_a1_l_2112;
			t_sample L_hp_a2_l_2118 = L_lp_a2_l_2113;
			t_sample L_w0_hi_2119 = safediv((((t_sample)6.2831853071796) * L_hiF_2101), L_sr_2098);
			t_sample L_cos_hi_2120 = cos(L_w0_hi_2119);
			t_sample L_sin_hi_2121 = sin(L_w0_hi_2119);
			t_sample L_alpha_hi_2122 = (L_sin_hi_2121 * ((t_sample)0.70710678118655));
			t_sample L_a0_hi_2123 = (((int)1) + L_alpha_hi_2122);
			t_sample L_a1_hi_2124 = (((int)-2) * L_cos_hi_2120);
			t_sample L_a2_hi_2125 = (((int)1) - L_alpha_hi_2122);
			t_sample L_lp_b0_h_2126 = safediv(((((int)1) - L_cos_hi_2120) * ((t_sample)0.5)), L_a0_hi_2123);
			t_sample L_lp_b1_h_2127 = safediv((((int)1) - L_cos_hi_2120), L_a0_hi_2123);
			t_sample L_lp_b2_h_2128 = L_lp_b0_h_2126;
			t_sample L_lp_a1_h_2129 = safediv(L_a1_hi_2124, L_a0_hi_2123);
			t_sample L_lp_a2_h_2130 = safediv(L_a2_hi_2125, L_a0_hi_2123);
			t_sample L_hp_b0_h_2131 = safediv(((((int)1) + L_cos_hi_2120) * ((t_sample)0.5)), L_a0_hi_2123);
			t_sample L_hp_b1_h_2132 = safediv((-(((int)1) + L_cos_hi_2120)), L_a0_hi_2123);
			t_sample L_hp_b2_h_2133 = L_hp_b0_h_2131;
			t_sample L_hp_a1_h_2134 = L_lp_a1_h_2129;
			t_sample L_hp_a2_h_2135 = L_lp_a2_h_2130;
			t_sample L_ap1_lp1_x1p = m_L_ap1_lp1_x_16;
			t_sample L_ap1_lp1_x2p = m_L_ap1_lp1_x_244;
			t_sample L_ap1_lp1_y1p = m_L_ap1_lp1_y_243;
			t_sample L_ap1_lp1_y2p = m_L_ap1_lp1_y_242;
			t_sample L_ap1_lp_s1 = (((((L_lp_b0_l_2109 * L_x_2095) + (L_lp_b1_l_2110 * L_ap1_lp1_x1p)) + (L_lp_b2_l_2111 * L_ap1_lp1_x2p)) - (L_lp_a1_l_2112 * L_ap1_lp1_y1p)) - (L_lp_a2_l_2113 * L_ap1_lp1_y2p));
			m_L_ap1_lp1_x_244 = L_ap1_lp1_x1p;
			m_L_ap1_lp1_x_16 = L_x_2095;
			m_L_ap1_lp1_y_242 = L_ap1_lp1_y1p;
			m_L_ap1_lp1_y_243 = L_ap1_lp_s1;
			t_sample L_ap1_lp2_x1p = m_L_ap1_lp2_x_14;
			t_sample L_ap1_lp2_x2p = m_L_ap1_lp2_x_241;
			t_sample L_ap1_lp2_y1p = m_L_ap1_lp2_y_240;
			t_sample L_ap1_lp2_y2p = m_L_ap1_lp2_y_239;
			t_sample L_ap1_lp = (((((L_lp_b0_l_2109 * L_ap1_lp_s1) + (L_lp_b1_l_2110 * L_ap1_lp2_x1p)) + (L_lp_b2_l_2111 * L_ap1_lp2_x2p)) - (L_lp_a1_l_2112 * L_ap1_lp2_y1p)) - (L_lp_a2_l_2113 * L_ap1_lp2_y2p));
			m_L_ap1_lp2_x_241 = L_ap1_lp2_x1p;
			m_L_ap1_lp2_x_14 = L_ap1_lp_s1;
			m_L_ap1_lp2_y_239 = L_ap1_lp2_y1p;
			m_L_ap1_lp2_y_240 = L_ap1_lp;
			t_sample L_ap1_hp1_x1p = m_L_ap1_hp1_x_12;
			t_sample L_ap1_hp1_x2p = m_L_ap1_hp1_x_238;
			t_sample L_ap1_hp1_y1p = m_L_ap1_hp1_y_237;
			t_sample L_ap1_hp1_y2p = m_L_ap1_hp1_y_236;
			t_sample L_ap1_hp_s1 = (((((L_hp_b0_l_2114 * L_x_2095) + (L_hp_b1_l_2115 * L_ap1_hp1_x1p)) + (L_hp_b2_l_2116 * L_ap1_hp1_x2p)) - (L_hp_a1_l_2117 * L_ap1_hp1_y1p)) - (L_hp_a2_l_2118 * L_ap1_hp1_y2p));
			m_L_ap1_hp1_x_238 = L_ap1_hp1_x1p;
			m_L_ap1_hp1_x_12 = L_x_2095;
			m_L_ap1_hp1_y_236 = L_ap1_hp1_y1p;
			m_L_ap1_hp1_y_237 = L_ap1_hp_s1;
			t_sample L_ap1_hp2_x1p = m_L_ap1_hp2_x_10;
			t_sample L_ap1_hp2_x2p = m_L_ap1_hp2_x_235;
			t_sample L_ap1_hp2_y1p = m_L_ap1_hp2_y_234;
			t_sample L_ap1_hp2_y2p = m_L_ap1_hp2_y_233;
			t_sample L_ap1_hp = (((((L_hp_b0_l_2114 * L_ap1_hp_s1) + (L_hp_b1_l_2115 * L_ap1_hp2_x1p)) + (L_hp_b2_l_2116 * L_ap1_hp2_x2p)) - (L_hp_a1_l_2117 * L_ap1_hp2_y1p)) - (L_hp_a2_l_2118 * L_ap1_hp2_y2p));
			m_L_ap1_hp2_x_235 = L_ap1_hp2_x1p;
			m_L_ap1_hp2_x_10 = L_ap1_hp_s1;
			m_L_ap1_hp2_y_233 = L_ap1_hp2_y1p;
			m_L_ap1_hp2_y_234 = L_ap1_hp;
			t_sample L_stage1_out = (L_ap1_lp + L_ap1_hp);
			t_sample L_ap2_lp1_x1p = m_L_ap2_lp1_x_8;
			t_sample L_ap2_lp1_x2p = m_L_ap2_lp1_x_232;
			t_sample L_ap2_lp1_y1p = m_L_ap2_lp1_y_231;
			t_sample L_ap2_lp1_y2p = m_L_ap2_lp1_y_230;
			t_sample L_ap2_lp_s1 = (((((L_lp_b0_h_2126 * L_stage1_out) + (L_lp_b1_h_2127 * L_ap2_lp1_x1p)) + (L_lp_b2_h_2128 * L_ap2_lp1_x2p)) - (L_lp_a1_h_2129 * L_ap2_lp1_y1p)) - (L_lp_a2_h_2130 * L_ap2_lp1_y2p));
			m_L_ap2_lp1_x_232 = L_ap2_lp1_x1p;
			m_L_ap2_lp1_x_8 = L_stage1_out;
			m_L_ap2_lp1_y_230 = L_ap2_lp1_y1p;
			m_L_ap2_lp1_y_231 = L_ap2_lp_s1;
			t_sample L_ap2_lp2_x1p = m_L_ap2_lp2_x_6;
			t_sample L_ap2_lp2_x2p = m_L_ap2_lp2_x_229;
			t_sample L_ap2_lp2_y1p = m_L_ap2_lp2_y_228;
			t_sample L_ap2_lp2_y2p = m_L_ap2_lp2_y_227;
			t_sample L_ap2_lp = (((((L_lp_b0_h_2126 * L_ap2_lp_s1) + (L_lp_b1_h_2127 * L_ap2_lp2_x1p)) + (L_lp_b2_h_2128 * L_ap2_lp2_x2p)) - (L_lp_a1_h_2129 * L_ap2_lp2_y1p)) - (L_lp_a2_h_2130 * L_ap2_lp2_y2p));
			m_L_ap2_lp2_x_229 = L_ap2_lp2_x1p;
			m_L_ap2_lp2_x_6 = L_ap2_lp_s1;
			m_L_ap2_lp2_y_227 = L_ap2_lp2_y1p;
			m_L_ap2_lp2_y_228 = L_ap2_lp;
			t_sample L_ap2_hp1_x1p = m_L_ap2_hp1_x_4;
			t_sample L_ap2_hp1_x2p = m_L_ap2_hp1_x_226;
			t_sample L_ap2_hp1_y1p = m_L_ap2_hp1_y_225;
			t_sample L_ap2_hp1_y2p = m_L_ap2_hp1_y_224;
			t_sample L_ap2_hp_s1 = (((((L_hp_b0_h_2131 * L_stage1_out) + (L_hp_b1_h_2132 * L_ap2_hp1_x1p)) + (L_hp_b2_h_2133 * L_ap2_hp1_x2p)) - (L_hp_a1_h_2134 * L_ap2_hp1_y1p)) - (L_hp_a2_h_2135 * L_ap2_hp1_y2p));
			m_L_ap2_hp1_x_226 = L_ap2_hp1_x1p;
			m_L_ap2_hp1_x_4 = L_stage1_out;
			m_L_ap2_hp1_y_224 = L_ap2_hp1_y1p;
			m_L_ap2_hp1_y_225 = L_ap2_hp_s1;
			t_sample L_ap2_hp2_x1p = m_L_ap2_hp2_x_2;
			t_sample L_ap2_hp2_x2p = m_L_ap2_hp2_x_223;
			t_sample L_ap2_hp2_y1p = m_L_ap2_hp2_y_222;
			t_sample L_ap2_hp2_y2p = m_L_ap2_hp2_y_221;
			t_sample L_ap2_hp = (((((L_hp_b0_h_2131 * L_ap2_hp_s1) + (L_hp_b1_h_2132 * L_ap2_hp2_x1p)) + (L_hp_b2_h_2133 * L_ap2_hp2_x2p)) - (L_hp_a1_h_2134 * L_ap2_hp2_y1p)) - (L_hp_a2_h_2135 * L_ap2_hp2_y2p));
			m_L_ap2_hp2_x_223 = L_ap2_hp2_x1p;
			m_L_ap2_hp2_x_2 = L_ap2_hp_s1;
			m_L_ap2_hp2_y_221 = L_ap2_hp2_y1p;
			m_L_ap2_hp2_y_222 = L_ap2_hp;
			t_sample dryCompL = (L_ap2_lp + L_ap2_hp);
			t_sample R_loF_2136 = smoothHpfFreq;
			t_sample R_hiF_2137 = smoothLpfFreq;
			t_sample R_x_2138 = rTrimmed;
			t_sample maxb_318 = ((minb_317 < R_loF_2136) ? minb_317 : R_loF_2136);
			t_sample R_loF_2142 = ((((int)10) < maxb_318) ? maxb_318 : ((int)10));
			t_sample maxb_320 = ((minb_319 < R_hiF_2137) ? minb_319 : R_hiF_2137);
			t_sample R_hiFr_2143 = ((((int)10) < maxb_320) ? maxb_320 : ((int)10));
			t_sample maxb_321 = (R_loF_2142 + ((int)1));
			t_sample R_hiF_2144 = ((R_hiFr_2143 < maxb_321) ? maxb_321 : R_hiFr_2143);
			t_sample R_w0_lo_2145 = safediv((((t_sample)6.2831853071796) * R_loF_2142), R_sr_2141);
			t_sample R_cos_lo_2146 = cos(R_w0_lo_2145);
			t_sample R_sin_lo_2147 = sin(R_w0_lo_2145);
			t_sample R_alpha_lo_2148 = (R_sin_lo_2147 * ((t_sample)0.70710678118655));
			t_sample R_a0_lo_2149 = (((int)1) + R_alpha_lo_2148);
			t_sample R_a1_lo_2150 = (((int)-2) * R_cos_lo_2146);
			t_sample R_a2_lo_2151 = (((int)1) - R_alpha_lo_2148);
			t_sample R_lp_b0_l_2152 = safediv(((((int)1) - R_cos_lo_2146) * ((t_sample)0.5)), R_a0_lo_2149);
			t_sample R_lp_b1_l_2153 = safediv((((int)1) - R_cos_lo_2146), R_a0_lo_2149);
			t_sample R_lp_b2_l_2154 = R_lp_b0_l_2152;
			t_sample R_lp_a1_l_2155 = safediv(R_a1_lo_2150, R_a0_lo_2149);
			t_sample R_lp_a2_l_2156 = safediv(R_a2_lo_2151, R_a0_lo_2149);
			t_sample R_hp_b0_l_2157 = safediv(((((int)1) + R_cos_lo_2146) * ((t_sample)0.5)), R_a0_lo_2149);
			t_sample R_hp_b1_l_2158 = safediv((-(((int)1) + R_cos_lo_2146)), R_a0_lo_2149);
			t_sample R_hp_b2_l_2159 = R_hp_b0_l_2157;
			t_sample R_hp_a1_l_2160 = R_lp_a1_l_2155;
			t_sample R_hp_a2_l_2161 = R_lp_a2_l_2156;
			t_sample R_w0_hi_2162 = safediv((((t_sample)6.2831853071796) * R_hiF_2144), R_sr_2141);
			t_sample R_cos_hi_2163 = cos(R_w0_hi_2162);
			t_sample R_sin_hi_2164 = sin(R_w0_hi_2162);
			t_sample R_alpha_hi_2165 = (R_sin_hi_2164 * ((t_sample)0.70710678118655));
			t_sample R_a0_hi_2166 = (((int)1) + R_alpha_hi_2165);
			t_sample R_a1_hi_2167 = (((int)-2) * R_cos_hi_2163);
			t_sample R_a2_hi_2168 = (((int)1) - R_alpha_hi_2165);
			t_sample R_lp_b0_h_2169 = safediv(((((int)1) - R_cos_hi_2163) * ((t_sample)0.5)), R_a0_hi_2166);
			t_sample R_lp_b1_h_2170 = safediv((((int)1) - R_cos_hi_2163), R_a0_hi_2166);
			t_sample R_lp_b2_h_2171 = R_lp_b0_h_2169;
			t_sample R_lp_a1_h_2172 = safediv(R_a1_hi_2167, R_a0_hi_2166);
			t_sample R_lp_a2_h_2173 = safediv(R_a2_hi_2168, R_a0_hi_2166);
			t_sample R_hp_b0_h_2174 = safediv(((((int)1) + R_cos_hi_2163) * ((t_sample)0.5)), R_a0_hi_2166);
			t_sample R_hp_b1_h_2175 = safediv((-(((int)1) + R_cos_hi_2163)), R_a0_hi_2166);
			t_sample R_hp_b2_h_2176 = R_hp_b0_h_2174;
			t_sample R_hp_a1_h_2177 = R_lp_a1_h_2172;
			t_sample R_hp_a2_h_2178 = R_lp_a2_h_2173;
			t_sample R_ap1_lp1_x1p = m_R_ap1_lp1_x_15;
			t_sample R_ap1_lp1_x2p = m_R_ap1_lp1_x_184;
			t_sample R_ap1_lp1_y1p = m_R_ap1_lp1_y_183;
			t_sample R_ap1_lp1_y2p = m_R_ap1_lp1_y_182;
			t_sample R_ap1_lp_s1 = (((((R_lp_b0_l_2152 * R_x_2138) + (R_lp_b1_l_2153 * R_ap1_lp1_x1p)) + (R_lp_b2_l_2154 * R_ap1_lp1_x2p)) - (R_lp_a1_l_2155 * R_ap1_lp1_y1p)) - (R_lp_a2_l_2156 * R_ap1_lp1_y2p));
			m_R_ap1_lp1_x_184 = R_ap1_lp1_x1p;
			m_R_ap1_lp1_x_15 = R_x_2138;
			m_R_ap1_lp1_y_182 = R_ap1_lp1_y1p;
			m_R_ap1_lp1_y_183 = R_ap1_lp_s1;
			t_sample R_ap1_lp2_x1p = m_R_ap1_lp2_x_13;
			t_sample R_ap1_lp2_x2p = m_R_ap1_lp2_x_181;
			t_sample R_ap1_lp2_y1p = m_R_ap1_lp2_y_180;
			t_sample R_ap1_lp2_y2p = m_R_ap1_lp2_y_179;
			t_sample R_ap1_lp = (((((R_lp_b0_l_2152 * R_ap1_lp_s1) + (R_lp_b1_l_2153 * R_ap1_lp2_x1p)) + (R_lp_b2_l_2154 * R_ap1_lp2_x2p)) - (R_lp_a1_l_2155 * R_ap1_lp2_y1p)) - (R_lp_a2_l_2156 * R_ap1_lp2_y2p));
			m_R_ap1_lp2_x_181 = R_ap1_lp2_x1p;
			m_R_ap1_lp2_x_13 = R_ap1_lp_s1;
			m_R_ap1_lp2_y_179 = R_ap1_lp2_y1p;
			m_R_ap1_lp2_y_180 = R_ap1_lp;
			t_sample R_ap1_hp1_x1p = m_R_ap1_hp1_x_11;
			t_sample R_ap1_hp1_x2p = m_R_ap1_hp1_x_178;
			t_sample R_ap1_hp1_y1p = m_R_ap1_hp1_y_177;
			t_sample R_ap1_hp1_y2p = m_R_ap1_hp1_y_176;
			t_sample R_ap1_hp_s1 = (((((R_hp_b0_l_2157 * R_x_2138) + (R_hp_b1_l_2158 * R_ap1_hp1_x1p)) + (R_hp_b2_l_2159 * R_ap1_hp1_x2p)) - (R_hp_a1_l_2160 * R_ap1_hp1_y1p)) - (R_hp_a2_l_2161 * R_ap1_hp1_y2p));
			m_R_ap1_hp1_x_178 = R_ap1_hp1_x1p;
			m_R_ap1_hp1_x_11 = R_x_2138;
			m_R_ap1_hp1_y_176 = R_ap1_hp1_y1p;
			m_R_ap1_hp1_y_177 = R_ap1_hp_s1;
			t_sample R_ap1_hp2_x1p = m_R_ap1_hp2_x_9;
			t_sample R_ap1_hp2_x2p = m_R_ap1_hp2_x_175;
			t_sample R_ap1_hp2_y1p = m_R_ap1_hp2_y_174;
			t_sample R_ap1_hp2_y2p = m_R_ap1_hp2_y_173;
			t_sample R_ap1_hp = (((((R_hp_b0_l_2157 * R_ap1_hp_s1) + (R_hp_b1_l_2158 * R_ap1_hp2_x1p)) + (R_hp_b2_l_2159 * R_ap1_hp2_x2p)) - (R_hp_a1_l_2160 * R_ap1_hp2_y1p)) - (R_hp_a2_l_2161 * R_ap1_hp2_y2p));
			m_R_ap1_hp2_x_175 = R_ap1_hp2_x1p;
			m_R_ap1_hp2_x_9 = R_ap1_hp_s1;
			m_R_ap1_hp2_y_173 = R_ap1_hp2_y1p;
			m_R_ap1_hp2_y_174 = R_ap1_hp;
			t_sample R_stage1_out = (R_ap1_lp + R_ap1_hp);
			t_sample R_ap2_lp1_x1p = m_R_ap2_lp1_x_7;
			t_sample R_ap2_lp1_x2p = m_R_ap2_lp1_x_172;
			t_sample R_ap2_lp1_y1p = m_R_ap2_lp1_y_171;
			t_sample R_ap2_lp1_y2p = m_R_ap2_lp1_y_170;
			t_sample R_ap2_lp_s1 = (((((R_lp_b0_h_2169 * R_stage1_out) + (R_lp_b1_h_2170 * R_ap2_lp1_x1p)) + (R_lp_b2_h_2171 * R_ap2_lp1_x2p)) - (R_lp_a1_h_2172 * R_ap2_lp1_y1p)) - (R_lp_a2_h_2173 * R_ap2_lp1_y2p));
			m_R_ap2_lp1_x_172 = R_ap2_lp1_x1p;
			m_R_ap2_lp1_x_7 = R_stage1_out;
			m_R_ap2_lp1_y_170 = R_ap2_lp1_y1p;
			m_R_ap2_lp1_y_171 = R_ap2_lp_s1;
			t_sample R_ap2_lp2_x1p = m_R_ap2_lp2_x_5;
			t_sample R_ap2_lp2_x2p = m_R_ap2_lp2_x_169;
			t_sample R_ap2_lp2_y1p = m_R_ap2_lp2_y_168;
			t_sample R_ap2_lp2_y2p = m_R_ap2_lp2_y_167;
			t_sample R_ap2_lp = (((((R_lp_b0_h_2169 * R_ap2_lp_s1) + (R_lp_b1_h_2170 * R_ap2_lp2_x1p)) + (R_lp_b2_h_2171 * R_ap2_lp2_x2p)) - (R_lp_a1_h_2172 * R_ap2_lp2_y1p)) - (R_lp_a2_h_2173 * R_ap2_lp2_y2p));
			m_R_ap2_lp2_x_169 = R_ap2_lp2_x1p;
			m_R_ap2_lp2_x_5 = R_ap2_lp_s1;
			m_R_ap2_lp2_y_167 = R_ap2_lp2_y1p;
			m_R_ap2_lp2_y_168 = R_ap2_lp;
			t_sample R_ap2_hp1_x1p = m_R_ap2_hp1_x_3;
			t_sample R_ap2_hp1_x2p = m_R_ap2_hp1_x_166;
			t_sample R_ap2_hp1_y1p = m_R_ap2_hp1_y_165;
			t_sample R_ap2_hp1_y2p = m_R_ap2_hp1_y_164;
			t_sample R_ap2_hp_s1 = (((((R_hp_b0_h_2174 * R_stage1_out) + (R_hp_b1_h_2175 * R_ap2_hp1_x1p)) + (R_hp_b2_h_2176 * R_ap2_hp1_x2p)) - (R_hp_a1_h_2177 * R_ap2_hp1_y1p)) - (R_hp_a2_h_2178 * R_ap2_hp1_y2p));
			m_R_ap2_hp1_x_166 = R_ap2_hp1_x1p;
			m_R_ap2_hp1_x_3 = R_stage1_out;
			m_R_ap2_hp1_y_164 = R_ap2_hp1_y1p;
			m_R_ap2_hp1_y_165 = R_ap2_hp_s1;
			t_sample R_ap2_hp2_x1p = m_R_ap2_hp2_x_1;
			t_sample R_ap2_hp2_x2p = m_R_ap2_hp2_x_163;
			t_sample R_ap2_hp2_y1p = m_R_ap2_hp2_y_162;
			t_sample R_ap2_hp2_y2p = m_R_ap2_hp2_y_161;
			t_sample R_ap2_hp = (((((R_hp_b0_h_2174 * R_ap2_hp_s1) + (R_hp_b1_h_2175 * R_ap2_hp2_x1p)) + (R_hp_b2_h_2176 * R_ap2_hp2_x2p)) - (R_hp_a1_h_2177 * R_ap2_hp2_y1p)) - (R_hp_a2_h_2178 * R_ap2_hp2_y2p));
			m_R_ap2_hp2_x_163 = R_ap2_hp2_x1p;
			m_R_ap2_hp2_x_1 = R_ap2_hp_s1;
			m_R_ap2_hp2_y_161 = R_ap2_hp2_y1p;
			m_R_ap2_hp2_y_162 = R_ap2_hp;
			t_sample dryCompR = (R_ap2_lp + R_ap2_hp);
			t_sample mix_2208 = (lIn + (scSm * (dryCompL - lIn)));
			t_sample mix_2209 = (rIn + (scSm * (dryCompR - rIn)));
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
			t_sample lLs_2179 = (((((a0Ls * lFiltered) + (a1Ls * m_tiltLsL_55)) + (a2Ls * m_tiltLsL_56)) - (b1Ls * m_tiltLsL_53)) - (b2Ls * m_tiltLsL_54));
			m_tiltLsL_56 = m_tiltLsL_55;
			m_tiltLsL_55 = lFiltered;
			m_tiltLsL_54 = m_tiltLsL_53;
			m_tiltLsL_53 = lLs_2179;
			t_sample rLs_2180 = (((((a0Ls * rFiltered) + (a1Ls * m_tiltLsR_51)) + (a2Ls * m_tiltLsR_52)) - (b1Ls * m_tiltLsR_49)) - (b2Ls * m_tiltLsR_50));
			m_tiltLsR_52 = m_tiltLsR_51;
			m_tiltLsR_51 = rFiltered;
			m_tiltLsR_50 = m_tiltLsR_49;
			m_tiltLsR_49 = rLs_2180;
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
			t_sample lTiltRaw = (((((a0Hs * lLs_2179) + (a1Hs * m_tiltHsL_47)) + (a2Hs * m_tiltHsL_48)) - (b1Hs * m_tiltHsL_45)) - (b2Hs * m_tiltHsL_46));
			m_tiltHsL_48 = m_tiltHsL_47;
			m_tiltHsL_47 = lLs_2179;
			m_tiltHsL_46 = m_tiltHsL_45;
			m_tiltHsL_45 = lTiltRaw;
			t_sample rTiltRaw = (((((a0Hs * rLs_2180) + (a1Hs * m_tiltHsR_43)) + (a2Hs * m_tiltHsR_44)) - (b1Hs * m_tiltHsR_41)) - (b2Hs * m_tiltHsR_42));
			m_tiltHsR_44 = m_tiltHsR_43;
			m_tiltHsR_43 = rLs_2180;
			m_tiltHsR_42 = m_tiltHsR_41;
			m_tiltHsR_41 = rTiltRaw;
			t_sample nr_ls = ((a0Ls + (a1Ls * cs)) + (a2Ls * cos2));
			t_sample ni_ls = (-((a1Ls * sn) + (a2Ls * sin2)));
			t_sample dr_ls = ((((int)1) + (b1Ls * cs)) + (b2Ls * cos2));
			t_sample di_ls = (-((b1Ls * sn) + (b2Ls * sin2)));
			t_sample maxb_322 = ((dr_ls * dr_ls) + (di_ls * di_ls));
			t_sample mag2_ls = safediv(((nr_ls * nr_ls) + (ni_ls * ni_ls)), ((((t_sample)1e-12) < maxb_322) ? maxb_322 : ((t_sample)1e-12)));
			t_sample mag_ls = sqrt(mag2_ls);
			t_sample nr_hs = ((a0Hs + (a1Hs * cs)) + (a2Hs * cos2));
			t_sample ni_hs = (-((a1Hs * sn) + (a2Hs * sin2)));
			t_sample dr_hs = ((((int)1) + (b1Hs * cs)) + (b2Hs * cos2));
			t_sample di_hs = (-((b1Hs * sn) + (b2Hs * sin2)));
			t_sample maxb_323 = ((dr_hs * dr_hs) + (di_hs * di_hs));
			t_sample mag2_hs = safediv(((nr_hs * nr_hs) + (ni_hs * ni_hs)), ((((t_sample)1e-12) < maxb_323) ? maxb_323 : ((t_sample)1e-12)));
			t_sample mag_hs = sqrt(mag2_hs);
			t_sample maxb_324 = (mag_ls * mag_hs);
			t_sample gPivot = safediv(((int)1), ((((t_sample)1e-09) < maxb_324) ? maxb_324 : ((t_sample)1e-09)));
			t_sample lTilt = (lTiltRaw * gPivot);
			t_sample rTilt = (rTiltRaw * gPivot);
			t_sample return_327;
			t_sample return_328;
			softclip_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_327, return_328);
			t_sample softL = return_327;
			t_sample softR = return_328;
			t_sample return_333;
			t_sample return_334;
			sigmoid_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_333, return_334);
			t_sample sigmL = return_333;
			t_sample sigmR = return_334;
			t_sample return_337;
			t_sample return_338;
			rectF_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_337, return_338);
			t_sample rectL = return_337;
			t_sample rectR = return_338;
			t_sample return_341;
			t_sample return_342;
			fuzzExp1_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_341, return_342);
			t_sample fuzz1L = return_341;
			t_sample fuzz1R = return_342;
			t_sample return_347;
			t_sample return_348;
			tangenteHiperbolica_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_347, return_348);
			t_sample tanhL = return_347;
			t_sample tanhR = return_348;
			t_sample return_353;
			t_sample return_354;
			rectH_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_353, return_354);
			t_sample recthL = return_353;
			t_sample recthR = return_354;
			t_sample return_355;
			t_sample return_356;
			arctangent_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_355, return_356);
			t_sample atanL = return_355;
			t_sample atanR = return_356;
			t_sample return_365;
			t_sample return_366;
			hardClip_d_d_d_d_d(lTilt, rTilt, drive, dc, ceiling, return_365, return_366);
			t_sample hardL = return_365;
			t_sample hardR = return_366;
			t_sample maxb_367 = (((int)1) - fabs((smoothedMode - ((int)0))));
			t_sample w0 = ((((int)0) < maxb_367) ? maxb_367 : ((int)0));
			t_sample maxb_368 = (((int)1) - fabs((smoothedMode - ((int)1))));
			t_sample w1 = ((((int)0) < maxb_368) ? maxb_368 : ((int)0));
			t_sample maxb_369 = (((int)1) - fabs((smoothedMode - ((int)2))));
			t_sample w2 = ((((int)0) < maxb_369) ? maxb_369 : ((int)0));
			t_sample maxb_370 = (((int)1) - fabs((smoothedMode - ((int)3))));
			t_sample w3 = ((((int)0) < maxb_370) ? maxb_370 : ((int)0));
			t_sample maxb_371 = (((int)1) - fabs((smoothedMode - ((int)4))));
			t_sample w4 = ((((int)0) < maxb_371) ? maxb_371 : ((int)0));
			t_sample maxb_372 = (((int)1) - fabs((smoothedMode - ((int)5))));
			t_sample w5 = ((((int)0) < maxb_372) ? maxb_372 : ((int)0));
			t_sample maxb_373 = (((int)1) - fabs((smoothedMode - ((int)6))));
			t_sample w6 = ((((int)0) < maxb_373) ? maxb_373 : ((int)0));
			t_sample maxb_374 = (((int)1) - fabs((smoothedMode - ((int)7))));
			t_sample w7 = ((((int)0) < maxb_374) ? maxb_374 : ((int)0));
			t_sample sumWeights = ((((((((w0 + w1) + w2) + w3) + w4) + w5) + w6) + w7) + ((t_sample)0.0001));
			t_sample w_2181 = safediv(w0, sumWeights);
			t_sample w_2182 = safediv(w1, sumWeights);
			t_sample w_2183 = safediv(w2, sumWeights);
			t_sample w_2184 = safediv(w3, sumWeights);
			t_sample w_2185 = safediv(w4, sumWeights);
			t_sample w_2186 = safediv(w5, sumWeights);
			t_sample w_2187 = safediv(w6, sumWeights);
			t_sample w_2188 = safediv(w7, sumWeights);
			t_sample distL = ((((((((softL * w_2181) + (sigmL * w_2182)) + (rectL * w_2183)) + (fuzz1L * w_2184)) + (tanhL * w_2185)) + (recthL * w_2186)) + (atanL * w_2187)) + (hardL * w_2188));
			t_sample distR = ((((((((softR * w_2181) + (sigmR * w_2182)) + (rectR * w_2183)) + (fuzz1R * w_2184)) + (tanhR * w_2185)) + (recthR * w_2186)) + (atanR * w_2187)) + (hardR * w_2188));
			t_sample processedL = __m_dcblock_375(distL);
			t_sample processedR = __m_dcblock_376(distR);
			t_sample return_377;
			t_sample return_378;
			bitCrusher_d_d_d(processedL, processedR, bits, return_377, return_378);
			t_sample bitL = return_377;
			t_sample bitR = return_378;
			t_sample bcL = __m_dcblock_379(bitL);
			t_sample bcR = __m_dcblock_380(bitR);
			t_sample mix_2210 = (processedL + (bitson * (bcL - processedL)));
			t_sample mix_2211 = (processedR + (bitson * (bcR - processedR)));
			t_sample maxb_381 = floor((m_hDownsample_70 + ((int)1)));
			t_sample deciFactor = ((((int)1) < maxb_381) ? maxb_381 : ((int)1));
			int enableNow = (downsampleOn > ((t_sample)0.5));
			int enableEdge = (enableNow > m_dsEnablePrev_57);
			m_dsEnablePrev_57 = enableNow;
			t_sample inc = safediv(((int)1), deciFactor);
			t_sample iffalse_382 = (m_dsPhase_59 + inc);
			m_dsPhase_59 = (enableEdge ? ((int)0) : iffalse_382);
			m_dsPhase_59 = (m_dsPhase_59 - floor(m_dsPhase_59));
			int dsEdgeWrap = (m_dsPhase_59 < m_dsTrigPrev_58);
			int dsEdge = (((enableEdge + dsEdgeWrap) + (deciFactor == ((int)1))) > ((t_sample)0.5));
			m_dsTrigPrev_58 = m_dsPhase_59;
			__m_latch_383 = ((dsEdge != 0) ? mix_2210 : __m_latch_383);
			t_sample dsHeldL = __m_latch_383;
			__m_latch_384 = ((dsEdge != 0) ? mix_2211 : __m_latch_384);
			t_sample dsHeldR = __m_latch_384;
			t_sample mix_2212 = (mix_2210 + (downsampleOn * (dsHeldL - mix_2210)));
			t_sample mix_2213 = (mix_2211 + (downsampleOn * (dsHeldR - mix_2211)));
			t_sample wetWithMakeupL = ((mix_2212 * outputMakeupLinear) + (bypassWhenActiveL * scSm));
			t_sample wetWithMakeupR = ((mix_2213 * outputMakeupLinear) + (bypassWhenActiveR * scSm));
			t_sample mix_2214 = (mix_2208 + (drywet * (wetWithMakeupL - mix_2208)));
			t_sample mix_2215 = (mix_2209 + (drywet * (wetWithMakeupR - mix_2209)));
			t_sample finalDcBlockedL = __m_dcblock_385(mix_2214);
			t_sample finalDcBlockedR = __m_dcblock_386(mix_2215);
			t_sample mix_2216 = (lIn + (bypass * (finalDcBlockedL - lIn)));
			t_sample mix_2217 = (rIn + (bypass * (finalDcBlockedR - rIn)));
			t_sample out1 = mix_2216;
			t_sample out4 = lTrimmed;
			t_sample out3 = ((int)0);
			t_sample out2 = mix_2217;
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
	inline void set_o_BAND(t_param _value) {
		m_o_BAND_281 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_n_DOWNSAMPLEON(t_param _value) {
		m_n_DOWNSAMPLEON_282 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_m_DOWNSAMPLE(t_param _value) {
		m_m_DOWNSAMPLE_283 = (_value < 0 ? 0 : (_value > 99 ? 99 : _value));
	};
	inline void set_l_OUTPUT(t_param _value) {
		m_l_OUTPUT_284 = (_value < -12 ? -12 : (_value > 12 ? 12 : _value));
	};
	inline void set_k_INPUT(t_param _value) {
		m_k_INPUT_285 = (_value < -12 ? -12 : (_value > 12 ? 12 : _value));
	};
	inline void set_l_SC(t_param _value) {
		m_l_SC_286 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_k_LPF(t_param _value) {
		m_k_LPF_287 = (_value < 1000 ? 1000 : (_value > 20000 ? 20000 : _value));
	};
	inline void set_j_HPF(t_param _value) {
		m_j_HPF_288 = (_value < 20 ? 20 : (_value > 1000 ? 1000 : _value));
	};
	inline void set_i_TILT(t_param _value) {
		m_i_TILT_289 = (_value < -6 ? -6 : (_value > 6 ? 6 : _value));
	};
	inline void set_h_BITSON(t_param _value) {
		m_h_BITSON_290 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_g_BITS(t_param _value) {
		m_g_BITS_291 = (_value < 3 ? 3 : (_value > 16 ? 16 : _value));
	};
	inline void set_f_BYPASS(t_param _value) {
		m_f_BYPASS_292 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_e_CEILING(t_param _value) {
		m_e_CEILING_293 = (_value < -20 ? -20 : (_value > 6 ? 6 : _value));
	};
	inline void set_d_MODE(t_param _value) {
		m_d_MODE_294 = (_value < 0 ? 0 : (_value > 7 ? 7 : _value));
	};
	inline void set_c_DC(t_param _value) {
		m_c_DC_295 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_b_DRIVE(t_param _value) {
		m_b_DRIVE_296 = (_value < 1 ? 1 : (_value > 50 ? 50 : _value));
	};
	inline void set_a_DRYWET(t_param _value) {
		m_a_DRYWET_297 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		int cond_325 = (fabs(lNorm) <= ((int)1));
		t_sample lOut = (cond_325 ? lCubic : lLimited);
		int cond_326 = (fabs(rNorm) <= ((int)1));
		t_sample rOut = (cond_326 ? rCubic : rLimited);
		out1 = (lOut * cell);
		out2 = (rOut * cell);
		
	};
	inline void sigmoid_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample factor = ((-((int)1)) * dr);
		t_sample l = ((((int)2) * safediv(((int)1), (((int)1) + exp((factor * lWithDC))))) - ((int)1));
		t_sample r = ((((int)2) * safediv(((int)1), (((int)1) + exp((factor * rWithDC))))) - ((int)1));
		t_sample v_329 = (l * cell);
		t_sample min_330 = (-cell);
		t_sample lOut = ((v_329 <= min_330) ? min_330 : ((v_329 >= cell) ? cell : v_329));
		t_sample v_331 = (r * cell);
		t_sample min_332 = (-cell);
		t_sample rOut = ((v_331 <= min_332) ? min_332 : ((v_331 >= cell) ? cell : v_331));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void rectF_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample l = ((((lWithDC > 0) ? 1 : ((lWithDC < 0) ? -1 : 0)) * fabs((lWithDC * dr))) * ((t_sample)0.707));
		t_sample r = ((((rWithDC > 0) ? 1 : ((rWithDC < 0) ? -1 : 0)) * fabs((rWithDC * dr))) * ((t_sample)0.707));
		t_sample min_335 = (-cell);
		t_sample lOut = ((l <= min_335) ? min_335 : ((l >= cell) ? cell : l));
		t_sample min_336 = (-cell);
		t_sample rOut = ((r <= min_336) ? min_336 : ((r >= cell) ? cell : r));
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
		t_sample min_339 = (-cell);
		t_sample lOut = ((l <= min_339) ? min_339 : ((l >= cell) ? cell : l));
		t_sample min_340 = (-cell);
		t_sample rOut = ((r <= min_340) ? min_340 : ((r >= cell) ? cell : r));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void tangenteHiperbolica_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lWithDC = (inl + (dc * ((t_sample)0.01)));
		t_sample rWithDC = (inr + (dc * ((t_sample)0.01)));
		t_sample v_343 = (lWithDC * dr);
		t_sample min_344 = (-cell);
		t_sample l = ((v_343 <= min_344) ? min_344 : ((v_343 >= cell) ? cell : v_343));
		t_sample v_345 = (rWithDC * dr);
		t_sample min_346 = (-cell);
		t_sample r = ((v_345 <= min_346) ? min_346 : ((v_345 >= cell) ? cell : v_345));
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
		t_sample v_349 = ((lPositive * dr) * ((t_sample)0.5));
		t_sample min_350 = (-cell);
		t_sample l = ((v_349 <= min_350) ? min_350 : ((v_349 >= cell) ? cell : v_349));
		t_sample v_351 = ((rPositive * dr) * ((t_sample)0.5));
		t_sample min_352 = (-cell);
		t_sample r = ((v_351 <= min_352) ? min_352 : ((v_351 >= cell) ? cell : v_351));
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
		int cond_357 = (lDriven > cell);
		int cond_358 = (lDriven < (-cell));
		t_sample iftrue_359 = (-cell);
		t_sample iffalse_360 = (cond_358 ? iftrue_359 : lDriven);
		t_sample l = (cond_357 ? cell : iffalse_360);
		int cond_361 = (rDriven > cell);
		int cond_362 = (rDriven < (-cell));
		t_sample iftrue_363 = (-cell);
		t_sample iffalse_364 = (cond_362 ? iftrue_363 : rDriven);
		t_sample r = (cond_361 ? cell : iffalse_364);
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
		case 0: *value = self->m_a_DRYWET_297; break;
		case 1: *value = self->m_b_DRIVE_296; break;
		case 2: *value = self->m_c_DC_295; break;
		case 3: *value = self->m_d_MODE_294; break;
		case 4: *value = self->m_e_CEILING_293; break;
		case 5: *value = self->m_f_BYPASS_292; break;
		case 6: *value = self->m_g_BITS_291; break;
		case 7: *value = self->m_h_BITSON_290; break;
		case 8: *value = self->m_i_TILT_289; break;
		case 9: *value = self->m_j_HPF_288; break;
		case 10: *value = self->m_k_INPUT_285; break;
		case 11: *value = self->m_k_LPF_287; break;
		case 12: *value = self->m_l_OUTPUT_284; break;
		case 13: *value = self->m_l_SC_286; break;
		case 14: *value = self->m_m_DOWNSAMPLE_283; break;
		case 15: *value = self->m_n_DOWNSAMPLEON_282; break;
		case 16: *value = self->m_o_BAND_281; break;
		
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
	// initialize parameter 0 ("m_a_DRYWET_297")
	pi = self->__commonstate.params + 0;
	pi->name = "a_DRYWET";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_a_DRYWET_297;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_b_DRIVE_296")
	pi = self->__commonstate.params + 1;
	pi->name = "b_DRIVE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_b_DRIVE_296;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 50;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_c_DC_295")
	pi = self->__commonstate.params + 2;
	pi->name = "c_DC";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_c_DC_295;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_d_MODE_294")
	pi = self->__commonstate.params + 3;
	pi->name = "d_MODE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d_MODE_294;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 7;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_e_CEILING_293")
	pi = self->__commonstate.params + 4;
	pi->name = "e_CEILING";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_e_CEILING_293;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -20;
	pi->outputmax = 6;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_f_BYPASS_292")
	pi = self->__commonstate.params + 5;
	pi->name = "f_BYPASS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_f_BYPASS_292;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_g_BITS_291")
	pi = self->__commonstate.params + 6;
	pi->name = "g_BITS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_g_BITS_291;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 3;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_h_BITSON_290")
	pi = self->__commonstate.params + 7;
	pi->name = "h_BITSON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_h_BITSON_290;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_i_TILT_289")
	pi = self->__commonstate.params + 8;
	pi->name = "i_TILT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_i_TILT_289;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -6;
	pi->outputmax = 6;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_j_HPF_288")
	pi = self->__commonstate.params + 9;
	pi->name = "j_HPF";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_j_HPF_288;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 20;
	pi->outputmax = 1000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_k_INPUT_285")
	pi = self->__commonstate.params + 10;
	pi->name = "k_INPUT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_k_INPUT_285;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -12;
	pi->outputmax = 12;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_k_LPF_287")
	pi = self->__commonstate.params + 11;
	pi->name = "k_LPF";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_k_LPF_287;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1000;
	pi->outputmax = 20000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_l_OUTPUT_284")
	pi = self->__commonstate.params + 12;
	pi->name = "l_OUTPUT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_l_OUTPUT_284;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -12;
	pi->outputmax = 12;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_l_SC_286")
	pi = self->__commonstate.params + 13;
	pi->name = "l_SC";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_l_SC_286;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_m_DOWNSAMPLE_283")
	pi = self->__commonstate.params + 14;
	pi->name = "m_DOWNSAMPLE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_m_DOWNSAMPLE_283;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_n_DOWNSAMPLEON_282")
	pi = self->__commonstate.params + 15;
	pi->name = "n_DOWNSAMPLEON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_n_DOWNSAMPLEON_282;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 16 ("m_o_BAND_281")
	pi = self->__commonstate.params + 16;
	pi->name = "o_BAND";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_o_BAND_281;
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

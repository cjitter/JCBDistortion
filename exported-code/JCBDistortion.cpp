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
[[maybe_unused]] static const int GENLIB_LOOPCOUNT_BAIL = 100000;

// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	DCBlock __m_dcblock_508;
	DCBlock __m_dcblock_512;
	DCBlock __m_dcblock_509;
	DCBlock __m_dcblock_513;
	DCBlock __m_dcblock_490;
	DCBlock __m_dcblock_491;
	int __exception;
	int vectorsize;
	t_sample m_R_ap_low_hp1_y_245;
	t_sample m_R_ap_low_hp2_x_244;
	t_sample m_R_ap_low_hp2_y_243;
	t_sample m_R_ap_low_hp1_y_246;
	t_sample m_R_ap_low_lp2_x_250;
	t_sample m_R_ap_low_lp2_y_248;
	t_sample m_R_ap_low_hp1_x_247;
	t_sample m_R_ap_low_hp2_y_242;
	t_sample m_R_ap_low_lp2_y_249;
	t_sample m_R_ap1_lp1_x_241;
	t_sample m_R_ap1_lp2_x_238;
	t_sample m_R_ap1_lp1_y_239;
	t_sample m_R_ap1_hp1_y_234;
	t_sample m_R_ap1_hp1_y_233;
	t_sample m_R_ap1_hp2_x_232;
	t_sample m_R_ap1_lp1_y_240;
	t_sample m_R_ap1_hp1_x_235;
	t_sample m_R_ap1_lp2_y_237;
	t_sample m_R_ap1_lp2_y_236;
	t_sample m_R_ap_low_lp1_y_251;
	t_sample m_R_ap_low_lp1_y_252;
	t_sample m_R_u2_x_256;
	t_sample m_R_u2_y_254;
	t_sample m_R_h2_x_268;
	t_sample m_R_h2_y_267;
	t_sample m_R_h2_y_266;
	t_sample m_R_m1_x_265;
	t_sample m_R_h1_y_269;
	t_sample m_R_h1_x_271;
	t_sample m_R_h1_y_270;
	t_sample m_R_l2_y_273;
	t_sample m_R_l2_y_272;
	t_sample m_R_ap_low_lp1_x_253;
	t_sample m_R_m1_y_264;
	t_sample m_R_m2_x_262;
	t_sample m_R_u1_y_257;
	t_sample m_R_ap1_hp2_y_231;
	t_sample m_R_u2_y_255;
	t_sample m_R_m1_y_263;
	t_sample m_R_u1_y_258;
	t_sample m_R_m2_y_260;
	t_sample m_R_u1_x_259;
	t_sample m_R_m2_y_261;
	t_sample m_R_ap1_hp2_y_230;
	t_sample m_R_ap2_lp1_y_227;
	t_sample m_R_ap2_lp1_y_228;
	t_sample m_m1_x_200;
	t_sample m_m1_y_199;
	t_sample m_m1_y_198;
	t_sample m_m2_x_197;
	t_sample m_m1_x_201;
	t_sample m_h2_y_203;
	t_sample m_h2_y_202;
	t_sample m_h2_x_205;
	t_sample m_h2_x_204;
	t_sample m_h1_y_206;
	t_sample m_m2_x_196;
	t_sample m_m2_y_194;
	t_sample m_u2_x_189;
	t_sample m_u2_x_188;
	t_sample m_u2_y_187;
	t_sample m_m2_y_195;
	t_sample m_u1_y_190;
	t_sample m_u1_x_192;
	t_sample m_u1_y_191;
	t_sample m_u1_x_193;
	t_sample m_R_ap2_lp1_x_229;
	t_sample m_h1_y_207;
	t_sample m_h1_x_209;
	t_sample m_R_ap2_hp1_x_223;
	t_sample m_R_ap2_hp1_y_222;
	t_sample m_R_ap2_hp1_y_221;
	t_sample m_R_ap2_hp2_x_220;
	t_sample m_R_ap2_lp2_y_224;
	t_sample m_R_ap2_lp2_x_226;
	t_sample m_R_ap2_lp2_y_225;
	t_sample m_R_l2_x_274;
	t_sample m_h1_x_208;
	t_sample m_R_ap2_hp2_y_219;
	t_sample m_l1_x_217;
	t_sample m_l2_x_212;
	t_sample m_l2_y_211;
	t_sample m_l2_y_210;
	t_sample m_R_ap2_hp2_y_218;
	t_sample m_l2_x_213;
	t_sample m_l1_y_215;
	t_sample m_l1_y_214;
	t_sample m_l1_x_216;
	t_sample m_R_l1_y_275;
	t_sample m_L_ap2_hp2_y_278;
	t_sample m_R_l1_x_277;
	t_sample m_L_l1_y_336;
	t_sample m_L_l1_y_335;
	t_sample m_L_l2_x_334;
	t_sample m_L_l2_y_333;
	t_sample m_L_l1_x_337;
	t_sample m_t_TONEQ_339;
	t_sample m_u_TONEPOS_338;
	t_sample m_q_TONEON_341;
	t_sample m_r_TONEFREQ_340;
	t_sample m_p_SAFELIMITON_342;
	t_sample m_L_l2_y_332;
	t_sample m_L_h1_y_330;
	t_sample m_L_m1_x_325;
	t_sample m_L_m1_y_324;
	t_sample m_L_m1_y_323;
	t_sample m_L_h1_x_331;
	t_sample m_L_h2_y_326;
	t_sample m_L_h2_x_328;
	t_sample m_L_h2_y_327;
	t_sample m_L_h1_y_329;
	t_sample m_L_m2_x_322;
	t_sample m_p_BANDSOLO_343;
	t_sample m_p_TILTPOS_345;
	t_sample m_e_CEILING_359;
	t_sample m_f_BYPASS_358;
	t_sample m_g_BITS_357;
	t_sample m_h_BITSON_356;
	t_sample m_d_MODE_360;
	t_sample m_b_DRIVE_362;
	t_sample m_c_DC_361;
	t_sample m_a_DRYWET_363;
	t_sample m_p_DISTON_344;
	t_sample m_i_TILT_355;
	t_sample m_j_HPF_353;
	t_sample m_m_DOWNSAMPLE_348;
	t_sample m_n_DOWNSAMPLEON_347;
	t_sample m_o_BAND_346;
	t_sample m_s_TILTON_354;
	t_sample m_l_OUTPUT_349;
	t_sample m_l_SC_351;
	t_sample m_k_INPUT_350;
	t_sample m_k_LPF_352;
	t_sample m_R_l1_y_276;
	t_sample m_L_m2_y_321;
	t_sample m_L_u1_x_319;
	t_sample m_L_ap1_hp2_y_291;
	t_sample m_L_ap1_hp2_y_290;
	t_sample m_L_ap2_lp1_x_289;
	t_sample m_L_ap2_lp1_y_288;
	t_sample m_L_ap1_hp2_x_292;
	t_sample m_L_ap1_hp1_y_294;
	t_sample m_L_ap1_hp1_y_293;
	t_sample m_L_ap1_lp2_y_296;
	t_sample m_L_ap1_hp1_x_295;
	t_sample m_L_ap1_lp2_y_297;
	t_sample m_L_ap2_lp1_y_287;
	t_sample m_L_ap2_lp2_y_285;
	t_sample m_L_ap2_hp2_x_280;
	t_sample m_L_ap2_hp2_y_279;
	t_sample m_u2_y_186;
	t_sample m_L_ap2_lp2_x_286;
	t_sample m_L_ap2_hp1_y_281;
	t_sample m_L_ap2_hp1_x_283;
	t_sample m_L_ap2_hp1_y_282;
	t_sample m_L_ap2_lp2_y_284;
	t_sample m_L_m2_y_320;
	t_sample m_L_ap1_lp2_x_298;
	t_sample m_L_ap1_lp1_y_300;
	t_sample m_L_u2_y_314;
	t_sample m_L_ap_low_lp1_x_313;
	t_sample m_L_ap_low_lp1_y_312;
	t_sample m_L_ap_low_lp1_y_311;
	t_sample m_L_u2_y_315;
	t_sample m_L_u1_y_317;
	t_sample m_L_u2_x_316;
	t_sample m_L_u1_y_318;
	t_sample m_L_ap1_lp1_y_299;
	t_sample m_L_ap_low_lp2_x_310;
	t_sample m_L_ap_low_lp2_y_308;
	t_sample m_L_ap_low_hp2_y_303;
	t_sample m_L_ap_low_hp2_y_302;
	t_sample m_L_ap1_lp1_x_301;
	t_sample m_L_ap_low_lp2_y_309;
	t_sample m_L_ap_low_hp2_x_304;
	t_sample m_L_ap_low_hp1_y_306;
	t_sample m_L_ap_low_hp1_y_305;
	t_sample m_L_ap_low_hp1_x_307;
	t_sample m_ap_low_lp1_x_185;
	t_sample m_ap_low_lp1_x_184;
	t_sample m_ap_low_lp1_y_183;
	t_sample m_R_ap_low_lp1_x_61;
	t_sample m_L_ap_low_lp2_x_60;
	t_sample m_R_ap_low_lp2_x_59;
	t_sample m_L_ap_low_hp1_x_58;
	t_sample m_L_ap_low_lp1_x_62;
	t_sample m_L_u2_x_64;
	t_sample m_R_u2_x_63;
	t_sample m_L_u1_x_66;
	t_sample m_R_u1_x_65;
	t_sample m_R_m2_x_67;
	t_sample m_R_ap_low_hp1_x_57;
	t_sample m_R_ap_low_hp2_x_55;
	t_sample m_R_ap1_hp1_x_49;
	t_sample m_L_ap1_hp2_x_48;
	t_sample m_R_ap1_hp2_x_47;
	t_sample m_L_ap_low_hp2_x_56;
	t_sample m_L_ap1_hp1_x_50;
	t_sample m_L_ap1_lp2_x_52;
	t_sample m_R_ap1_lp2_x_51;
	t_sample m_L_ap1_lp1_x_54;
	t_sample m_R_ap1_lp1_x_53;
	t_sample m_L_ap2_lp1_x_46;
	t_sample m_L_m2_x_68;
	t_sample m_L_m1_x_70;
	t_sample m_postTiltHsL_84;
	t_sample m_postTiltHsL_83;
	t_sample m_postTiltHsR_82;
	t_sample m_postTiltHsR_81;
	t_sample m_postTiltHsL_85;
	t_sample m_postTiltLsR_87;
	t_sample m_postTiltHsL_86;
	t_sample m_postTiltLsR_89;
	t_sample m_postTiltLsR_88;
	t_sample m_R_m1_x_69;
	t_sample m_postTiltHsR_80;
	t_sample m_L_l1_x_78;
	t_sample m_R_h1_x_73;
	t_sample m_L_h2_x_72;
	t_sample m_R_h2_x_71;
	t_sample m_postTiltHsR_79;
	t_sample m_L_h1_x_74;
	t_sample m_L_l2_x_76;
	t_sample m_R_l2_x_75;
	t_sample m_R_l1_x_77;
	t_sample m_postTiltLsR_90;
	t_sample m_R_ap2_lp1_x_45;
	t_sample m_R_ap2_lp2_x_43;
	t_sample m_preToneBL_y_14;
	t_sample m_preToneBL_y_13;
	t_sample m_preToneBR_x_12;
	t_sample m_preToneBR_x_11;
	t_sample m_preToneBL_x_15;
	t_sample m_preToneAR_y_17;
	t_sample m_preToneBL_x_16;
	t_sample m_preToneAR_x_19;
	t_sample m_preToneAR_y_18;
	t_sample m_preToneAR_x_20;
	t_sample m_preToneBR_y_10;
	t_sample m_toneApL_x_8;
	t_sample m_toneApR_y_2;
	t_sample m_toneApR_y_1;
	t_sample samplerate;
	t_sample m_preToneBR_y_9;
	t_sample m_toneApR_x_3;
	t_sample m_toneApL_y_5;
	t_sample m_toneApR_x_4;
	t_sample m_toneApL_x_7;
	t_sample m_toneApL_y_6;
	t_sample m_L_ap2_lp2_x_44;
	t_sample m_preToneAL_y_21;
	t_sample m_preToneAL_x_23;
	t_sample m_hBandSolo_37;
	t_sample m_hSafeLimitOn_36;
	t_sample m_hToneOn_35;
	t_sample m_hToneFreq_34;
	t_sample m_hDistOn_38;
	t_sample m_L_ap2_hp2_x_40;
	t_sample m_R_ap2_hp2_x_39;
	t_sample m_L_ap2_hp1_x_42;
	t_sample m_R_ap2_hp1_x_41;
	t_sample m_preToneAL_y_22;
	t_sample m_toneL_x_33;
	t_sample m_toneL_y_31;
	t_sample m_toneR_y_26;
	t_sample m_hToneQ_25;
	t_sample m_preToneAL_x_24;
	t_sample m_toneL_x_32;
	t_sample m_toneR_y_27;
	t_sample m_toneR_x_29;
	t_sample m_toneR_x_28;
	t_sample m_toneL_y_30;
	t_sample __m_latch_516;
	t_sample m_postTiltLsL_91;
	t_sample m_postTiltLsL_93;
	t_sample m_ap1_hp2_y_154;
	t_sample m_ap2_lp1_x_153;
	t_sample m_ap2_lp1_x_152;
	t_sample m_ap2_lp1_y_151;
	t_sample m_ap1_hp2_y_155;
	t_sample m_ap1_hp2_x_157;
	t_sample m_ap1_hp2_x_156;
	t_sample m_ap1_hp1_y_159;
	t_sample m_ap1_hp1_y_158;
	t_sample m_ap1_hp1_x_160;
	t_sample m_ap2_lp1_y_150;
	t_sample m_ap2_lp2_x_148;
	t_sample m_ap2_hp1_y_142;
	t_sample m_ap2_hp2_x_141;
	t_sample m_ap2_hp2_x_140;
	t_sample m_ap2_lp2_x_149;
	t_sample m_ap2_hp1_y_143;
	t_sample m_ap2_hp1_x_145;
	t_sample m_ap2_hp1_x_144;
	t_sample m_ap2_lp2_y_147;
	t_sample m_ap2_lp2_y_146;
	t_sample m_ap2_hp2_y_139;
	t_sample m_ap1_hp1_x_161;
	t_sample m_ap1_lp2_y_163;
	t_sample m_ap_low_hp1_x_177;
	t_sample m_ap_low_hp1_x_176;
	t_sample m_ap_low_hp1_y_175;
	t_sample m_ap_low_hp1_y_174;
	t_sample m_ap_low_lp2_y_178;
	t_sample m_ap_low_lp2_x_180;
	t_sample m_ap_low_lp2_y_179;
	t_sample m_ap_low_lp1_y_182;
	t_sample m_ap_low_lp2_x_181;
	t_sample m_ap1_lp2_y_162;
	t_sample m_ap_low_hp2_x_173;
	t_sample m_ap_low_hp2_y_171;
	t_sample m_ap1_lp1_y_166;
	t_sample m_ap1_lp2_x_165;
	t_sample m_ap1_lp2_x_164;
	t_sample m_ap_low_hp2_x_172;
	t_sample m_ap1_lp1_y_167;
	t_sample m_ap1_lp1_x_169;
	t_sample m_ap1_lp1_x_168;
	t_sample m_ap_low_hp2_y_170;
	t_sample m_postTiltLsL_92;
	t_sample m_ap2_hp2_y_138;
	t_sample m_hDrive_136;
	t_sample m_tiltLsR_107;
	t_sample m_tiltLsR_106;
	t_sample m_tiltLsR_105;
	t_sample m_tiltHsL_104;
	t_sample m_tiltLsR_108;
	t_sample m_tiltLsL_110;
	t_sample m_tiltLsL_109;
	t_sample m_tiltLsL_112;
	t_sample m_tiltLsL_111;
	t_sample m_dsEnablePrev_113;
	t_sample m_tiltHsL_103;
	t_sample m_tiltHsL_101;
	t_sample m_hTiltPos_96;
	t_sample m_hTonePos_95;
	t_sample m_postTiltLsL_94;
	t_sample m_tiltHsL_102;
	t_sample m_tiltHsR_97;
	t_sample m_tiltHsR_99;
	t_sample m_tiltHsR_98;
	t_sample m_tiltHsR_100;
	t_sample m_hBand_137;
	t_sample m_dsTrigPrev_114;
	t_sample m_dsPhasor_116;
	t_sample m_hTiltOn_130;
	t_sample m_hInput_129;
	t_sample m_hOutput_128;
	t_sample m_hMode_127;
	t_sample m_hTilt_131;
	t_sample m_hBits_133;
	t_sample m_hBitson_132;
	t_sample m_hDc_135;
	t_sample m_hDrywet_134;
	t_sample m_dsPhase_115;
	t_sample m_hDownsample_126;
	t_sample m_hBypass_124;
	t_sample m_hpfFreqHistory_119;
	t_sample m_lpfFreqHistory_118;
	t_sample m_scEnableHistory_117;
	t_sample m_hDownsampleOn_125;
	t_sample m_lpfR_z_120;
	t_sample m_hpfR_z_122;
	t_sample m_lpfL_z_121;
	t_sample m_hpfL_z_123;
	t_sample __m_latch_517;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_toneApR_y_1 = ((int)0);
		m_toneApR_y_2 = ((int)0);
		m_toneApR_x_3 = ((int)0);
		m_toneApR_x_4 = ((int)0);
		m_toneApL_y_5 = ((int)0);
		m_toneApL_y_6 = ((int)0);
		m_toneApL_x_7 = ((int)0);
		m_toneApL_x_8 = ((int)0);
		m_preToneBR_y_9 = ((int)0);
		m_preToneBR_y_10 = ((int)0);
		m_preToneBR_x_11 = ((int)0);
		m_preToneBR_x_12 = ((int)0);
		m_preToneBL_y_13 = ((int)0);
		m_preToneBL_y_14 = ((int)0);
		m_preToneBL_x_15 = ((int)0);
		m_preToneBL_x_16 = ((int)0);
		m_preToneAR_y_17 = ((int)0);
		m_preToneAR_y_18 = ((int)0);
		m_preToneAR_x_19 = ((int)0);
		m_preToneAR_x_20 = ((int)0);
		m_preToneAL_y_21 = ((int)0);
		m_preToneAL_y_22 = ((int)0);
		m_preToneAL_x_23 = ((int)0);
		m_preToneAL_x_24 = ((int)0);
		m_hToneQ_25 = ((t_sample)0.70710678118655);
		m_toneR_y_26 = ((int)0);
		m_toneR_y_27 = ((int)0);
		m_toneR_x_28 = ((int)0);
		m_toneR_x_29 = ((int)0);
		m_toneL_y_30 = ((int)0);
		m_toneL_y_31 = ((int)0);
		m_toneL_x_32 = ((int)0);
		m_toneL_x_33 = ((int)0);
		m_hToneFreq_34 = ((int)12000);
		m_hToneOn_35 = ((int)0);
		m_hSafeLimitOn_36 = ((int)0);
		m_hBandSolo_37 = ((int)0);
		m_hDistOn_38 = ((int)1);
		m_R_ap2_hp2_x_39 = ((int)0);
		m_L_ap2_hp2_x_40 = ((int)0);
		m_R_ap2_hp1_x_41 = ((int)0);
		m_L_ap2_hp1_x_42 = ((int)0);
		m_R_ap2_lp2_x_43 = ((int)0);
		m_L_ap2_lp2_x_44 = ((int)0);
		m_R_ap2_lp1_x_45 = ((int)0);
		m_L_ap2_lp1_x_46 = ((int)0);
		m_R_ap1_hp2_x_47 = ((int)0);
		m_L_ap1_hp2_x_48 = ((int)0);
		m_R_ap1_hp1_x_49 = ((int)0);
		m_L_ap1_hp1_x_50 = ((int)0);
		m_R_ap1_lp2_x_51 = ((int)0);
		m_L_ap1_lp2_x_52 = ((int)0);
		m_R_ap1_lp1_x_53 = ((int)0);
		m_L_ap1_lp1_x_54 = ((int)0);
		m_R_ap_low_hp2_x_55 = ((int)0);
		m_L_ap_low_hp2_x_56 = ((int)0);
		m_R_ap_low_hp1_x_57 = ((int)0);
		m_L_ap_low_hp1_x_58 = ((int)0);
		m_R_ap_low_lp2_x_59 = ((int)0);
		m_L_ap_low_lp2_x_60 = ((int)0);
		m_R_ap_low_lp1_x_61 = ((int)0);
		m_L_ap_low_lp1_x_62 = ((int)0);
		m_R_u2_x_63 = ((int)0);
		m_L_u2_x_64 = ((int)0);
		m_R_u1_x_65 = ((int)0);
		m_L_u1_x_66 = ((int)0);
		m_R_m2_x_67 = ((int)0);
		m_L_m2_x_68 = ((int)0);
		m_R_m1_x_69 = ((int)0);
		m_L_m1_x_70 = ((int)0);
		m_R_h2_x_71 = ((int)0);
		m_L_h2_x_72 = ((int)0);
		m_R_h1_x_73 = ((int)0);
		m_L_h1_x_74 = ((int)0);
		m_R_l2_x_75 = ((int)0);
		m_L_l2_x_76 = ((int)0);
		m_R_l1_x_77 = ((int)0);
		m_L_l1_x_78 = ((int)0);
		m_postTiltHsR_79 = ((int)0);
		m_postTiltHsR_80 = ((int)0);
		m_postTiltHsR_81 = ((int)0);
		m_postTiltHsR_82 = ((int)0);
		m_postTiltHsL_83 = ((int)0);
		m_postTiltHsL_84 = ((int)0);
		m_postTiltHsL_85 = ((int)0);
		m_postTiltHsL_86 = ((int)0);
		m_postTiltLsR_87 = ((int)0);
		m_postTiltLsR_88 = ((int)0);
		m_postTiltLsR_89 = ((int)0);
		m_postTiltLsR_90 = ((int)0);
		m_postTiltLsL_91 = ((int)0);
		m_postTiltLsL_92 = ((int)0);
		m_postTiltLsL_93 = ((int)0);
		m_postTiltLsL_94 = ((int)0);
		m_hTonePos_95 = ((int)1);
		m_hTiltPos_96 = ((int)0);
		m_tiltHsR_97 = ((int)0);
		m_tiltHsR_98 = ((int)0);
		m_tiltHsR_99 = ((int)0);
		m_tiltHsR_100 = ((int)0);
		m_tiltHsL_101 = ((int)0);
		m_tiltHsL_102 = ((int)0);
		m_tiltHsL_103 = ((int)0);
		m_tiltHsL_104 = ((int)0);
		m_tiltLsR_105 = ((int)0);
		m_tiltLsR_106 = ((int)0);
		m_tiltLsR_107 = ((int)0);
		m_tiltLsR_108 = ((int)0);
		m_tiltLsL_109 = ((int)0);
		m_tiltLsL_110 = ((int)0);
		m_tiltLsL_111 = ((int)0);
		m_tiltLsL_112 = ((int)0);
		m_dsEnablePrev_113 = ((int)0);
		m_dsTrigPrev_114 = ((int)0);
		m_dsPhase_115 = ((int)0);
		m_dsPhasor_116 = ((int)0);
		m_scEnableHistory_117 = ((int)0);
		m_lpfFreqHistory_118 = ((int)0);
		m_hpfFreqHistory_119 = ((int)0);
		m_lpfR_z_120 = ((int)0);
		m_lpfL_z_121 = ((int)0);
		m_hpfR_z_122 = ((int)0);
		m_hpfL_z_123 = ((int)0);
		m_hBypass_124 = ((int)0);
		m_hDownsampleOn_125 = ((int)0);
		m_hDownsample_126 = ((int)0);
		m_hMode_127 = ((int)0);
		m_hOutput_128 = ((int)0);
		m_hInput_129 = ((int)0);
		m_hTiltOn_130 = ((int)1);
		m_hTilt_131 = ((int)0);
		m_hBitson_132 = ((int)0);
		m_hBits_133 = ((int)0);
		m_hDrywet_134 = ((int)0);
		m_hDc_135 = ((int)0);
		m_hDrive_136 = ((int)0);
		m_hBand_137 = ((int)1);
		m_ap2_hp2_y_138 = ((int)0);
		m_ap2_hp2_y_139 = ((int)0);
		m_ap2_hp2_x_140 = ((int)0);
		m_ap2_hp2_x_141 = ((int)0);
		m_ap2_hp1_y_142 = ((int)0);
		m_ap2_hp1_y_143 = ((int)0);
		m_ap2_hp1_x_144 = ((int)0);
		m_ap2_hp1_x_145 = ((int)0);
		m_ap2_lp2_y_146 = ((int)0);
		m_ap2_lp2_y_147 = ((int)0);
		m_ap2_lp2_x_148 = ((int)0);
		m_ap2_lp2_x_149 = ((int)0);
		m_ap2_lp1_y_150 = ((int)0);
		m_ap2_lp1_y_151 = ((int)0);
		m_ap2_lp1_x_152 = ((int)0);
		m_ap2_lp1_x_153 = ((int)0);
		m_ap1_hp2_y_154 = ((int)0);
		m_ap1_hp2_y_155 = ((int)0);
		m_ap1_hp2_x_156 = ((int)0);
		m_ap1_hp2_x_157 = ((int)0);
		m_ap1_hp1_y_158 = ((int)0);
		m_ap1_hp1_y_159 = ((int)0);
		m_ap1_hp1_x_160 = ((int)0);
		m_ap1_hp1_x_161 = ((int)0);
		m_ap1_lp2_y_162 = ((int)0);
		m_ap1_lp2_y_163 = ((int)0);
		m_ap1_lp2_x_164 = ((int)0);
		m_ap1_lp2_x_165 = ((int)0);
		m_ap1_lp1_y_166 = ((int)0);
		m_ap1_lp1_y_167 = ((int)0);
		m_ap1_lp1_x_168 = ((int)0);
		m_ap1_lp1_x_169 = ((int)0);
		m_ap_low_hp2_y_170 = ((int)0);
		m_ap_low_hp2_y_171 = ((int)0);
		m_ap_low_hp2_x_172 = ((int)0);
		m_ap_low_hp2_x_173 = ((int)0);
		m_ap_low_hp1_y_174 = ((int)0);
		m_ap_low_hp1_y_175 = ((int)0);
		m_ap_low_hp1_x_176 = ((int)0);
		m_ap_low_hp1_x_177 = ((int)0);
		m_ap_low_lp2_y_178 = ((int)0);
		m_ap_low_lp2_y_179 = ((int)0);
		m_ap_low_lp2_x_180 = ((int)0);
		m_ap_low_lp2_x_181 = ((int)0);
		m_ap_low_lp1_y_182 = ((int)0);
		m_ap_low_lp1_y_183 = ((int)0);
		m_ap_low_lp1_x_184 = ((int)0);
		m_ap_low_lp1_x_185 = ((int)0);
		m_u2_y_186 = ((int)0);
		m_u2_y_187 = ((int)0);
		m_u2_x_188 = ((int)0);
		m_u2_x_189 = ((int)0);
		m_u1_y_190 = ((int)0);
		m_u1_y_191 = ((int)0);
		m_u1_x_192 = ((int)0);
		m_u1_x_193 = ((int)0);
		m_m2_y_194 = ((int)0);
		m_m2_y_195 = ((int)0);
		m_m2_x_196 = ((int)0);
		m_m2_x_197 = ((int)0);
		m_m1_y_198 = ((int)0);
		m_m1_y_199 = ((int)0);
		m_m1_x_200 = ((int)0);
		m_m1_x_201 = ((int)0);
		m_h2_y_202 = ((int)0);
		m_h2_y_203 = ((int)0);
		m_h2_x_204 = ((int)0);
		m_h2_x_205 = ((int)0);
		m_h1_y_206 = ((int)0);
		m_h1_y_207 = ((int)0);
		m_h1_x_208 = ((int)0);
		m_h1_x_209 = ((int)0);
		m_l2_y_210 = ((int)0);
		m_l2_y_211 = ((int)0);
		m_l2_x_212 = ((int)0);
		m_l2_x_213 = ((int)0);
		m_l1_y_214 = ((int)0);
		m_l1_y_215 = ((int)0);
		m_l1_x_216 = ((int)0);
		m_l1_x_217 = ((int)0);
		m_R_ap2_hp2_y_218 = ((int)0);
		m_R_ap2_hp2_y_219 = ((int)0);
		m_R_ap2_hp2_x_220 = ((int)0);
		m_R_ap2_hp1_y_221 = ((int)0);
		m_R_ap2_hp1_y_222 = ((int)0);
		m_R_ap2_hp1_x_223 = ((int)0);
		m_R_ap2_lp2_y_224 = ((int)0);
		m_R_ap2_lp2_y_225 = ((int)0);
		m_R_ap2_lp2_x_226 = ((int)0);
		m_R_ap2_lp1_y_227 = ((int)0);
		m_R_ap2_lp1_y_228 = ((int)0);
		m_R_ap2_lp1_x_229 = ((int)0);
		m_R_ap1_hp2_y_230 = ((int)0);
		m_R_ap1_hp2_y_231 = ((int)0);
		m_R_ap1_hp2_x_232 = ((int)0);
		m_R_ap1_hp1_y_233 = ((int)0);
		m_R_ap1_hp1_y_234 = ((int)0);
		m_R_ap1_hp1_x_235 = ((int)0);
		m_R_ap1_lp2_y_236 = ((int)0);
		m_R_ap1_lp2_y_237 = ((int)0);
		m_R_ap1_lp2_x_238 = ((int)0);
		m_R_ap1_lp1_y_239 = ((int)0);
		m_R_ap1_lp1_y_240 = ((int)0);
		m_R_ap1_lp1_x_241 = ((int)0);
		m_R_ap_low_hp2_y_242 = ((int)0);
		m_R_ap_low_hp2_y_243 = ((int)0);
		m_R_ap_low_hp2_x_244 = ((int)0);
		m_R_ap_low_hp1_y_245 = ((int)0);
		m_R_ap_low_hp1_y_246 = ((int)0);
		m_R_ap_low_hp1_x_247 = ((int)0);
		m_R_ap_low_lp2_y_248 = ((int)0);
		m_R_ap_low_lp2_y_249 = ((int)0);
		m_R_ap_low_lp2_x_250 = ((int)0);
		m_R_ap_low_lp1_y_251 = ((int)0);
		m_R_ap_low_lp1_y_252 = ((int)0);
		m_R_ap_low_lp1_x_253 = ((int)0);
		m_R_u2_y_254 = ((int)0);
		m_R_u2_y_255 = ((int)0);
		m_R_u2_x_256 = ((int)0);
		m_R_u1_y_257 = ((int)0);
		m_R_u1_y_258 = ((int)0);
		m_R_u1_x_259 = ((int)0);
		m_R_m2_y_260 = ((int)0);
		m_R_m2_y_261 = ((int)0);
		m_R_m2_x_262 = ((int)0);
		m_R_m1_y_263 = ((int)0);
		m_R_m1_y_264 = ((int)0);
		m_R_m1_x_265 = ((int)0);
		m_R_h2_y_266 = ((int)0);
		m_R_h2_y_267 = ((int)0);
		m_R_h2_x_268 = ((int)0);
		m_R_h1_y_269 = ((int)0);
		m_R_h1_y_270 = ((int)0);
		m_R_h1_x_271 = ((int)0);
		m_R_l2_y_272 = ((int)0);
		m_R_l2_y_273 = ((int)0);
		m_R_l2_x_274 = ((int)0);
		m_R_l1_y_275 = ((int)0);
		m_R_l1_y_276 = ((int)0);
		m_R_l1_x_277 = ((int)0);
		m_L_ap2_hp2_y_278 = ((int)0);
		m_L_ap2_hp2_y_279 = ((int)0);
		m_L_ap2_hp2_x_280 = ((int)0);
		m_L_ap2_hp1_y_281 = ((int)0);
		m_L_ap2_hp1_y_282 = ((int)0);
		m_L_ap2_hp1_x_283 = ((int)0);
		m_L_ap2_lp2_y_284 = ((int)0);
		m_L_ap2_lp2_y_285 = ((int)0);
		m_L_ap2_lp2_x_286 = ((int)0);
		m_L_ap2_lp1_y_287 = ((int)0);
		m_L_ap2_lp1_y_288 = ((int)0);
		m_L_ap2_lp1_x_289 = ((int)0);
		m_L_ap1_hp2_y_290 = ((int)0);
		m_L_ap1_hp2_y_291 = ((int)0);
		m_L_ap1_hp2_x_292 = ((int)0);
		m_L_ap1_hp1_y_293 = ((int)0);
		m_L_ap1_hp1_y_294 = ((int)0);
		m_L_ap1_hp1_x_295 = ((int)0);
		m_L_ap1_lp2_y_296 = ((int)0);
		m_L_ap1_lp2_y_297 = ((int)0);
		m_L_ap1_lp2_x_298 = ((int)0);
		m_L_ap1_lp1_y_299 = ((int)0);
		m_L_ap1_lp1_y_300 = ((int)0);
		m_L_ap1_lp1_x_301 = ((int)0);
		m_L_ap_low_hp2_y_302 = ((int)0);
		m_L_ap_low_hp2_y_303 = ((int)0);
		m_L_ap_low_hp2_x_304 = ((int)0);
		m_L_ap_low_hp1_y_305 = ((int)0);
		m_L_ap_low_hp1_y_306 = ((int)0);
		m_L_ap_low_hp1_x_307 = ((int)0);
		m_L_ap_low_lp2_y_308 = ((int)0);
		m_L_ap_low_lp2_y_309 = ((int)0);
		m_L_ap_low_lp2_x_310 = ((int)0);
		m_L_ap_low_lp1_y_311 = ((int)0);
		m_L_ap_low_lp1_y_312 = ((int)0);
		m_L_ap_low_lp1_x_313 = ((int)0);
		m_L_u2_y_314 = ((int)0);
		m_L_u2_y_315 = ((int)0);
		m_L_u2_x_316 = ((int)0);
		m_L_u1_y_317 = ((int)0);
		m_L_u1_y_318 = ((int)0);
		m_L_u1_x_319 = ((int)0);
		m_L_m2_y_320 = ((int)0);
		m_L_m2_y_321 = ((int)0);
		m_L_m2_x_322 = ((int)0);
		m_L_m1_y_323 = ((int)0);
		m_L_m1_y_324 = ((int)0);
		m_L_m1_x_325 = ((int)0);
		m_L_h2_y_326 = ((int)0);
		m_L_h2_y_327 = ((int)0);
		m_L_h2_x_328 = ((int)0);
		m_L_h1_y_329 = ((int)0);
		m_L_h1_y_330 = ((int)0);
		m_L_h1_x_331 = ((int)0);
		m_L_l2_y_332 = ((int)0);
		m_L_l2_y_333 = ((int)0);
		m_L_l2_x_334 = ((int)0);
		m_L_l1_y_335 = ((int)0);
		m_L_l1_y_336 = ((int)0);
		m_L_l1_x_337 = ((int)0);
		m_u_TONEPOS_338 = 1;
		m_t_TONEQ_339 = 0.70710678118655;
		m_r_TONEFREQ_340 = 20000;
		m_q_TONEON_341 = 0;
		m_p_SAFELIMITON_342 = 0;
		m_p_BANDSOLO_343 = 0;
		m_p_DISTON_344 = 1;
		m_p_TILTPOS_345 = 0;
		m_o_BAND_346 = 1;
		m_n_DOWNSAMPLEON_347 = 0;
		m_m_DOWNSAMPLE_348 = 0;
		m_l_OUTPUT_349 = 0;
		m_k_INPUT_350 = 0;
		m_l_SC_351 = 0;
		m_k_LPF_352 = 5000;
		m_j_HPF_353 = 250;
		m_s_TILTON_354 = 1;
		m_i_TILT_355 = 0;
		m_h_BITSON_356 = 0;
		m_g_BITS_357 = 16;
		m_f_BYPASS_358 = 0;
		m_e_CEILING_359 = 0;
		m_d_MODE_360 = 0;
		m_c_DC_361 = 0;
		m_b_DRIVE_362 = 1;
		m_a_DRYWET_363 = 1;
		__m_dcblock_490.reset();
		__m_dcblock_491.reset();
		__m_dcblock_508.reset();
		__m_dcblock_509.reset();
		__m_dcblock_512.reset();
		__m_dcblock_513.reset();
		__m_latch_516 = 0;
		__m_latch_517 = 0;
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
		t_sample ceiling = dbtoa(m_e_CEILING_359);
		int L_sr = samplerate;
		t_sample minb_364 = (((t_sample)0.45) * L_sr);
		t_sample minb_366 = (((t_sample)0.45) * L_sr);
		int R_sr = samplerate;
		t_sample minb_369 = (((t_sample)0.45) * R_sr);
		t_sample minb_371 = (((t_sample)0.45) * R_sr);
		int L_sr_2992 = samplerate;
		t_sample minb_379 = (((t_sample)0.45) * L_sr_2992);
		t_sample minb_381 = (((t_sample)0.45) * L_sr_2992);
		int R_sr_3034 = samplerate;
		t_sample minb_384 = (((t_sample)0.45) * R_sr_3034);
		t_sample minb_386 = (((t_sample)0.45) * R_sr_3034);
		t_sample omega = safediv(((t_sample)6283.1853071796), samplerate);
		t_sample sn = sin(omega);
		t_sample cs = cos(omega);
		t_sample cosw = cs;
		t_sample sinw = sn;
		t_sample cos2 = ((cs * cs) - (sn * sn));
		t_sample sin2 = ((((int)2) * sn) * cs);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample lIn = in1;
			t_sample rIn = in2;
			m_hDrive_136 = ((m_hDrive_136 * ((t_sample)0.999)) + (m_b_DRIVE_362 * ((t_sample)0.001)));
			t_sample drive = m_hDrive_136;
			m_hDc_135 = ((m_hDc_135 * ((t_sample)0.999)) + (m_c_DC_361 * ((t_sample)0.001)));
			t_sample dc = m_hDc_135;
			m_hDrywet_134 = ((m_hDrywet_134 * ((t_sample)0.999)) + (m_a_DRYWET_363 * ((t_sample)0.001)));
			t_sample drywet = m_hDrywet_134;
			m_hBits_133 = ((m_hBits_133 * ((t_sample)0.999)) + (m_g_BITS_357 * ((t_sample)0.001)));
			t_sample bits = m_hBits_133;
			m_hBitson_132 = ((m_hBitson_132 * ((t_sample)0.999)) + (m_h_BITSON_356 * ((t_sample)0.001)));
			t_sample bitson = m_hBitson_132;
			m_hTilt_131 = ((m_hTilt_131 * ((t_sample)0.999)) + (m_i_TILT_355 * ((t_sample)0.001)));
			t_sample tiltDb = m_hTilt_131;
			m_hTiltOn_130 = ((m_hTiltOn_130 * ((t_sample)0.99)) + (m_s_TILTON_354 * ((t_sample)0.01)));
			t_sample tiltOn = ((m_hTiltOn_130 <= ((int)0)) ? ((int)0) : ((m_hTiltOn_130 >= ((int)1)) ? ((int)1) : m_hTiltOn_130));
			m_hInput_129 = ((m_hInput_129 * ((t_sample)0.999)) + (m_k_INPUT_350 * ((t_sample)0.001)));
			t_sample inputTrimDb = m_hInput_129;
			m_hOutput_128 = ((m_hOutput_128 * ((t_sample)0.999)) + (m_l_OUTPUT_349 * ((t_sample)0.001)));
			t_sample outputMakeupDb = m_hOutput_128;
			m_hBand_137 = ((m_hBand_137 * ((t_sample)0.999)) + (m_o_BAND_346 * ((t_sample)0.001)));
			t_sample smoothedBand = m_hBand_137;
			m_hMode_127 = ((m_hMode_127 * ((t_sample)0.99)) + (m_d_MODE_360 * ((t_sample)0.01)));
			t_sample smoothedMode = m_hMode_127;
			m_hDownsample_126 = ((m_hDownsample_126 * ((t_sample)0.999)) + (m_m_DOWNSAMPLE_348 * ((t_sample)0.001)));
			m_hDownsampleOn_125 = ((m_hDownsampleOn_125 * ((t_sample)0.9)) + (m_n_DOWNSAMPLEON_347 * ((t_sample)0.1)));
			t_sample downsampleOn = m_hDownsampleOn_125;
			m_hBypass_124 = ((m_hBypass_124 * ((t_sample)0.999)) + ((((int)1) - m_f_BYPASS_358) * ((t_sample)0.001)));
			t_sample bypass = m_hBypass_124;
			t_sample smoothHpfFreq = ((m_hpfFreqHistory_119 * ((t_sample)0.999)) + (m_j_HPF_353 * ((t_sample)0.001)));
			m_hpfFreqHistory_119 = fixdenorm(smoothHpfFreq);
			t_sample smoothLpfFreq = ((m_lpfFreqHistory_118 * ((t_sample)0.999)) + (m_k_LPF_352 * ((t_sample)0.001)));
			m_lpfFreqHistory_118 = fixdenorm(smoothLpfFreq);
			t_sample smoothScEnable = ((m_scEnableHistory_117 * ((t_sample)0.999)) + (m_l_SC_351 * ((t_sample)0.001)));
			m_scEnableHistory_117 = fixdenorm(smoothScEnable);
			m_hTiltPos_96 = ((m_hTiltPos_96 * ((t_sample)0.999)) + (m_p_TILTPOS_345 * ((t_sample)0.001)));
			t_sample wPost = ((m_hTiltPos_96 <= ((int)0)) ? ((int)0) : ((m_hTiltPos_96 >= ((int)1)) ? ((int)1) : m_hTiltPos_96));
			m_hDistOn_38 = ((m_hDistOn_38 * ((t_sample)0.999)) + (m_p_DISTON_344 * ((t_sample)0.001)));
			t_sample wDist = ((m_hDistOn_38 <= ((int)0)) ? ((int)0) : ((m_hDistOn_38 >= ((int)1)) ? ((int)1) : m_hDistOn_38));
			m_hBandSolo_37 = ((m_hBandSolo_37 * ((t_sample)0.999)) + (m_p_BANDSOLO_343 * ((t_sample)0.001)));
			m_hSafeLimitOn_36 = ((m_hSafeLimitOn_36 * ((t_sample)0.999)) + (m_p_SAFELIMITON_342 * ((t_sample)0.001)));
			t_sample safeOn = ((m_hSafeLimitOn_36 <= ((int)0)) ? ((int)0) : ((m_hSafeLimitOn_36 >= ((int)1)) ? ((int)1) : m_hSafeLimitOn_36));
			m_hToneOn_35 = ((m_hToneOn_35 * ((t_sample)0.99)) + (m_q_TONEON_341 * ((t_sample)0.01)));
			t_sample toneOn = ((m_hToneOn_35 <= ((int)0)) ? ((int)0) : ((m_hToneOn_35 >= ((int)1)) ? ((int)1) : m_hToneOn_35));
			m_hToneFreq_34 = ((m_hToneFreq_34 * ((t_sample)0.999)) + (m_r_TONEFREQ_340 * ((t_sample)0.001)));
			t_sample toneFreq = m_hToneFreq_34;
			m_hToneQ_25 = ((m_hToneQ_25 * ((t_sample)0.999)) + (m_t_TONEQ_339 * ((t_sample)0.001)));
			t_sample tq = ((m_hToneQ_25 <= ((t_sample)0.125)) ? ((t_sample)0.125) : ((m_hToneQ_25 >= ((int)16)) ? ((int)16) : m_hToneQ_25));
			m_hTonePos_95 = ((m_hTonePos_95 * ((t_sample)0.999)) + (m_u_TONEPOS_338 * ((t_sample)0.001)));
			t_sample wTonePost = ((m_hTonePos_95 <= ((int)0)) ? ((int)0) : ((m_hTonePos_95 >= ((int)1)) ? ((int)1) : m_hTonePos_95));
			t_sample wTonePre = (((int)1) - wTonePost);
			t_sample omegaT = safediv((toneFreq * ((t_sample)6.2831853071796)), samplerate);
			t_sample sinT = sin(omegaT);
			t_sample cosT = cos(omegaT);
			t_sample alphaT = safediv(sinT, (((int)2) * tq));
			t_sample b0T = ((((int)1) - cosT) * ((t_sample)0.5));
			t_sample b1T = (((int)1) - cosT);
			t_sample b2T = ((((int)1) - cosT) * ((t_sample)0.5));
			t_sample a0T = (((int)1) + alphaT);
			t_sample a1T = (((int)-2) * cosT);
			t_sample a2T = (((int)1) - alphaT);
			t_sample inv_a0T = safediv(((int)1), a0T);
			t_sample t_a0 = (b0T * inv_a0T);
			t_sample t_a1 = (b1T * inv_a0T);
			t_sample t_a2 = (b2T * inv_a0T);
			t_sample t_b1 = (a1T * inv_a0T);
			t_sample t_b2 = (a2T * inv_a0T);
			t_sample ap_b0 = t_b2;
			t_sample ap_b1 = t_b1;
			t_sample ap_a1 = t_b1;
			t_sample ap_a2 = t_b2;
			t_sample inputTrimLinear = dbtoa(inputTrimDb);
			t_sample outputMakeupLinear = dbtoa(outputMakeupDb);
			t_sample lTrimmed = (lIn * inputTrimLinear);
			t_sample rTrimmed = (rIn * inputTrimLinear);
			t_sample scSm = smoothScEnable;
			t_sample L_loF = smoothHpfFreq;
			t_sample L_hiF = smoothLpfFreq;
			t_sample L_x = lTrimmed;
			t_sample maxb_365 = ((minb_364 < L_loF) ? minb_364 : L_loF);
			t_sample L_loF_2981 = ((((int)10) < maxb_365) ? maxb_365 : ((int)10));
			t_sample maxb_367 = ((minb_366 < L_hiF) ? minb_366 : L_hiF);
			t_sample L_hiFr = ((((int)10) < maxb_367) ? maxb_367 : ((int)10));
			t_sample maxb_368 = (L_loF_2981 + ((int)1));
			t_sample L_hiF_2982 = ((L_hiFr < maxb_368) ? maxb_368 : L_hiFr);
			t_sample L_w0_lo = safediv((((t_sample)6.2831853071796) * L_loF_2981), L_sr);
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
			t_sample L_w0_hi = safediv((((t_sample)6.2831853071796) * L_hiF_2982), L_sr);
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
			t_sample L_l1_x1p = fixdenorm(m_L_l1_x_78);
			t_sample L_l1_x2p = fixdenorm(m_L_l1_x_337);
			t_sample L_l1_y1p = fixdenorm(m_L_l1_y_336);
			t_sample L_l1_y2p = fixdenorm(m_L_l1_y_335);
			t_sample L_low_s1 = (((((L_lp_b0_l * L_x) + (L_lp_b1_l * L_l1_x1p)) + (L_lp_b2_l * L_l1_x2p)) - (L_lp_a1_l * L_l1_y1p)) - (L_lp_a2_l * L_l1_y2p));
			m_L_l1_x_337 = L_l1_x1p;
			m_L_l1_x_78 = L_x;
			m_L_l1_y_335 = L_l1_y1p;
			m_L_l1_y_336 = L_low_s1;
			t_sample L_l2_x1p = fixdenorm(m_L_l2_x_76);
			t_sample L_l2_x2p = fixdenorm(m_L_l2_x_334);
			t_sample L_l2_y1p = fixdenorm(m_L_l2_y_333);
			t_sample L_l2_y2p = fixdenorm(m_L_l2_y_332);
			t_sample L_low_raw = (((((L_lp_b0_l * L_low_s1) + (L_lp_b1_l * L_l2_x1p)) + (L_lp_b2_l * L_l2_x2p)) - (L_lp_a1_l * L_l2_y1p)) - (L_lp_a2_l * L_l2_y2p));
			m_L_l2_x_334 = L_l2_x1p;
			m_L_l2_x_76 = L_low_s1;
			m_L_l2_y_332 = L_l2_y1p;
			m_L_l2_y_333 = L_low_raw;
			t_sample L_h1_x1p = fixdenorm(m_L_h1_x_74);
			t_sample L_h1_x2p = fixdenorm(m_L_h1_x_331);
			t_sample L_h1_y1p = fixdenorm(m_L_h1_y_330);
			t_sample L_h1_y2p = fixdenorm(m_L_h1_y_329);
			t_sample L_rest_s1 = (((((L_hp_b0_l * L_x) + (L_hp_b1_l * L_h1_x1p)) + (L_hp_b2_l * L_h1_x2p)) - (L_hp_a1_l * L_h1_y1p)) - (L_hp_a2_l * L_h1_y2p));
			m_L_h1_x_331 = L_h1_x1p;
			m_L_h1_x_74 = L_x;
			m_L_h1_y_329 = L_h1_y1p;
			m_L_h1_y_330 = L_rest_s1;
			t_sample L_h2_x1p = fixdenorm(m_L_h2_x_72);
			t_sample L_h2_x2p = fixdenorm(m_L_h2_x_328);
			t_sample L_h2_y1p = fixdenorm(m_L_h2_y_327);
			t_sample L_h2_y2p = fixdenorm(m_L_h2_y_326);
			t_sample L_rest = (((((L_hp_b0_l * L_rest_s1) + (L_hp_b1_l * L_h2_x1p)) + (L_hp_b2_l * L_h2_x2p)) - (L_hp_a1_l * L_h2_y1p)) - (L_hp_a2_l * L_h2_y2p));
			m_L_h2_x_328 = L_h2_x1p;
			m_L_h2_x_72 = L_rest_s1;
			m_L_h2_y_326 = L_h2_y1p;
			m_L_h2_y_327 = L_rest;
			t_sample L_ap_low_lp1_x1p = fixdenorm(m_L_ap_low_lp1_x_62);
			t_sample L_ap_low_lp1_x2p = fixdenorm(m_L_ap_low_lp1_x_313);
			t_sample L_ap_low_lp1_y1p = fixdenorm(m_L_ap_low_lp1_y_312);
			t_sample L_ap_low_lp1_y2p = fixdenorm(m_L_ap_low_lp1_y_311);
			t_sample L_ap_low_lp_s1 = (((((L_lp_b0_h * L_low_raw) + (L_lp_b1_h * L_ap_low_lp1_x1p)) + (L_lp_b2_h * L_ap_low_lp1_x2p)) - (L_lp_a1_h * L_ap_low_lp1_y1p)) - (L_lp_a2_h * L_ap_low_lp1_y2p));
			m_L_ap_low_lp1_x_313 = L_ap_low_lp1_x1p;
			m_L_ap_low_lp1_x_62 = L_low_raw;
			m_L_ap_low_lp1_y_311 = L_ap_low_lp1_y1p;
			m_L_ap_low_lp1_y_312 = L_ap_low_lp_s1;
			t_sample L_ap_low_lp2_x1p = fixdenorm(m_L_ap_low_lp2_x_60);
			t_sample L_ap_low_lp2_x2p = fixdenorm(m_L_ap_low_lp2_x_310);
			t_sample L_ap_low_lp2_y1p = fixdenorm(m_L_ap_low_lp2_y_309);
			t_sample L_ap_low_lp2_y2p = fixdenorm(m_L_ap_low_lp2_y_308);
			t_sample L_ap_low_lp = (((((L_lp_b0_h * L_ap_low_lp_s1) + (L_lp_b1_h * L_ap_low_lp2_x1p)) + (L_lp_b2_h * L_ap_low_lp2_x2p)) - (L_lp_a1_h * L_ap_low_lp2_y1p)) - (L_lp_a2_h * L_ap_low_lp2_y2p));
			m_L_ap_low_lp2_x_310 = L_ap_low_lp2_x1p;
			m_L_ap_low_lp2_x_60 = L_ap_low_lp_s1;
			m_L_ap_low_lp2_y_308 = L_ap_low_lp2_y1p;
			m_L_ap_low_lp2_y_309 = L_ap_low_lp;
			t_sample L_ap_low_hp1_x1p = fixdenorm(m_L_ap_low_hp1_x_58);
			t_sample L_ap_low_hp1_x2p = fixdenorm(m_L_ap_low_hp1_x_307);
			t_sample L_ap_low_hp1_y1p = fixdenorm(m_L_ap_low_hp1_y_306);
			t_sample L_ap_low_hp1_y2p = fixdenorm(m_L_ap_low_hp1_y_305);
			t_sample L_ap_low_hp_s1 = (((((L_hp_b0_h * L_low_raw) + (L_hp_b1_h * L_ap_low_hp1_x1p)) + (L_hp_b2_h * L_ap_low_hp1_x2p)) - (L_hp_a1_h * L_ap_low_hp1_y1p)) - (L_hp_a2_h * L_ap_low_hp1_y2p));
			m_L_ap_low_hp1_x_307 = L_ap_low_hp1_x1p;
			m_L_ap_low_hp1_x_58 = L_low_raw;
			m_L_ap_low_hp1_y_305 = L_ap_low_hp1_y1p;
			m_L_ap_low_hp1_y_306 = L_ap_low_hp_s1;
			t_sample L_ap_low_hp2_x1p = fixdenorm(m_L_ap_low_hp2_x_56);
			t_sample L_ap_low_hp2_x2p = fixdenorm(m_L_ap_low_hp2_x_304);
			t_sample L_ap_low_hp2_y1p = fixdenorm(m_L_ap_low_hp2_y_303);
			t_sample L_ap_low_hp2_y2p = fixdenorm(m_L_ap_low_hp2_y_302);
			t_sample L_ap_low_hp = (((((L_hp_b0_h * L_ap_low_hp_s1) + (L_hp_b1_h * L_ap_low_hp2_x1p)) + (L_hp_b2_h * L_ap_low_hp2_x2p)) - (L_hp_a1_h * L_ap_low_hp2_y1p)) - (L_hp_a2_h * L_ap_low_hp2_y2p));
			m_L_ap_low_hp2_x_304 = L_ap_low_hp2_x1p;
			m_L_ap_low_hp2_x_56 = L_ap_low_hp_s1;
			m_L_ap_low_hp2_y_302 = L_ap_low_hp2_y1p;
			m_L_ap_low_hp2_y_303 = L_ap_low_hp;
			t_sample L_low = (L_ap_low_lp + L_ap_low_hp);
			t_sample L_m1_x1p = fixdenorm(m_L_m1_x_70);
			t_sample L_m1_x2p = fixdenorm(m_L_m1_x_325);
			t_sample L_m1_y1p = fixdenorm(m_L_m1_y_324);
			t_sample L_m1_y2p = fixdenorm(m_L_m1_y_323);
			t_sample L_mid_s1 = (((((L_lp_b0_h * L_rest) + (L_lp_b1_h * L_m1_x1p)) + (L_lp_b2_h * L_m1_x2p)) - (L_lp_a1_h * L_m1_y1p)) - (L_lp_a2_h * L_m1_y2p));
			m_L_m1_x_325 = L_m1_x1p;
			m_L_m1_x_70 = L_rest;
			m_L_m1_y_323 = L_m1_y1p;
			m_L_m1_y_324 = L_mid_s1;
			t_sample L_m2_x1p = fixdenorm(m_L_m2_x_68);
			t_sample L_m2_x2p = fixdenorm(m_L_m2_x_322);
			t_sample L_m2_y1p = fixdenorm(m_L_m2_y_321);
			t_sample L_m2_y2p = fixdenorm(m_L_m2_y_320);
			t_sample L_mid = (((((L_lp_b0_h * L_mid_s1) + (L_lp_b1_h * L_m2_x1p)) + (L_lp_b2_h * L_m2_x2p)) - (L_lp_a1_h * L_m2_y1p)) - (L_lp_a2_h * L_m2_y2p));
			m_L_m2_x_322 = L_m2_x1p;
			m_L_m2_x_68 = L_mid_s1;
			m_L_m2_y_320 = L_m2_y1p;
			m_L_m2_y_321 = L_mid;
			t_sample L_u1_x1p = fixdenorm(m_L_u1_x_66);
			t_sample L_u1_x2p = fixdenorm(m_L_u1_x_319);
			t_sample L_u1_y1p = fixdenorm(m_L_u1_y_318);
			t_sample L_u1_y2p = fixdenorm(m_L_u1_y_317);
			t_sample L_high_s1 = (((((L_hp_b0_h * L_rest) + (L_hp_b1_h * L_u1_x1p)) + (L_hp_b2_h * L_u1_x2p)) - (L_hp_a1_h * L_u1_y1p)) - (L_hp_a2_h * L_u1_y2p));
			m_L_u1_x_319 = L_u1_x1p;
			m_L_u1_x_66 = L_rest;
			m_L_u1_y_317 = L_u1_y1p;
			m_L_u1_y_318 = L_high_s1;
			t_sample L_u2_x1p = fixdenorm(m_L_u2_x_64);
			t_sample L_u2_x2p = fixdenorm(m_L_u2_x_316);
			t_sample L_u2_y1p = fixdenorm(m_L_u2_y_315);
			t_sample L_u2_y2p = fixdenorm(m_L_u2_y_314);
			t_sample L_high = (((((L_hp_b0_h * L_high_s1) + (L_hp_b1_h * L_u2_x1p)) + (L_hp_b2_h * L_u2_x2p)) - (L_hp_a1_h * L_u2_y1p)) - (L_hp_a2_h * L_u2_y2p));
			m_L_u2_x_316 = L_u2_x1p;
			m_L_u2_x_64 = L_high_s1;
			m_L_u2_y_314 = L_u2_y1p;
			m_L_u2_y_315 = L_high;
			t_sample lowL = L_low;
			t_sample midL = L_mid;
			t_sample highL = L_high;
			t_sample R_loF = smoothHpfFreq;
			t_sample R_hiF = smoothLpfFreq;
			t_sample R_x = rTrimmed;
			t_sample maxb_370 = ((minb_369 < R_loF) ? minb_369 : R_loF);
			t_sample R_loF_2983 = ((((int)10) < maxb_370) ? maxb_370 : ((int)10));
			t_sample maxb_372 = ((minb_371 < R_hiF) ? minb_371 : R_hiF);
			t_sample R_hiFr = ((((int)10) < maxb_372) ? maxb_372 : ((int)10));
			t_sample maxb_373 = (R_loF_2983 + ((int)1));
			t_sample R_hiF_2984 = ((R_hiFr < maxb_373) ? maxb_373 : R_hiFr);
			t_sample R_w0_lo = safediv((((t_sample)6.2831853071796) * R_loF_2983), R_sr);
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
			t_sample R_w0_hi = safediv((((t_sample)6.2831853071796) * R_hiF_2984), R_sr);
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
			t_sample R_l1_x1p = fixdenorm(m_R_l1_x_77);
			t_sample R_l1_x2p = fixdenorm(m_R_l1_x_277);
			t_sample R_l1_y1p = fixdenorm(m_R_l1_y_276);
			t_sample R_l1_y2p = fixdenorm(m_R_l1_y_275);
			t_sample R_low_s1 = (((((R_lp_b0_l * R_x) + (R_lp_b1_l * R_l1_x1p)) + (R_lp_b2_l * R_l1_x2p)) - (R_lp_a1_l * R_l1_y1p)) - (R_lp_a2_l * R_l1_y2p));
			m_R_l1_x_277 = R_l1_x1p;
			m_R_l1_x_77 = R_x;
			m_R_l1_y_275 = R_l1_y1p;
			m_R_l1_y_276 = R_low_s1;
			t_sample R_l2_x1p = fixdenorm(m_R_l2_x_75);
			t_sample R_l2_x2p = fixdenorm(m_R_l2_x_274);
			t_sample R_l2_y1p = fixdenorm(m_R_l2_y_273);
			t_sample R_l2_y2p = fixdenorm(m_R_l2_y_272);
			t_sample R_low_raw = (((((R_lp_b0_l * R_low_s1) + (R_lp_b1_l * R_l2_x1p)) + (R_lp_b2_l * R_l2_x2p)) - (R_lp_a1_l * R_l2_y1p)) - (R_lp_a2_l * R_l2_y2p));
			m_R_l2_x_274 = R_l2_x1p;
			m_R_l2_x_75 = R_low_s1;
			m_R_l2_y_272 = R_l2_y1p;
			m_R_l2_y_273 = R_low_raw;
			t_sample R_h1_x1p = fixdenorm(m_R_h1_x_73);
			t_sample R_h1_x2p = fixdenorm(m_R_h1_x_271);
			t_sample R_h1_y1p = fixdenorm(m_R_h1_y_270);
			t_sample R_h1_y2p = fixdenorm(m_R_h1_y_269);
			t_sample R_rest_s1 = (((((R_hp_b0_l * R_x) + (R_hp_b1_l * R_h1_x1p)) + (R_hp_b2_l * R_h1_x2p)) - (R_hp_a1_l * R_h1_y1p)) - (R_hp_a2_l * R_h1_y2p));
			m_R_h1_x_271 = R_h1_x1p;
			m_R_h1_x_73 = R_x;
			m_R_h1_y_269 = R_h1_y1p;
			m_R_h1_y_270 = R_rest_s1;
			t_sample R_h2_x1p = fixdenorm(m_R_h2_x_71);
			t_sample R_h2_x2p = fixdenorm(m_R_h2_x_268);
			t_sample R_h2_y1p = fixdenorm(m_R_h2_y_267);
			t_sample R_h2_y2p = fixdenorm(m_R_h2_y_266);
			t_sample R_rest = (((((R_hp_b0_l * R_rest_s1) + (R_hp_b1_l * R_h2_x1p)) + (R_hp_b2_l * R_h2_x2p)) - (R_hp_a1_l * R_h2_y1p)) - (R_hp_a2_l * R_h2_y2p));
			m_R_h2_x_268 = R_h2_x1p;
			m_R_h2_x_71 = R_rest_s1;
			m_R_h2_y_266 = R_h2_y1p;
			m_R_h2_y_267 = R_rest;
			t_sample R_ap_low_lp1_x1p = fixdenorm(m_R_ap_low_lp1_x_61);
			t_sample R_ap_low_lp1_x2p = fixdenorm(m_R_ap_low_lp1_x_253);
			t_sample R_ap_low_lp1_y1p = fixdenorm(m_R_ap_low_lp1_y_252);
			t_sample R_ap_low_lp1_y2p = fixdenorm(m_R_ap_low_lp1_y_251);
			t_sample R_ap_low_lp_s1 = (((((R_lp_b0_h * R_low_raw) + (R_lp_b1_h * R_ap_low_lp1_x1p)) + (R_lp_b2_h * R_ap_low_lp1_x2p)) - (R_lp_a1_h * R_ap_low_lp1_y1p)) - (R_lp_a2_h * R_ap_low_lp1_y2p));
			m_R_ap_low_lp1_x_253 = R_ap_low_lp1_x1p;
			m_R_ap_low_lp1_x_61 = R_low_raw;
			m_R_ap_low_lp1_y_251 = R_ap_low_lp1_y1p;
			m_R_ap_low_lp1_y_252 = R_ap_low_lp_s1;
			t_sample R_ap_low_lp2_x1p = fixdenorm(m_R_ap_low_lp2_x_59);
			t_sample R_ap_low_lp2_x2p = fixdenorm(m_R_ap_low_lp2_x_250);
			t_sample R_ap_low_lp2_y1p = fixdenorm(m_R_ap_low_lp2_y_249);
			t_sample R_ap_low_lp2_y2p = fixdenorm(m_R_ap_low_lp2_y_248);
			t_sample R_ap_low_lp = (((((R_lp_b0_h * R_ap_low_lp_s1) + (R_lp_b1_h * R_ap_low_lp2_x1p)) + (R_lp_b2_h * R_ap_low_lp2_x2p)) - (R_lp_a1_h * R_ap_low_lp2_y1p)) - (R_lp_a2_h * R_ap_low_lp2_y2p));
			m_R_ap_low_lp2_x_250 = R_ap_low_lp2_x1p;
			m_R_ap_low_lp2_x_59 = R_ap_low_lp_s1;
			m_R_ap_low_lp2_y_248 = R_ap_low_lp2_y1p;
			m_R_ap_low_lp2_y_249 = R_ap_low_lp;
			t_sample R_ap_low_hp1_x1p = fixdenorm(m_R_ap_low_hp1_x_57);
			t_sample R_ap_low_hp1_x2p = fixdenorm(m_R_ap_low_hp1_x_247);
			t_sample R_ap_low_hp1_y1p = fixdenorm(m_R_ap_low_hp1_y_246);
			t_sample R_ap_low_hp1_y2p = fixdenorm(m_R_ap_low_hp1_y_245);
			t_sample R_ap_low_hp_s1 = (((((R_hp_b0_h * R_low_raw) + (R_hp_b1_h * R_ap_low_hp1_x1p)) + (R_hp_b2_h * R_ap_low_hp1_x2p)) - (R_hp_a1_h * R_ap_low_hp1_y1p)) - (R_hp_a2_h * R_ap_low_hp1_y2p));
			m_R_ap_low_hp1_x_247 = R_ap_low_hp1_x1p;
			m_R_ap_low_hp1_x_57 = R_low_raw;
			m_R_ap_low_hp1_y_245 = R_ap_low_hp1_y1p;
			m_R_ap_low_hp1_y_246 = R_ap_low_hp_s1;
			t_sample R_ap_low_hp2_x1p = fixdenorm(m_R_ap_low_hp2_x_55);
			t_sample R_ap_low_hp2_x2p = fixdenorm(m_R_ap_low_hp2_x_244);
			t_sample R_ap_low_hp2_y1p = fixdenorm(m_R_ap_low_hp2_y_243);
			t_sample R_ap_low_hp2_y2p = fixdenorm(m_R_ap_low_hp2_y_242);
			t_sample R_ap_low_hp = (((((R_hp_b0_h * R_ap_low_hp_s1) + (R_hp_b1_h * R_ap_low_hp2_x1p)) + (R_hp_b2_h * R_ap_low_hp2_x2p)) - (R_hp_a1_h * R_ap_low_hp2_y1p)) - (R_hp_a2_h * R_ap_low_hp2_y2p));
			m_R_ap_low_hp2_x_244 = R_ap_low_hp2_x1p;
			m_R_ap_low_hp2_x_55 = R_ap_low_hp_s1;
			m_R_ap_low_hp2_y_242 = R_ap_low_hp2_y1p;
			m_R_ap_low_hp2_y_243 = R_ap_low_hp;
			t_sample R_low = (R_ap_low_lp + R_ap_low_hp);
			t_sample R_m1_x1p = fixdenorm(m_R_m1_x_69);
			t_sample R_m1_x2p = fixdenorm(m_R_m1_x_265);
			t_sample R_m1_y1p = fixdenorm(m_R_m1_y_264);
			t_sample R_m1_y2p = fixdenorm(m_R_m1_y_263);
			t_sample R_mid_s1 = (((((R_lp_b0_h * R_rest) + (R_lp_b1_h * R_m1_x1p)) + (R_lp_b2_h * R_m1_x2p)) - (R_lp_a1_h * R_m1_y1p)) - (R_lp_a2_h * R_m1_y2p));
			m_R_m1_x_265 = R_m1_x1p;
			m_R_m1_x_69 = R_rest;
			m_R_m1_y_263 = R_m1_y1p;
			m_R_m1_y_264 = R_mid_s1;
			t_sample R_m2_x1p = fixdenorm(m_R_m2_x_67);
			t_sample R_m2_x2p = fixdenorm(m_R_m2_x_262);
			t_sample R_m2_y1p = fixdenorm(m_R_m2_y_261);
			t_sample R_m2_y2p = fixdenorm(m_R_m2_y_260);
			t_sample R_mid = (((((R_lp_b0_h * R_mid_s1) + (R_lp_b1_h * R_m2_x1p)) + (R_lp_b2_h * R_m2_x2p)) - (R_lp_a1_h * R_m2_y1p)) - (R_lp_a2_h * R_m2_y2p));
			m_R_m2_x_262 = R_m2_x1p;
			m_R_m2_x_67 = R_mid_s1;
			m_R_m2_y_260 = R_m2_y1p;
			m_R_m2_y_261 = R_mid;
			t_sample R_u1_x1p = fixdenorm(m_R_u1_x_65);
			t_sample R_u1_x2p = fixdenorm(m_R_u1_x_259);
			t_sample R_u1_y1p = fixdenorm(m_R_u1_y_258);
			t_sample R_u1_y2p = fixdenorm(m_R_u1_y_257);
			t_sample R_high_s1 = (((((R_hp_b0_h * R_rest) + (R_hp_b1_h * R_u1_x1p)) + (R_hp_b2_h * R_u1_x2p)) - (R_hp_a1_h * R_u1_y1p)) - (R_hp_a2_h * R_u1_y2p));
			m_R_u1_x_259 = R_u1_x1p;
			m_R_u1_x_65 = R_rest;
			m_R_u1_y_257 = R_u1_y1p;
			m_R_u1_y_258 = R_high_s1;
			t_sample R_u2_x1p = fixdenorm(m_R_u2_x_63);
			t_sample R_u2_x2p = fixdenorm(m_R_u2_x_256);
			t_sample R_u2_y1p = fixdenorm(m_R_u2_y_255);
			t_sample R_u2_y2p = fixdenorm(m_R_u2_y_254);
			t_sample R_high = (((((R_hp_b0_h * R_high_s1) + (R_hp_b1_h * R_u2_x1p)) + (R_hp_b2_h * R_u2_x2p)) - (R_hp_a1_h * R_u2_y1p)) - (R_hp_a2_h * R_u2_y2p));
			m_R_u2_x_256 = R_u2_x1p;
			m_R_u2_x_63 = R_high_s1;
			m_R_u2_y_254 = R_u2_y1p;
			m_R_u2_y_255 = R_high;
			t_sample lowR = R_low;
			t_sample midR = R_mid;
			t_sample highR = R_high;
			t_sample maxb_374 = (((int)1) - fabs((smoothedBand - ((int)0))));
			t_sample wLow = ((((int)0) < maxb_374) ? maxb_374 : ((int)0));
			t_sample maxb_375 = (((int)1) - fabs((smoothedBand - ((int)1))));
			t_sample wMid = ((((int)0) < maxb_375) ? maxb_375 : ((int)0));
			t_sample maxb_376 = (((int)1) - fabs((smoothedBand - ((int)2))));
			t_sample wHigh = ((((int)0) < maxb_376) ? maxb_376 : ((int)0));
			t_sample maxb_377 = ((wLow + wMid) + wHigh);
			t_sample wSum = ((((t_sample)1e-09) < maxb_377) ? maxb_377 : ((t_sample)1e-09));
			t_sample wLow_2985 = safediv(wLow, wSum);
			t_sample wMid_2986 = safediv(wMid, wSum);
			t_sample wHigh_2987 = safediv(wHigh, wSum);
			t_sample preBandL = (((wLow_2985 * lowL) + (wMid_2986 * midL)) + (wHigh_2987 * highL));
			t_sample preBandR = (((wLow_2985 * lowR) + (wMid_2986 * midR)) + (wHigh_2987 * highR));
			t_sample sumBandsL = ((lowL + midL) + highL);
			t_sample sumBandsR = ((lowR + midR) + highR);
			t_sample v_378 = (m_hBandSolo_37 * scSm);
			t_sample soloAmt = ((v_378 <= ((int)0)) ? ((int)0) : ((v_378 >= ((int)1)) ? ((int)1) : v_378));
			t_sample bypassWhenActiveL = ((sumBandsL - preBandL) * (((int)1) - soloAmt));
			t_sample bypassWhenActiveR = ((sumBandsR - preBandR) * (((int)1) - soloAmt));
			t_sample mix_3165 = (lTrimmed + (scSm * (preBandL - lTrimmed)));
			t_sample preDistInL = mix_3165;
			t_sample mix_3166 = (rTrimmed + (scSm * (preBandR - rTrimmed)));
			t_sample preDistInR = mix_3166;
			t_sample L_loF_2988 = smoothHpfFreq;
			t_sample L_hiF_2989 = smoothLpfFreq;
			t_sample L_x_2990 = lIn;
			t_sample maxb_380 = ((minb_379 < L_loF_2988) ? minb_379 : L_loF_2988);
			t_sample L_loF_2993 = ((((int)10) < maxb_380) ? maxb_380 : ((int)10));
			t_sample maxb_382 = ((minb_381 < L_hiF_2989) ? minb_381 : L_hiF_2989);
			t_sample L_hiFr_2994 = ((((int)10) < maxb_382) ? maxb_382 : ((int)10));
			t_sample maxb_383 = (L_loF_2993 + ((int)1));
			t_sample L_hiF_2995 = ((L_hiFr_2994 < maxb_383) ? maxb_383 : L_hiFr_2994);
			t_sample L_w0_lo_2996 = safediv((((t_sample)6.2831853071796) * L_loF_2993), L_sr_2992);
			t_sample L_cos_lo_2997 = cos(L_w0_lo_2996);
			t_sample L_sin_lo_2998 = sin(L_w0_lo_2996);
			t_sample L_alpha_lo_2999 = (L_sin_lo_2998 * ((t_sample)0.70710678118655));
			t_sample L_a0_lo_3000 = (((int)1) + L_alpha_lo_2999);
			t_sample L_a1_lo_3001 = (((int)-2) * L_cos_lo_2997);
			t_sample L_a2_lo_3002 = (((int)1) - L_alpha_lo_2999);
			t_sample L_lp_b0_l_3003 = safediv(((((int)1) - L_cos_lo_2997) * ((t_sample)0.5)), L_a0_lo_3000);
			t_sample L_lp_b1_l_3004 = safediv((((int)1) - L_cos_lo_2997), L_a0_lo_3000);
			t_sample L_lp_b2_l_3005 = L_lp_b0_l_3003;
			t_sample L_lp_a1_l_3006 = safediv(L_a1_lo_3001, L_a0_lo_3000);
			t_sample L_lp_a2_l_3007 = safediv(L_a2_lo_3002, L_a0_lo_3000);
			t_sample L_hp_b0_l_3008 = safediv(((((int)1) + L_cos_lo_2997) * ((t_sample)0.5)), L_a0_lo_3000);
			t_sample L_hp_b1_l_3009 = safediv((-(((int)1) + L_cos_lo_2997)), L_a0_lo_3000);
			t_sample L_hp_b2_l_3010 = L_hp_b0_l_3008;
			t_sample L_hp_a1_l_3011 = L_lp_a1_l_3006;
			t_sample L_hp_a2_l_3012 = L_lp_a2_l_3007;
			t_sample L_w0_hi_3013 = safediv((((t_sample)6.2831853071796) * L_hiF_2995), L_sr_2992);
			t_sample L_cos_hi_3014 = cos(L_w0_hi_3013);
			t_sample L_sin_hi_3015 = sin(L_w0_hi_3013);
			t_sample L_alpha_hi_3016 = (L_sin_hi_3015 * ((t_sample)0.70710678118655));
			t_sample L_a0_hi_3017 = (((int)1) + L_alpha_hi_3016);
			t_sample L_a1_hi_3018 = (((int)-2) * L_cos_hi_3014);
			t_sample L_a2_hi_3019 = (((int)1) - L_alpha_hi_3016);
			t_sample L_lp_b0_h_3020 = safediv(((((int)1) - L_cos_hi_3014) * ((t_sample)0.5)), L_a0_hi_3017);
			t_sample L_lp_b1_h_3021 = safediv((((int)1) - L_cos_hi_3014), L_a0_hi_3017);
			t_sample L_lp_b2_h_3022 = L_lp_b0_h_3020;
			t_sample L_lp_a1_h_3023 = safediv(L_a1_hi_3018, L_a0_hi_3017);
			t_sample L_lp_a2_h_3024 = safediv(L_a2_hi_3019, L_a0_hi_3017);
			t_sample L_hp_b0_h_3025 = safediv(((((int)1) + L_cos_hi_3014) * ((t_sample)0.5)), L_a0_hi_3017);
			t_sample L_hp_b1_h_3026 = safediv((-(((int)1) + L_cos_hi_3014)), L_a0_hi_3017);
			t_sample L_hp_b2_h_3027 = L_hp_b0_h_3025;
			t_sample L_hp_a1_h_3028 = L_lp_a1_h_3023;
			t_sample L_hp_a2_h_3029 = L_lp_a2_h_3024;
			t_sample L_ap1_lp1_x1p = m_L_ap1_lp1_x_54;
			t_sample L_ap1_lp1_x2p = m_L_ap1_lp1_x_301;
			t_sample L_ap1_lp1_y1p = m_L_ap1_lp1_y_300;
			t_sample L_ap1_lp1_y2p = m_L_ap1_lp1_y_299;
			t_sample L_ap1_lp_s1 = (((((L_lp_b0_l_3003 * L_x_2990) + (L_lp_b1_l_3004 * L_ap1_lp1_x1p)) + (L_lp_b2_l_3005 * L_ap1_lp1_x2p)) - (L_lp_a1_l_3006 * L_ap1_lp1_y1p)) - (L_lp_a2_l_3007 * L_ap1_lp1_y2p));
			m_L_ap1_lp1_x_301 = L_ap1_lp1_x1p;
			m_L_ap1_lp1_x_54 = L_x_2990;
			m_L_ap1_lp1_y_299 = L_ap1_lp1_y1p;
			m_L_ap1_lp1_y_300 = L_ap1_lp_s1;
			t_sample L_ap1_lp2_x1p = m_L_ap1_lp2_x_52;
			t_sample L_ap1_lp2_x2p = m_L_ap1_lp2_x_298;
			t_sample L_ap1_lp2_y1p = m_L_ap1_lp2_y_297;
			t_sample L_ap1_lp2_y2p = m_L_ap1_lp2_y_296;
			t_sample L_ap1_lp = (((((L_lp_b0_l_3003 * L_ap1_lp_s1) + (L_lp_b1_l_3004 * L_ap1_lp2_x1p)) + (L_lp_b2_l_3005 * L_ap1_lp2_x2p)) - (L_lp_a1_l_3006 * L_ap1_lp2_y1p)) - (L_lp_a2_l_3007 * L_ap1_lp2_y2p));
			m_L_ap1_lp2_x_298 = L_ap1_lp2_x1p;
			m_L_ap1_lp2_x_52 = L_ap1_lp_s1;
			m_L_ap1_lp2_y_296 = L_ap1_lp2_y1p;
			m_L_ap1_lp2_y_297 = L_ap1_lp;
			t_sample L_ap1_hp1_x1p = m_L_ap1_hp1_x_50;
			t_sample L_ap1_hp1_x2p = m_L_ap1_hp1_x_295;
			t_sample L_ap1_hp1_y1p = m_L_ap1_hp1_y_294;
			t_sample L_ap1_hp1_y2p = m_L_ap1_hp1_y_293;
			t_sample L_ap1_hp_s1 = (((((L_hp_b0_l_3008 * L_x_2990) + (L_hp_b1_l_3009 * L_ap1_hp1_x1p)) + (L_hp_b2_l_3010 * L_ap1_hp1_x2p)) - (L_hp_a1_l_3011 * L_ap1_hp1_y1p)) - (L_hp_a2_l_3012 * L_ap1_hp1_y2p));
			m_L_ap1_hp1_x_295 = L_ap1_hp1_x1p;
			m_L_ap1_hp1_x_50 = L_x_2990;
			m_L_ap1_hp1_y_293 = L_ap1_hp1_y1p;
			m_L_ap1_hp1_y_294 = L_ap1_hp_s1;
			t_sample L_ap1_hp2_x1p = m_L_ap1_hp2_x_48;
			t_sample L_ap1_hp2_x2p = m_L_ap1_hp2_x_292;
			t_sample L_ap1_hp2_y1p = m_L_ap1_hp2_y_291;
			t_sample L_ap1_hp2_y2p = m_L_ap1_hp2_y_290;
			t_sample L_ap1_hp = (((((L_hp_b0_l_3008 * L_ap1_hp_s1) + (L_hp_b1_l_3009 * L_ap1_hp2_x1p)) + (L_hp_b2_l_3010 * L_ap1_hp2_x2p)) - (L_hp_a1_l_3011 * L_ap1_hp2_y1p)) - (L_hp_a2_l_3012 * L_ap1_hp2_y2p));
			m_L_ap1_hp2_x_292 = L_ap1_hp2_x1p;
			m_L_ap1_hp2_x_48 = L_ap1_hp_s1;
			m_L_ap1_hp2_y_290 = L_ap1_hp2_y1p;
			m_L_ap1_hp2_y_291 = L_ap1_hp;
			t_sample L_stage1_out = (L_ap1_lp + L_ap1_hp);
			t_sample L_ap2_lp1_x1p = m_L_ap2_lp1_x_46;
			t_sample L_ap2_lp1_x2p = m_L_ap2_lp1_x_289;
			t_sample L_ap2_lp1_y1p = m_L_ap2_lp1_y_288;
			t_sample L_ap2_lp1_y2p = m_L_ap2_lp1_y_287;
			t_sample L_ap2_lp_s1 = (((((L_lp_b0_h_3020 * L_stage1_out) + (L_lp_b1_h_3021 * L_ap2_lp1_x1p)) + (L_lp_b2_h_3022 * L_ap2_lp1_x2p)) - (L_lp_a1_h_3023 * L_ap2_lp1_y1p)) - (L_lp_a2_h_3024 * L_ap2_lp1_y2p));
			m_L_ap2_lp1_x_289 = L_ap2_lp1_x1p;
			m_L_ap2_lp1_x_46 = L_stage1_out;
			m_L_ap2_lp1_y_287 = L_ap2_lp1_y1p;
			m_L_ap2_lp1_y_288 = L_ap2_lp_s1;
			t_sample L_ap2_lp2_x1p = m_L_ap2_lp2_x_44;
			t_sample L_ap2_lp2_x2p = m_L_ap2_lp2_x_286;
			t_sample L_ap2_lp2_y1p = m_L_ap2_lp2_y_285;
			t_sample L_ap2_lp2_y2p = m_L_ap2_lp2_y_284;
			t_sample L_ap2_lp = (((((L_lp_b0_h_3020 * L_ap2_lp_s1) + (L_lp_b1_h_3021 * L_ap2_lp2_x1p)) + (L_lp_b2_h_3022 * L_ap2_lp2_x2p)) - (L_lp_a1_h_3023 * L_ap2_lp2_y1p)) - (L_lp_a2_h_3024 * L_ap2_lp2_y2p));
			m_L_ap2_lp2_x_286 = L_ap2_lp2_x1p;
			m_L_ap2_lp2_x_44 = L_ap2_lp_s1;
			m_L_ap2_lp2_y_284 = L_ap2_lp2_y1p;
			m_L_ap2_lp2_y_285 = L_ap2_lp;
			t_sample L_ap2_hp1_x1p = m_L_ap2_hp1_x_42;
			t_sample L_ap2_hp1_x2p = m_L_ap2_hp1_x_283;
			t_sample L_ap2_hp1_y1p = m_L_ap2_hp1_y_282;
			t_sample L_ap2_hp1_y2p = m_L_ap2_hp1_y_281;
			t_sample L_ap2_hp_s1 = (((((L_hp_b0_h_3025 * L_stage1_out) + (L_hp_b1_h_3026 * L_ap2_hp1_x1p)) + (L_hp_b2_h_3027 * L_ap2_hp1_x2p)) - (L_hp_a1_h_3028 * L_ap2_hp1_y1p)) - (L_hp_a2_h_3029 * L_ap2_hp1_y2p));
			m_L_ap2_hp1_x_283 = L_ap2_hp1_x1p;
			m_L_ap2_hp1_x_42 = L_stage1_out;
			m_L_ap2_hp1_y_281 = L_ap2_hp1_y1p;
			m_L_ap2_hp1_y_282 = L_ap2_hp_s1;
			t_sample L_ap2_hp2_x1p = m_L_ap2_hp2_x_40;
			t_sample L_ap2_hp2_x2p = m_L_ap2_hp2_x_280;
			t_sample L_ap2_hp2_y1p = m_L_ap2_hp2_y_279;
			t_sample L_ap2_hp2_y2p = m_L_ap2_hp2_y_278;
			t_sample L_ap2_hp = (((((L_hp_b0_h_3025 * L_ap2_hp_s1) + (L_hp_b1_h_3026 * L_ap2_hp2_x1p)) + (L_hp_b2_h_3027 * L_ap2_hp2_x2p)) - (L_hp_a1_h_3028 * L_ap2_hp2_y1p)) - (L_hp_a2_h_3029 * L_ap2_hp2_y2p));
			m_L_ap2_hp2_x_280 = L_ap2_hp2_x1p;
			m_L_ap2_hp2_x_40 = L_ap2_hp_s1;
			m_L_ap2_hp2_y_278 = L_ap2_hp2_y1p;
			m_L_ap2_hp2_y_279 = L_ap2_hp;
			t_sample dryCompL = (L_ap2_lp + L_ap2_hp);
			t_sample R_loF_3030 = smoothHpfFreq;
			t_sample R_hiF_3031 = smoothLpfFreq;
			t_sample R_x_3032 = rIn;
			t_sample maxb_385 = ((minb_384 < R_loF_3030) ? minb_384 : R_loF_3030);
			t_sample R_loF_3035 = ((((int)10) < maxb_385) ? maxb_385 : ((int)10));
			t_sample maxb_387 = ((minb_386 < R_hiF_3031) ? minb_386 : R_hiF_3031);
			t_sample R_hiFr_3036 = ((((int)10) < maxb_387) ? maxb_387 : ((int)10));
			t_sample maxb_388 = (R_loF_3035 + ((int)1));
			t_sample R_hiF_3037 = ((R_hiFr_3036 < maxb_388) ? maxb_388 : R_hiFr_3036);
			t_sample R_w0_lo_3038 = safediv((((t_sample)6.2831853071796) * R_loF_3035), R_sr_3034);
			t_sample R_cos_lo_3039 = cos(R_w0_lo_3038);
			t_sample R_sin_lo_3040 = sin(R_w0_lo_3038);
			t_sample R_alpha_lo_3041 = (R_sin_lo_3040 * ((t_sample)0.70710678118655));
			t_sample R_a0_lo_3042 = (((int)1) + R_alpha_lo_3041);
			t_sample R_a1_lo_3043 = (((int)-2) * R_cos_lo_3039);
			t_sample R_a2_lo_3044 = (((int)1) - R_alpha_lo_3041);
			t_sample R_lp_b0_l_3045 = safediv(((((int)1) - R_cos_lo_3039) * ((t_sample)0.5)), R_a0_lo_3042);
			t_sample R_lp_b1_l_3046 = safediv((((int)1) - R_cos_lo_3039), R_a0_lo_3042);
			t_sample R_lp_b2_l_3047 = R_lp_b0_l_3045;
			t_sample R_lp_a1_l_3048 = safediv(R_a1_lo_3043, R_a0_lo_3042);
			t_sample R_lp_a2_l_3049 = safediv(R_a2_lo_3044, R_a0_lo_3042);
			t_sample R_hp_b0_l_3050 = safediv(((((int)1) + R_cos_lo_3039) * ((t_sample)0.5)), R_a0_lo_3042);
			t_sample R_hp_b1_l_3051 = safediv((-(((int)1) + R_cos_lo_3039)), R_a0_lo_3042);
			t_sample R_hp_b2_l_3052 = R_hp_b0_l_3050;
			t_sample R_hp_a1_l_3053 = R_lp_a1_l_3048;
			t_sample R_hp_a2_l_3054 = R_lp_a2_l_3049;
			t_sample R_w0_hi_3055 = safediv((((t_sample)6.2831853071796) * R_hiF_3037), R_sr_3034);
			t_sample R_cos_hi_3056 = cos(R_w0_hi_3055);
			t_sample R_sin_hi_3057 = sin(R_w0_hi_3055);
			t_sample R_alpha_hi_3058 = (R_sin_hi_3057 * ((t_sample)0.70710678118655));
			t_sample R_a0_hi_3059 = (((int)1) + R_alpha_hi_3058);
			t_sample R_a1_hi_3060 = (((int)-2) * R_cos_hi_3056);
			t_sample R_a2_hi_3061 = (((int)1) - R_alpha_hi_3058);
			t_sample R_lp_b0_h_3062 = safediv(((((int)1) - R_cos_hi_3056) * ((t_sample)0.5)), R_a0_hi_3059);
			t_sample R_lp_b1_h_3063 = safediv((((int)1) - R_cos_hi_3056), R_a0_hi_3059);
			t_sample R_lp_b2_h_3064 = R_lp_b0_h_3062;
			t_sample R_lp_a1_h_3065 = safediv(R_a1_hi_3060, R_a0_hi_3059);
			t_sample R_lp_a2_h_3066 = safediv(R_a2_hi_3061, R_a0_hi_3059);
			t_sample R_hp_b0_h_3067 = safediv(((((int)1) + R_cos_hi_3056) * ((t_sample)0.5)), R_a0_hi_3059);
			t_sample R_hp_b1_h_3068 = safediv((-(((int)1) + R_cos_hi_3056)), R_a0_hi_3059);
			t_sample R_hp_b2_h_3069 = R_hp_b0_h_3067;
			t_sample R_hp_a1_h_3070 = R_lp_a1_h_3065;
			t_sample R_hp_a2_h_3071 = R_lp_a2_h_3066;
			t_sample R_ap1_lp1_x1p = m_R_ap1_lp1_x_53;
			t_sample R_ap1_lp1_x2p = m_R_ap1_lp1_x_241;
			t_sample R_ap1_lp1_y1p = m_R_ap1_lp1_y_240;
			t_sample R_ap1_lp1_y2p = m_R_ap1_lp1_y_239;
			t_sample R_ap1_lp_s1 = (((((R_lp_b0_l_3045 * R_x_3032) + (R_lp_b1_l_3046 * R_ap1_lp1_x1p)) + (R_lp_b2_l_3047 * R_ap1_lp1_x2p)) - (R_lp_a1_l_3048 * R_ap1_lp1_y1p)) - (R_lp_a2_l_3049 * R_ap1_lp1_y2p));
			m_R_ap1_lp1_x_241 = R_ap1_lp1_x1p;
			m_R_ap1_lp1_x_53 = R_x_3032;
			m_R_ap1_lp1_y_239 = R_ap1_lp1_y1p;
			m_R_ap1_lp1_y_240 = R_ap1_lp_s1;
			t_sample R_ap1_lp2_x1p = m_R_ap1_lp2_x_51;
			t_sample R_ap1_lp2_x2p = m_R_ap1_lp2_x_238;
			t_sample R_ap1_lp2_y1p = m_R_ap1_lp2_y_237;
			t_sample R_ap1_lp2_y2p = m_R_ap1_lp2_y_236;
			t_sample R_ap1_lp = (((((R_lp_b0_l_3045 * R_ap1_lp_s1) + (R_lp_b1_l_3046 * R_ap1_lp2_x1p)) + (R_lp_b2_l_3047 * R_ap1_lp2_x2p)) - (R_lp_a1_l_3048 * R_ap1_lp2_y1p)) - (R_lp_a2_l_3049 * R_ap1_lp2_y2p));
			m_R_ap1_lp2_x_238 = R_ap1_lp2_x1p;
			m_R_ap1_lp2_x_51 = R_ap1_lp_s1;
			m_R_ap1_lp2_y_236 = R_ap1_lp2_y1p;
			m_R_ap1_lp2_y_237 = R_ap1_lp;
			t_sample R_ap1_hp1_x1p = m_R_ap1_hp1_x_49;
			t_sample R_ap1_hp1_x2p = m_R_ap1_hp1_x_235;
			t_sample R_ap1_hp1_y1p = m_R_ap1_hp1_y_234;
			t_sample R_ap1_hp1_y2p = m_R_ap1_hp1_y_233;
			t_sample R_ap1_hp_s1 = (((((R_hp_b0_l_3050 * R_x_3032) + (R_hp_b1_l_3051 * R_ap1_hp1_x1p)) + (R_hp_b2_l_3052 * R_ap1_hp1_x2p)) - (R_hp_a1_l_3053 * R_ap1_hp1_y1p)) - (R_hp_a2_l_3054 * R_ap1_hp1_y2p));
			m_R_ap1_hp1_x_235 = R_ap1_hp1_x1p;
			m_R_ap1_hp1_x_49 = R_x_3032;
			m_R_ap1_hp1_y_233 = R_ap1_hp1_y1p;
			m_R_ap1_hp1_y_234 = R_ap1_hp_s1;
			t_sample R_ap1_hp2_x1p = m_R_ap1_hp2_x_47;
			t_sample R_ap1_hp2_x2p = m_R_ap1_hp2_x_232;
			t_sample R_ap1_hp2_y1p = m_R_ap1_hp2_y_231;
			t_sample R_ap1_hp2_y2p = m_R_ap1_hp2_y_230;
			t_sample R_ap1_hp = (((((R_hp_b0_l_3050 * R_ap1_hp_s1) + (R_hp_b1_l_3051 * R_ap1_hp2_x1p)) + (R_hp_b2_l_3052 * R_ap1_hp2_x2p)) - (R_hp_a1_l_3053 * R_ap1_hp2_y1p)) - (R_hp_a2_l_3054 * R_ap1_hp2_y2p));
			m_R_ap1_hp2_x_232 = R_ap1_hp2_x1p;
			m_R_ap1_hp2_x_47 = R_ap1_hp_s1;
			m_R_ap1_hp2_y_230 = R_ap1_hp2_y1p;
			m_R_ap1_hp2_y_231 = R_ap1_hp;
			t_sample R_stage1_out = (R_ap1_lp + R_ap1_hp);
			t_sample R_ap2_lp1_x1p = m_R_ap2_lp1_x_45;
			t_sample R_ap2_lp1_x2p = m_R_ap2_lp1_x_229;
			t_sample R_ap2_lp1_y1p = m_R_ap2_lp1_y_228;
			t_sample R_ap2_lp1_y2p = m_R_ap2_lp1_y_227;
			t_sample R_ap2_lp_s1 = (((((R_lp_b0_h_3062 * R_stage1_out) + (R_lp_b1_h_3063 * R_ap2_lp1_x1p)) + (R_lp_b2_h_3064 * R_ap2_lp1_x2p)) - (R_lp_a1_h_3065 * R_ap2_lp1_y1p)) - (R_lp_a2_h_3066 * R_ap2_lp1_y2p));
			m_R_ap2_lp1_x_229 = R_ap2_lp1_x1p;
			m_R_ap2_lp1_x_45 = R_stage1_out;
			m_R_ap2_lp1_y_227 = R_ap2_lp1_y1p;
			m_R_ap2_lp1_y_228 = R_ap2_lp_s1;
			t_sample R_ap2_lp2_x1p = m_R_ap2_lp2_x_43;
			t_sample R_ap2_lp2_x2p = m_R_ap2_lp2_x_226;
			t_sample R_ap2_lp2_y1p = m_R_ap2_lp2_y_225;
			t_sample R_ap2_lp2_y2p = m_R_ap2_lp2_y_224;
			t_sample R_ap2_lp = (((((R_lp_b0_h_3062 * R_ap2_lp_s1) + (R_lp_b1_h_3063 * R_ap2_lp2_x1p)) + (R_lp_b2_h_3064 * R_ap2_lp2_x2p)) - (R_lp_a1_h_3065 * R_ap2_lp2_y1p)) - (R_lp_a2_h_3066 * R_ap2_lp2_y2p));
			m_R_ap2_lp2_x_226 = R_ap2_lp2_x1p;
			m_R_ap2_lp2_x_43 = R_ap2_lp_s1;
			m_R_ap2_lp2_y_224 = R_ap2_lp2_y1p;
			m_R_ap2_lp2_y_225 = R_ap2_lp;
			t_sample R_ap2_hp1_x1p = m_R_ap2_hp1_x_41;
			t_sample R_ap2_hp1_x2p = m_R_ap2_hp1_x_223;
			t_sample R_ap2_hp1_y1p = m_R_ap2_hp1_y_222;
			t_sample R_ap2_hp1_y2p = m_R_ap2_hp1_y_221;
			t_sample R_ap2_hp_s1 = (((((R_hp_b0_h_3067 * R_stage1_out) + (R_hp_b1_h_3068 * R_ap2_hp1_x1p)) + (R_hp_b2_h_3069 * R_ap2_hp1_x2p)) - (R_hp_a1_h_3070 * R_ap2_hp1_y1p)) - (R_hp_a2_h_3071 * R_ap2_hp1_y2p));
			m_R_ap2_hp1_x_223 = R_ap2_hp1_x1p;
			m_R_ap2_hp1_x_41 = R_stage1_out;
			m_R_ap2_hp1_y_221 = R_ap2_hp1_y1p;
			m_R_ap2_hp1_y_222 = R_ap2_hp_s1;
			t_sample R_ap2_hp2_x1p = m_R_ap2_hp2_x_39;
			t_sample R_ap2_hp2_x2p = m_R_ap2_hp2_x_220;
			t_sample R_ap2_hp2_y1p = m_R_ap2_hp2_y_219;
			t_sample R_ap2_hp2_y2p = m_R_ap2_hp2_y_218;
			t_sample R_ap2_hp = (((((R_hp_b0_h_3067 * R_ap2_hp_s1) + (R_hp_b1_h_3068 * R_ap2_hp2_x1p)) + (R_hp_b2_h_3069 * R_ap2_hp2_x2p)) - (R_hp_a1_h_3070 * R_ap2_hp2_y1p)) - (R_hp_a2_h_3071 * R_ap2_hp2_y2p));
			m_R_ap2_hp2_x_220 = R_ap2_hp2_x1p;
			m_R_ap2_hp2_x_39 = R_ap2_hp_s1;
			m_R_ap2_hp2_y_218 = R_ap2_hp2_y1p;
			m_R_ap2_hp2_y_219 = R_ap2_hp;
			t_sample dryCompR = (R_ap2_lp + R_ap2_hp);
			t_sample mix_3167 = (lIn + (scSm * (dryCompL - lIn)));
			t_sample dryL = mix_3167;
			t_sample mix_3168 = (rIn + (scSm * (dryCompR - rIn)));
			t_sample dryR = mix_3168;
			t_sample lFiltered = preDistInL;
			t_sample rFiltered = preDistInR;
			t_sample Gls = (-tiltDb);
			t_sample Ghs = tiltDb;
			t_sample Als = sqrt(dbtoa(Gls));
			t_sample Ahs = sqrt(dbtoa(Ghs));
			t_sample alphaLs = ((((t_sample)0.5) * sn) * sqrt((((Als + safediv(((int)1), Als)) * ((int)1)) + ((int)2))));
			t_sample alphaHs = ((((t_sample)0.5) * sn) * sqrt((((Ahs + safediv(((int)1), Ahs)) * ((int)1)) + ((int)2))));
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
			t_sample lLs_3072 = (((((a0Ls * lFiltered) + (a1Ls * fixdenorm(m_tiltLsL_111))) + (a2Ls * fixdenorm(m_tiltLsL_112))) - (b1Ls * fixdenorm(m_tiltLsL_109))) - (b2Ls * fixdenorm(m_tiltLsL_110)));
			m_tiltLsL_112 = m_tiltLsL_111;
			m_tiltLsL_111 = lFiltered;
			m_tiltLsL_110 = m_tiltLsL_109;
			m_tiltLsL_109 = lLs_3072;
			t_sample rLs_3073 = (((((a0Ls * rFiltered) + (a1Ls * fixdenorm(m_tiltLsR_107))) + (a2Ls * fixdenorm(m_tiltLsR_108))) - (b1Ls * fixdenorm(m_tiltLsR_105))) - (b2Ls * fixdenorm(m_tiltLsR_106)));
			m_tiltLsR_108 = m_tiltLsR_107;
			m_tiltLsR_107 = rFiltered;
			m_tiltLsR_106 = m_tiltLsR_105;
			m_tiltLsR_105 = rLs_3073;
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
			t_sample lTiltRaw = (((((a0Hs * lLs_3072) + (a1Hs * fixdenorm(m_tiltHsL_103))) + (a2Hs * fixdenorm(m_tiltHsL_104))) - (b1Hs * fixdenorm(m_tiltHsL_101))) - (b2Hs * fixdenorm(m_tiltHsL_102)));
			m_tiltHsL_104 = m_tiltHsL_103;
			m_tiltHsL_103 = lLs_3072;
			m_tiltHsL_102 = m_tiltHsL_101;
			m_tiltHsL_101 = lTiltRaw;
			t_sample rTiltRaw = (((((a0Hs * rLs_3073) + (a1Hs * fixdenorm(m_tiltHsR_99))) + (a2Hs * fixdenorm(m_tiltHsR_100))) - (b1Hs * fixdenorm(m_tiltHsR_97))) - (b2Hs * fixdenorm(m_tiltHsR_98)));
			m_tiltHsR_100 = m_tiltHsR_99;
			m_tiltHsR_99 = rLs_3073;
			m_tiltHsR_98 = m_tiltHsR_97;
			m_tiltHsR_97 = rTiltRaw;
			t_sample nr_ls = ((a0Ls + (a1Ls * cosw)) + (a2Ls * cos2));
			t_sample ni_ls = (-((a1Ls * sinw) + (a2Ls * sin2)));
			t_sample dr_ls = ((((int)1) + (b1Ls * cosw)) + (b2Ls * cos2));
			t_sample di_ls = (-((b1Ls * sinw) + (b2Ls * sin2)));
			t_sample maxb_389 = ((dr_ls * dr_ls) + (di_ls * di_ls));
			t_sample mag2_ls = safediv(((nr_ls * nr_ls) + (ni_ls * ni_ls)), ((((t_sample)1e-12) < maxb_389) ? maxb_389 : ((t_sample)1e-12)));
			t_sample mag_ls = sqrt(mag2_ls);
			t_sample nr_hs = ((a0Hs + (a1Hs * cosw)) + (a2Hs * cos2));
			t_sample ni_hs = (-((a1Hs * sinw) + (a2Hs * sin2)));
			t_sample dr_hs = ((((int)1) + (b1Hs * cosw)) + (b2Hs * cos2));
			t_sample di_hs = (-((b1Hs * sinw) + (b2Hs * sin2)));
			t_sample maxb_390 = ((dr_hs * dr_hs) + (di_hs * di_hs));
			t_sample mag2_hs = safediv(((nr_hs * nr_hs) + (ni_hs * ni_hs)), ((((t_sample)1e-12) < maxb_390) ? maxb_390 : ((t_sample)1e-12)));
			t_sample mag_hs = sqrt(mag2_hs);
			t_sample maxb_391 = (mag_ls * mag_hs);
			t_sample gPivot = safediv(((int)1), ((((t_sample)1e-09) < maxb_391) ? maxb_391 : ((t_sample)1e-09)));
			t_sample lTilt = (lTiltRaw * gPivot);
			t_sample rTilt = (rTiltRaw * gPivot);
			t_sample mix_3169 = (lFiltered + (tiltOn * (lTilt - lFiltered)));
			t_sample lTiltAct = mix_3169;
			t_sample mix_3170 = (rFiltered + (tiltOn * (rTilt - rFiltered)));
			t_sample rTiltAct = mix_3170;
			t_sample mode = smoothedMode;
			t_sample maxb_392 = (((int)1) - fabs((mode - ((int)0))));
			t_sample w0 = ((((int)0) < maxb_392) ? maxb_392 : ((int)0));
			t_sample maxb_393 = (((int)1) - fabs((mode - ((int)1))));
			t_sample w1 = ((((int)0) < maxb_393) ? maxb_393 : ((int)0));
			t_sample maxb_394 = (((int)1) - fabs((mode - ((int)2))));
			t_sample w2 = ((((int)0) < maxb_394) ? maxb_394 : ((int)0));
			t_sample maxb_395 = (((int)1) - fabs((mode - ((int)3))));
			t_sample w3 = ((((int)0) < maxb_395) ? maxb_395 : ((int)0));
			t_sample maxb_396 = (((int)1) - fabs((mode - ((int)4))));
			t_sample w4 = ((((int)0) < maxb_396) ? maxb_396 : ((int)0));
			t_sample maxb_397 = (((int)1) - fabs((mode - ((int)5))));
			t_sample w5 = ((((int)0) < maxb_397) ? maxb_397 : ((int)0));
			t_sample maxb_398 = (((int)1) - fabs((mode - ((int)6))));
			t_sample w6 = ((((int)0) < maxb_398) ? maxb_398 : ((int)0));
			t_sample maxb_399 = (((int)1) - fabs((mode - ((int)7))));
			t_sample w7 = ((((int)0) < maxb_399) ? maxb_399 : ((int)0));
			t_sample sumWeights = ((((((((w0 + w1) + w2) + w3) + w4) + w5) + w6) + w7) + ((t_sample)0.0001));
			t_sample w_3074 = safediv(w0, sumWeights);
			t_sample w_3075 = safediv(w1, sumWeights);
			t_sample w_3076 = safediv(w2, sumWeights);
			t_sample w_3077 = safediv(w3, sumWeights);
			t_sample w_3078 = safediv(w4, sumWeights);
			t_sample w_3079 = safediv(w5, sumWeights);
			t_sample w_3080 = safediv(w6, sumWeights);
			t_sample w_3081 = safediv(w7, sumWeights);
			t_sample dcNorm = ((m_hDc_135 * ((int)2)) - ((int)1));
			t_sample dcSkew = (tanh((dcNorm * ((int)3))) * ((t_sample)0.4));
			t_sample preAL_x1p = fixdenorm(m_preToneAL_x_24);
			t_sample preAL_x2p = fixdenorm(m_preToneAL_x_23);
			t_sample preAL_y1p = fixdenorm(m_preToneAL_y_22);
			t_sample preAL_y2p = fixdenorm(m_preToneAL_y_21);
			t_sample preA_L = (((((t_a0 * lTiltAct) + (t_a1 * preAL_x1p)) + (t_a2 * preAL_x2p)) - (t_b1 * preAL_y1p)) - (t_b2 * preAL_y2p));
			m_preToneAL_x_23 = preAL_x1p;
			m_preToneAL_x_24 = lTiltAct;
			m_preToneAL_y_21 = preAL_y1p;
			m_preToneAL_y_22 = preA_L;
			t_sample preAR_x1p = fixdenorm(m_preToneAR_x_20);
			t_sample preAR_x2p = fixdenorm(m_preToneAR_x_19);
			t_sample preAR_y1p = fixdenorm(m_preToneAR_y_18);
			t_sample preAR_y2p = fixdenorm(m_preToneAR_y_17);
			t_sample preA_R = (((((t_a0 * rTiltAct) + (t_a1 * preAR_x1p)) + (t_a2 * preAR_x2p)) - (t_b1 * preAR_y1p)) - (t_b2 * preAR_y2p));
			m_preToneAR_x_19 = preAR_x1p;
			m_preToneAR_x_20 = rTiltAct;
			m_preToneAR_y_17 = preAR_y1p;
			m_preToneAR_y_18 = preA_R;
			t_sample preBL_x1p = fixdenorm(m_preToneBL_x_16);
			t_sample preBL_x2p = fixdenorm(m_preToneBL_x_15);
			t_sample preBL_y1p = fixdenorm(m_preToneBL_y_14);
			t_sample preBL_y2p = fixdenorm(m_preToneBL_y_13);
			t_sample preB_L = (((((t_a0 * preDistInL) + (t_a1 * preBL_x1p)) + (t_a2 * preBL_x2p)) - (t_b1 * preBL_y1p)) - (t_b2 * preBL_y2p));
			m_preToneBL_x_15 = preBL_x1p;
			m_preToneBL_x_16 = preDistInL;
			m_preToneBL_y_13 = preBL_y1p;
			m_preToneBL_y_14 = preB_L;
			t_sample preBR_x1p = fixdenorm(m_preToneBR_x_12);
			t_sample preBR_x2p = fixdenorm(m_preToneBR_x_11);
			t_sample preBR_y1p = fixdenorm(m_preToneBR_y_10);
			t_sample preBR_y2p = fixdenorm(m_preToneBR_y_9);
			t_sample preB_R = (((((t_a0 * preDistInR) + (t_a1 * preBR_x1p)) + (t_a2 * preBR_x2p)) - (t_b1 * preBR_y1p)) - (t_b2 * preBR_y2p));
			m_preToneBR_x_11 = preBR_x1p;
			m_preToneBR_x_12 = preDistInR;
			m_preToneBR_y_9 = preBR_y1p;
			m_preToneBR_y_10 = preB_R;
			t_sample mul_3172 = (wTonePre * toneOn);
			t_sample mix_3171 = (lTiltAct + (mul_3172 * (preA_L - lTiltAct)));
			t_sample inA_L = mix_3171;
			t_sample mul_3174 = (wTonePre * toneOn);
			t_sample mix_3173 = (rTiltAct + (mul_3174 * (preA_R - rTiltAct)));
			t_sample inA_R = mix_3173;
			t_sample mul_3176 = (wTonePre * toneOn);
			t_sample mix_3175 = (preDistInL + (mul_3176 * (preB_L - preDistInL)));
			t_sample inB_L = mix_3175;
			t_sample mul_3178 = (wTonePre * toneOn);
			t_sample mix_3177 = (preDistInR + (mul_3178 * (preB_R - preDistInR)));
			t_sample inB_R = mix_3177;
			t_sample return_408;
			t_sample return_409;
			softclip_d_d_d_d_d(inA_L, inA_R, drive, dc, ceiling, return_408, return_409);
			t_sample softL_A = return_408;
			t_sample softR_A = return_409;
			t_sample return_420;
			t_sample return_421;
			sigmoid_d_d_d_d_d(inA_L, inA_R, drive, dc, ceiling, return_420, return_421);
			t_sample sigmL_A = return_420;
			t_sample sigmR_A = return_421;
			t_sample return_430;
			t_sample return_431;
			rectF_d_d_d_d_d(inA_L, inA_R, drive, dc, ceiling, return_430, return_431);
			t_sample rectL_A = return_430;
			t_sample rectR_A = return_431;
			t_sample return_440;
			t_sample return_441;
			fuzzExp1_d_d_d_d_d(inA_L, inA_R, drive, dc, ceiling, return_440, return_441);
			t_sample fuzz1L_A = return_440;
			t_sample fuzz1R_A = return_441;
			t_sample return_456;
			t_sample return_457;
			tangenteHiperbolica_d_d_d_d_d(inA_L, inA_R, drive, dc, ceiling, return_456, return_457);
			t_sample tanhL_A = return_456;
			t_sample tanhR_A = return_457;
			t_sample return_464;
			t_sample return_465;
			rectH_d_d_d_d_d(inA_L, inA_R, drive, dc, ceiling, return_464, return_465);
			t_sample recthL_A = return_464;
			t_sample recthR_A = return_465;
			t_sample return_472;
			t_sample return_473;
			arctangent_d_d_d_d_d(inA_L, inA_R, drive, dc, ceiling, return_472, return_473);
			t_sample atanL_A = return_472;
			t_sample atanR_A = return_473;
			t_sample return_488;
			t_sample return_489;
			hardClip_d_d_d_d_d(inA_L, inA_R, drive, dc, ceiling, return_488, return_489);
			t_sample hardL_A = return_488;
			t_sample hardR_A = return_489;
			t_sample distL_A = ((((((((softL_A * w_3074) + (sigmL_A * w_3075)) + (rectL_A * w_3076)) + (fuzz1L_A * w_3077)) + (tanhL_A * w_3078)) + (recthL_A * w_3079)) + (atanL_A * w_3080)) + (hardL_A * w_3081));
			t_sample distR_A = ((((((((softR_A * w_3074) + (sigmR_A * w_3075)) + (rectR_A * w_3076)) + (fuzz1R_A * w_3077)) + (tanhR_A * w_3078)) + (recthR_A * w_3079)) + (atanR_A * w_3080)) + (hardR_A * w_3081));
			t_sample preOutL = __m_dcblock_490(distL_A);
			t_sample preOutR = __m_dcblock_491(distR_A);
			t_sample return_492;
			t_sample return_493;
			softclip_d_d_d_d_d(inB_L, inB_R, drive, dcSkew, ceiling, return_492, return_493);
			t_sample softL_B = return_492;
			t_sample softR_B = return_493;
			t_sample return_494;
			t_sample return_495;
			sigmoid_d_d_d_d_d(inB_L, inB_R, drive, dcSkew, ceiling, return_494, return_495);
			t_sample sigmL_B = return_494;
			t_sample sigmR_B = return_495;
			t_sample return_496;
			t_sample return_497;
			rectF_d_d_d_d_d(inB_L, inB_R, drive, dcSkew, ceiling, return_496, return_497);
			t_sample rectL_B = return_496;
			t_sample rectR_B = return_497;
			t_sample return_498;
			t_sample return_499;
			fuzzExp1_d_d_d_d_d(inB_L, inB_R, drive, dcSkew, ceiling, return_498, return_499);
			t_sample fuzz1L_B = return_498;
			t_sample fuzz1R_B = return_499;
			t_sample return_500;
			t_sample return_501;
			tangenteHiperbolica_d_d_d_d_d(inB_L, inB_R, drive, dcSkew, ceiling, return_500, return_501);
			t_sample tanhL_B = return_500;
			t_sample tanhR_B = return_501;
			t_sample return_502;
			t_sample return_503;
			rectH_d_d_d_d_d(inB_L, inB_R, drive, dcSkew, ceiling, return_502, return_503);
			t_sample recthL_B = return_502;
			t_sample recthR_B = return_503;
			t_sample return_504;
			t_sample return_505;
			arctangent_d_d_d_d_d(inB_L, inB_R, drive, dcSkew, ceiling, return_504, return_505);
			t_sample atanL_B = return_504;
			t_sample atanR_B = return_505;
			t_sample return_506;
			t_sample return_507;
			hardClip_d_d_d_d_d(inB_L, inB_R, drive, dcSkew, ceiling, return_506, return_507);
			t_sample hardL_B = return_506;
			t_sample hardR_B = return_507;
			t_sample distL_B = ((((((((softL_B * w_3074) + (sigmL_B * w_3075)) + (rectL_B * w_3076)) + (fuzz1L_B * w_3077)) + (tanhL_B * w_3078)) + (recthL_B * w_3079)) + (atanL_B * w_3080)) + (hardL_B * w_3081));
			t_sample distR_B = ((((((((softR_B * w_3074) + (sigmR_B * w_3075)) + (rectR_B * w_3076)) + (fuzz1R_B * w_3077)) + (tanhR_B * w_3078)) + (recthR_B * w_3079)) + (atanR_B * w_3080)) + (hardR_B * w_3081));
			t_sample postInL = __m_dcblock_508(distL_B);
			t_sample postInR = __m_dcblock_509(distR_B);
			t_sample postLsL = (((((a0Ls * postInL) + (a1Ls * m_postTiltLsL_93)) + (a2Ls * m_postTiltLsL_94)) - (b1Ls * m_postTiltLsL_91)) - (b2Ls * m_postTiltLsL_92));
			m_postTiltLsL_94 = m_postTiltLsL_93;
			m_postTiltLsL_93 = postInL;
			m_postTiltLsL_92 = m_postTiltLsL_91;
			m_postTiltLsL_91 = postLsL;
			t_sample postLsR = (((((a0Ls * postInR) + (a1Ls * m_postTiltLsR_89)) + (a2Ls * m_postTiltLsR_90)) - (b1Ls * m_postTiltLsR_87)) - (b2Ls * m_postTiltLsR_88));
			m_postTiltLsR_90 = m_postTiltLsR_89;
			m_postTiltLsR_89 = postInR;
			m_postTiltLsR_88 = m_postTiltLsR_87;
			m_postTiltLsR_87 = postLsR;
			t_sample postTiltRawL = (((((a0Hs * postLsL) + (a1Hs * m_postTiltHsL_85)) + (a2Hs * m_postTiltHsL_86)) - (b1Hs * m_postTiltHsL_83)) - (b2Hs * m_postTiltHsL_84));
			m_postTiltHsL_86 = m_postTiltHsL_85;
			m_postTiltHsL_85 = postLsL;
			m_postTiltHsL_84 = m_postTiltHsL_83;
			m_postTiltHsL_83 = postTiltRawL;
			t_sample postTiltRawR = (((((a0Hs * postLsR) + (a1Hs * m_postTiltHsR_81)) + (a2Hs * m_postTiltHsR_82)) - (b1Hs * m_postTiltHsR_79)) - (b2Hs * m_postTiltHsR_80));
			m_postTiltHsR_82 = m_postTiltHsR_81;
			m_postTiltHsR_81 = postLsR;
			m_postTiltHsR_80 = m_postTiltHsR_79;
			m_postTiltHsR_79 = postTiltRawR;
			t_sample postTiltL = (postTiltRawL * gPivot);
			t_sample postTiltR = (postTiltRawR * gPivot);
			t_sample mix_3179 = (postInL + (tiltOn * (postTiltL - postInL)));
			t_sample postTiltActL = mix_3179;
			t_sample mix_3180 = (postInR + (tiltOn * (postTiltR - postInR)));
			t_sample postTiltActR = mix_3180;
			t_sample mix_3181 = (preOutL + (wPost * (postTiltActL - preOutL)));
			t_sample distMorphL = mix_3181;
			t_sample mix_3182 = (preOutR + (wPost * (postTiltActR - preOutR)));
			t_sample distMorphR = mix_3182;
			t_sample cleanPreTiltL = inA_L;
			t_sample cleanPreTiltR = inA_R;
			t_sample mix_3183 = (cleanPreTiltL + (wDist * (distMorphL - cleanPreTiltL)));
			t_sample processedL = mix_3183;
			t_sample mix_3184 = (cleanPreTiltR + (wDist * (distMorphR - cleanPreTiltR)));
			t_sample processedR = mix_3184;
			t_sample return_510;
			t_sample return_511;
			bitCrusher_d_d_d(processedL, processedR, bits, return_510, return_511);
			t_sample bitL = return_510;
			t_sample bitR = return_511;
			t_sample bcL = __m_dcblock_512(bitL);
			t_sample bcR = __m_dcblock_513(bitR);
			t_sample mix_3185 = (processedL + (bitson * (bcL - processedL)));
			t_sample withBitCrusherL = mix_3185;
			t_sample mix_3186 = (processedR + (bitson * (bcR - processedR)));
			t_sample withBitCrusherR = mix_3186;
			t_sample maxb_514 = floor((m_hDownsample_126 + ((int)1)));
			t_sample deciFactor = ((((int)1) < maxb_514) ? maxb_514 : ((int)1));
			int enableNow = (downsampleOn > ((t_sample)0.5));
			int enableEdge = (enableNow > m_dsEnablePrev_113);
			m_dsEnablePrev_113 = enableNow;
			t_sample inc = safediv(((int)1), deciFactor);
			t_sample iffalse_515 = (m_dsPhase_115 + inc);
			m_dsPhase_115 = (enableEdge ? ((int)0) : iffalse_515);
			m_dsPhase_115 = (m_dsPhase_115 - floor(m_dsPhase_115));
			int dsEdgeWrap = (m_dsPhase_115 < m_dsTrigPrev_114);
			int dsEdge = (((enableEdge + dsEdgeWrap) + (deciFactor == ((int)1))) > ((t_sample)0.5));
			m_dsTrigPrev_114 = m_dsPhase_115;
			__m_latch_516 = ((dsEdge != 0) ? withBitCrusherL : __m_latch_516);
			t_sample dsHeldL = __m_latch_516;
			__m_latch_517 = ((dsEdge != 0) ? withBitCrusherR : __m_latch_517);
			t_sample dsHeldR = __m_latch_517;
			t_sample mix_3187 = (withBitCrusherL + (downsampleOn * (dsHeldL - withBitCrusherL)));
			t_sample wetFinalL = mix_3187;
			t_sample mix_3188 = (withBitCrusherR + (downsampleOn * (dsHeldR - withBitCrusherR)));
			t_sample wetFinalR = mix_3188;
			t_sample wetWithMakeupL = ((wetFinalL * outputMakeupLinear) + (bypassWhenActiveL * scSm));
			t_sample wetWithMakeupR = ((wetFinalR * outputMakeupLinear) + (bypassWhenActiveR * scSm));
			t_sample tL_x1p = fixdenorm(m_toneL_x_33);
			t_sample tL_x2p = fixdenorm(m_toneL_x_32);
			t_sample tL_y1p = fixdenorm(m_toneL_y_31);
			t_sample tL_y2p = fixdenorm(m_toneL_y_30);
			t_sample wetToneL = (((((t_a0 * wetWithMakeupL) + (t_a1 * tL_x1p)) + (t_a2 * tL_x2p)) - (t_b1 * tL_y1p)) - (t_b2 * tL_y2p));
			m_toneL_x_32 = tL_x1p;
			m_toneL_x_33 = wetWithMakeupL;
			m_toneL_y_30 = tL_y1p;
			m_toneL_y_31 = wetToneL;
			t_sample tR_x1p = fixdenorm(m_toneR_x_29);
			t_sample tR_x2p = fixdenorm(m_toneR_x_28);
			t_sample tR_y1p = fixdenorm(m_toneR_y_27);
			t_sample tR_y2p = fixdenorm(m_toneR_y_26);
			t_sample wetToneR = (((((t_a0 * wetWithMakeupR) + (t_a1 * tR_x1p)) + (t_a2 * tR_x2p)) - (t_b1 * tR_y1p)) - (t_b2 * tR_y2p));
			m_toneR_x_28 = tR_x1p;
			m_toneR_x_29 = wetWithMakeupR;
			m_toneR_y_26 = tR_y1p;
			m_toneR_y_27 = wetToneR;
			t_sample mul_3190 = (toneOn * wTonePost);
			t_sample mix_3189 = (wetWithMakeupL + (mul_3190 * (wetToneL - wetWithMakeupL)));
			t_sample mul_3192 = (toneOn * wTonePost);
			t_sample mix_3191 = (wetWithMakeupR + (mul_3192 * (wetToneR - wetWithMakeupR)));
			t_sample apL_x1p = fixdenorm(m_toneApL_x_8);
			t_sample apL_x2p = fixdenorm(m_toneApL_x_7);
			t_sample apL_y1p = fixdenorm(m_toneApL_y_6);
			t_sample apL_y2p = fixdenorm(m_toneApL_y_5);
			t_sample dryCompL_3082 = (((((ap_b0 * dryL) + (ap_b1 * apL_x1p)) + (((int)1) * apL_x2p)) - (ap_a1 * apL_y1p)) - (ap_a2 * apL_y2p));
			m_toneApL_x_7 = apL_x1p;
			m_toneApL_x_8 = dryL;
			m_toneApL_y_5 = apL_y1p;
			m_toneApL_y_6 = dryCompL_3082;
			t_sample apR_x1p = fixdenorm(m_toneApR_x_4);
			t_sample apR_x2p = fixdenorm(m_toneApR_x_3);
			t_sample apR_y1p = fixdenorm(m_toneApR_y_2);
			t_sample apR_y2p = fixdenorm(m_toneApR_y_1);
			t_sample dryCompR_3083 = (((((ap_b0 * dryR) + (ap_b1 * apR_x1p)) + (((int)1) * apR_x2p)) - (ap_a1 * apR_y1p)) - (ap_a2 * apR_y2p));
			m_toneApR_x_3 = apR_x1p;
			m_toneApR_x_4 = dryR;
			m_toneApR_y_1 = apR_y1p;
			m_toneApR_y_2 = dryCompR_3083;
			t_sample mix_3193 = (dryL + (toneOn * (dryCompL_3082 - dryL)));
			t_sample mix_3194 = (dryR + (toneOn * (dryCompR_3083 - dryR)));
			t_sample mix_3195 = (mix_3193 + (drywet * (mix_3189 - mix_3193)));
			t_sample mix_3196 = (mix_3194 + (drywet * (mix_3191 - mix_3194)));
			t_sample clamp_3198 = ((mix_3195 <= ((t_sample)-0.98855309465694)) ? ((t_sample)-0.98855309465694) : ((mix_3195 >= ((t_sample)0.98855309465694)) ? ((t_sample)0.98855309465694) : mix_3195));
			t_sample mix_3197 = (mix_3195 + (safeOn * (clamp_3198 - mix_3195)));
			t_sample clamp_3200 = ((mix_3196 <= ((t_sample)-0.98855309465694)) ? ((t_sample)-0.98855309465694) : ((mix_3196 >= ((t_sample)0.98855309465694)) ? ((t_sample)0.98855309465694) : mix_3196));
			t_sample mix_3199 = (mix_3196 + (safeOn * (clamp_3200 - mix_3196)));
			t_sample mix_3201 = (lIn + (bypass * (mix_3197 - lIn)));
			t_sample mix_3202 = (rIn + (bypass * (mix_3199 - rIn)));
			t_sample out4 = lTrimmed;
			t_sample out3 = ((int)0);
			t_sample out2 = mix_3202;
			t_sample out1 = mix_3201;
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
	inline void set_u_TONEPOS(t_param _value) {
		m_u_TONEPOS_338 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_t_TONEQ(t_param _value) {
		m_t_TONEQ_339 = (_value < 0.70710678118655 ? 0.70710678118655 : (_value > 16 ? 16 : _value));
	};
	inline void set_r_TONEFREQ(t_param _value) {
		m_r_TONEFREQ_340 = (_value < 20 ? 20 : (_value > 20000 ? 20000 : _value));
	};
	inline void set_q_TONEON(t_param _value) {
		m_q_TONEON_341 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_p_SAFELIMITON(t_param _value) {
		m_p_SAFELIMITON_342 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_p_BANDSOLO(t_param _value) {
		m_p_BANDSOLO_343 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_p_DISTON(t_param _value) {
		m_p_DISTON_344 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_p_TILTPOS(t_param _value) {
		m_p_TILTPOS_345 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_o_BAND(t_param _value) {
		m_o_BAND_346 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_n_DOWNSAMPLEON(t_param _value) {
		m_n_DOWNSAMPLEON_347 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_m_DOWNSAMPLE(t_param _value) {
		m_m_DOWNSAMPLE_348 = (_value < 0 ? 0 : (_value > 99 ? 99 : _value));
	};
	inline void set_l_OUTPUT(t_param _value) {
		m_l_OUTPUT_349 = (_value < -24 ? -24 : (_value > 12 ? 12 : _value));
	};
	inline void set_k_INPUT(t_param _value) {
		m_k_INPUT_350 = (_value < -12 ? -12 : (_value > 12 ? 12 : _value));
	};
	inline void set_l_SC(t_param _value) {
		m_l_SC_351 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_k_LPF(t_param _value) {
		m_k_LPF_352 = (_value < 1000 ? 1000 : (_value > 20000 ? 20000 : _value));
	};
	inline void set_j_HPF(t_param _value) {
		m_j_HPF_353 = (_value < 20 ? 20 : (_value > 1000 ? 1000 : _value));
	};
	inline void set_s_TILTON(t_param _value) {
		m_s_TILTON_354 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_i_TILT(t_param _value) {
		m_i_TILT_355 = (_value < -6 ? -6 : (_value > 6 ? 6 : _value));
	};
	inline void set_h_BITSON(t_param _value) {
		m_h_BITSON_356 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_g_BITS(t_param _value) {
		m_g_BITS_357 = (_value < 2 ? 2 : (_value > 16 ? 16 : _value));
	};
	inline void set_f_BYPASS(t_param _value) {
		m_f_BYPASS_358 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_e_CEILING(t_param _value) {
		m_e_CEILING_359 = (_value < -20 ? -20 : (_value > 6 ? 6 : _value));
	};
	inline void set_d_MODE(t_param _value) {
		m_d_MODE_360 = (_value < 0 ? 0 : (_value > 7 ? 7 : _value));
	};
	inline void set_c_DC(t_param _value) {
		m_c_DC_361 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_b_DRIVE(t_param _value) {
		m_b_DRIVE_362 = (_value < 1 ? 1 : (_value > 50 ? 50 : _value));
	};
	inline void set_a_DRYWET(t_param _value) {
		m_a_DRYWET_363 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void softclip_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_400 = (inl >= ((int)0));
		t_sample iftrue_401 = (inl * lDrivePos);
		t_sample iffalse_402 = (inl * lDriveNeg);
		t_sample lNorm = safediv((cond_400 ? iftrue_401 : iffalse_402), cell);
		int cond_403 = (inr >= ((int)0));
		t_sample iftrue_404 = (inr * rDrivePos);
		t_sample iffalse_405 = (inr * rDriveNeg);
		t_sample rNorm = safediv((cond_403 ? iftrue_404 : iffalse_405), cell);
		t_sample lCubic = (lNorm - (((lNorm * lNorm) * lNorm) * ((t_sample)0.33333333333333)));
		t_sample rCubic = (rNorm - (((rNorm * rNorm) * rNorm) * ((t_sample)0.33333333333333)));
		t_sample lLimited = (((lNorm > 0) ? 1 : ((lNorm < 0) ? -1 : 0)) * (((int)2) * ((t_sample)0.33333333333333)));
		t_sample rLimited = (((rNorm > 0) ? 1 : ((rNorm < 0) ? -1 : 0)) * (((int)2) * ((t_sample)0.33333333333333)));
		int cond_406 = (fabs(lNorm) <= ((int)1));
		t_sample lOut = (cond_406 ? lCubic : lLimited);
		int cond_407 = (fabs(rNorm) <= ((int)1));
		t_sample rOut = (cond_407 ? rCubic : rLimited);
		out1 = (lOut * cell);
		out2 = (rOut * cell);
		
	};
	inline void sigmoid_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_410 = (inl >= ((int)0));
		t_sample iftrue_411 = (inl * lDrivePos);
		t_sample iffalse_412 = (inl * lDriveNeg);
		t_sample lAdj = (cond_410 ? iftrue_411 : iffalse_412);
		int cond_413 = (inr >= ((int)0));
		t_sample iftrue_414 = (inr * rDrivePos);
		t_sample iffalse_415 = (inr * rDriveNeg);
		t_sample rAdj = (cond_413 ? iftrue_414 : iffalse_415);
		int factor = (-((int)1));
		t_sample l = ((((int)2) * safediv(((int)1), (((int)1) + exp((factor * lAdj))))) - ((int)1));
		t_sample r = ((((int)2) * safediv(((int)1), (((int)1) + exp((factor * rAdj))))) - ((int)1));
		t_sample v_416 = (l * cell);
		t_sample min_417 = (-cell);
		t_sample lOut = ((v_416 <= min_417) ? min_417 : ((v_416 >= cell) ? cell : v_416));
		t_sample v_418 = (r * cell);
		t_sample min_419 = (-cell);
		t_sample rOut = ((v_418 <= min_419) ? min_419 : ((v_418 >= cell) ? cell : v_418));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void rectF_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_422 = (inl >= ((int)0));
		t_sample iftrue_423 = (inl * lDrivePos);
		t_sample iffalse_424 = (inl * lDriveNeg);
		t_sample lAdj = (cond_422 ? iftrue_423 : iffalse_424);
		int cond_425 = (inr >= ((int)0));
		t_sample iftrue_426 = (inr * rDrivePos);
		t_sample iffalse_427 = (inr * rDriveNeg);
		t_sample rAdj = (cond_425 ? iftrue_426 : iffalse_427);
		t_sample l = ((((lAdj > 0) ? 1 : ((lAdj < 0) ? -1 : 0)) * fabs(lAdj)) * ((t_sample)0.707));
		t_sample r = ((((rAdj > 0) ? 1 : ((rAdj < 0) ? -1 : 0)) * fabs(rAdj)) * ((t_sample)0.707));
		t_sample min_428 = (-cell);
		t_sample lOut = ((l <= min_428) ? min_428 : ((l >= cell) ? cell : l));
		t_sample min_429 = (-cell);
		t_sample rOut = ((r <= min_429) ? min_429 : ((r >= cell) ? cell : r));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void fuzzExp1_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_432 = (inl >= ((int)0));
		t_sample iftrue_433 = (inl * lDrivePos);
		t_sample iffalse_434 = (inl * lDriveNeg);
		t_sample lAdj = (cond_432 ? iftrue_433 : iffalse_434);
		int cond_435 = (inr >= ((int)0));
		t_sample iftrue_436 = (inr * rDrivePos);
		t_sample iffalse_437 = (inr * rDriveNeg);
		t_sample rAdj = (cond_435 ? iftrue_436 : iffalse_437);
		int signl = ((lAdj > 0) ? 1 : ((lAdj < 0) ? -1 : 0));
		int signr = ((rAdj > 0) ? 1 : ((rAdj < 0) ? -1 : 0));
		t_sample l = (signl * (((int)1) - exp((-fabs(lAdj)))));
		t_sample r = (signr * (((int)1) - exp((-fabs(rAdj)))));
		t_sample min_438 = (-cell);
		t_sample lOut = ((l <= min_438) ? min_438 : ((l >= cell) ? cell : l));
		t_sample min_439 = (-cell);
		t_sample rOut = ((r <= min_439) ? min_439 : ((r >= cell) ? cell : r));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void tangenteHiperbolica_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_442 = (inl >= ((int)0));
		t_sample v_443 = (inl * lDrivePos);
		t_sample min_444 = (-cell);
		t_sample iftrue_445 = ((v_443 <= min_444) ? min_444 : ((v_443 >= cell) ? cell : v_443));
		t_sample v_446 = (inl * lDriveNeg);
		t_sample min_447 = (-cell);
		t_sample iffalse_448 = ((v_446 <= min_447) ? min_447 : ((v_446 >= cell) ? cell : v_446));
		t_sample l = (cond_442 ? iftrue_445 : iffalse_448);
		int cond_449 = (inr >= ((int)0));
		t_sample v_450 = (inr * rDrivePos);
		t_sample min_451 = (-cell);
		t_sample iftrue_452 = ((v_450 <= min_451) ? min_451 : ((v_450 >= cell) ? cell : v_450));
		t_sample v_453 = (inr * rDriveNeg);
		t_sample min_454 = (-cell);
		t_sample iffalse_455 = ((v_453 <= min_454) ? min_454 : ((v_453 >= cell) ? cell : v_453));
		t_sample r = (cond_449 ? iftrue_452 : iffalse_455);
		t_sample lOut = safediv(tanh(l), tanh(dr));
		t_sample rOut = safediv(tanh(r), tanh(dr));
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void rectH_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample maxa_458 = (inl * lDrivePos);
		t_sample lPositive = ((maxa_458 < ((int)0)) ? ((int)0) : maxa_458);
		t_sample maxa_459 = (inr * rDrivePos);
		t_sample rPositive = ((maxa_459 < ((int)0)) ? ((int)0) : maxa_459);
		t_sample v_460 = (lPositive * ((t_sample)0.5));
		t_sample min_461 = (-cell);
		t_sample l = ((v_460 <= min_461) ? min_461 : ((v_460 >= cell) ? cell : v_460));
		t_sample v_462 = (rPositive * ((t_sample)0.5));
		t_sample min_463 = (-cell);
		t_sample r = ((v_462 <= min_463) ? min_463 : ((v_462 >= cell) ? cell : v_462));
		out1 = l;
		out2 = r;
		
	};
	inline void arctangent_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_466 = (inl >= ((int)0));
		t_sample iftrue_467 = (inl * lDrivePos);
		t_sample iffalse_468 = (inl * lDriveNeg);
		t_sample lAdj = (cond_466 ? iftrue_467 : iffalse_468);
		int cond_469 = (inr >= ((int)0));
		t_sample iftrue_470 = (inr * rDrivePos);
		t_sample iffalse_471 = (inr * rDriveNeg);
		t_sample rAdj = (cond_469 ? iftrue_470 : iffalse_471);
		t_sample l = ((((int)2) * ((t_sample)0.31830988618379)) * atan((lAdj * ((int)2))));
		t_sample r = ((((int)2) * ((t_sample)0.31830988618379)) * atan((rAdj * ((int)2))));
		t_sample lOut = (l * cell);
		t_sample rOut = (r * cell);
		out1 = lOut;
		out2 = rOut;
		
	};
	inline void hardClip_d_d_d_d_d(t_sample inl, t_sample inr, t_sample dr, t_sample dc, t_sample cell, t_sample& out1, t_sample& out2) {
		t_sample lDrivePos = (dr * (((int)1) + dc));
		t_sample lDriveNeg = (dr * (((int)1) - dc));
		t_sample rDrivePos = (dr * (((int)1) + dc));
		t_sample rDriveNeg = (dr * (((int)1) - dc));
		int cond_474 = (inl >= ((int)0));
		t_sample iftrue_475 = (inl * lDrivePos);
		t_sample iffalse_476 = (inl * lDriveNeg);
		t_sample lDriven = (cond_474 ? iftrue_475 : iffalse_476);
		int cond_477 = (inr >= ((int)0));
		t_sample iftrue_478 = (inr * rDrivePos);
		t_sample iffalse_479 = (inr * rDriveNeg);
		t_sample rDriven = (cond_477 ? iftrue_478 : iffalse_479);
		int cond_480 = (lDriven > cell);
		int cond_481 = (lDriven < (-cell));
		t_sample iftrue_482 = (-cell);
		t_sample iffalse_483 = (cond_481 ? iftrue_482 : lDriven);
		t_sample l = (cond_480 ? cell : iffalse_483);
		int cond_484 = (rDriven > cell);
		int cond_485 = (rDriven < (-cell));
		t_sample iftrue_486 = (-cell);
		t_sample iffalse_487 = (cond_485 ? iftrue_486 : rDriven);
		t_sample r = (cond_484 ? cell : iffalse_487);
		out1 = l;
		out2 = r;
		
	};
	inline void bitCrusher_d_d_d(t_sample inl, t_sample inr, t_sample bits, t_sample& out1, t_sample& out2) {
		t_sample steps = (safepow(((int)2), bits) - ((int)1));
		t_sample invSteps = safediv(((int)1), steps);
		t_sample l = (round((inl * steps)) * invSteps);
		t_sample r = (round((inr * steps)) * invSteps);
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
int num_params() { return 26; }

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
		case 17: self->set_p_BANDSOLO(value); break;
		case 18: self->set_p_DISTON(value); break;
		case 19: self->set_p_SAFELIMITON(value); break;
		case 20: self->set_p_TILTPOS(value); break;
		case 21: self->set_q_TONEON(value); break;
		case 22: self->set_r_TONEFREQ(value); break;
		case 23: self->set_s_TILTON(value); break;
		case 24: self->set_t_TONEQ(value); break;
		case 25: self->set_u_TONEPOS(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_a_DRYWET_363; break;
		case 1: *value = self->m_b_DRIVE_362; break;
		case 2: *value = self->m_c_DC_361; break;
		case 3: *value = self->m_d_MODE_360; break;
		case 4: *value = self->m_e_CEILING_359; break;
		case 5: *value = self->m_f_BYPASS_358; break;
		case 6: *value = self->m_g_BITS_357; break;
		case 7: *value = self->m_h_BITSON_356; break;
		case 8: *value = self->m_i_TILT_355; break;
		case 9: *value = self->m_j_HPF_353; break;
		case 10: *value = self->m_k_INPUT_350; break;
		case 11: *value = self->m_k_LPF_352; break;
		case 12: *value = self->m_l_OUTPUT_349; break;
		case 13: *value = self->m_l_SC_351; break;
		case 14: *value = self->m_m_DOWNSAMPLE_348; break;
		case 15: *value = self->m_n_DOWNSAMPLEON_347; break;
		case 16: *value = self->m_o_BAND_346; break;
		case 17: *value = self->m_p_BANDSOLO_343; break;
		case 18: *value = self->m_p_DISTON_344; break;
		case 19: *value = self->m_p_SAFELIMITON_342; break;
		case 20: *value = self->m_p_TILTPOS_345; break;
		case 21: *value = self->m_q_TONEON_341; break;
		case 22: *value = self->m_r_TONEFREQ_340; break;
		case 23: *value = self->m_s_TILTON_354; break;
		case 24: *value = self->m_t_TONEQ_339; break;
		case 25: *value = self->m_u_TONEPOS_338; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(26 * sizeof(ParamInfo));
	self->__commonstate.numparams = 26;
	// initialize parameter 0 ("m_a_DRYWET_363")
	pi = self->__commonstate.params + 0;
	pi->name = "a_DRYWET";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_a_DRYWET_363;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_b_DRIVE_362")
	pi = self->__commonstate.params + 1;
	pi->name = "b_DRIVE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_b_DRIVE_362;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 50;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_c_DC_361")
	pi = self->__commonstate.params + 2;
	pi->name = "c_DC";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_c_DC_361;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_d_MODE_360")
	pi = self->__commonstate.params + 3;
	pi->name = "d_MODE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d_MODE_360;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 7;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_e_CEILING_359")
	pi = self->__commonstate.params + 4;
	pi->name = "e_CEILING";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_e_CEILING_359;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -20;
	pi->outputmax = 6;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_f_BYPASS_358")
	pi = self->__commonstate.params + 5;
	pi->name = "f_BYPASS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_f_BYPASS_358;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_g_BITS_357")
	pi = self->__commonstate.params + 6;
	pi->name = "g_BITS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_g_BITS_357;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 2;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_h_BITSON_356")
	pi = self->__commonstate.params + 7;
	pi->name = "h_BITSON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_h_BITSON_356;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_i_TILT_355")
	pi = self->__commonstate.params + 8;
	pi->name = "i_TILT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_i_TILT_355;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -6;
	pi->outputmax = 6;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_j_HPF_353")
	pi = self->__commonstate.params + 9;
	pi->name = "j_HPF";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_j_HPF_353;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 20;
	pi->outputmax = 1000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_k_INPUT_350")
	pi = self->__commonstate.params + 10;
	pi->name = "k_INPUT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_k_INPUT_350;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -12;
	pi->outputmax = 12;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_k_LPF_352")
	pi = self->__commonstate.params + 11;
	pi->name = "k_LPF";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_k_LPF_352;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1000;
	pi->outputmax = 20000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_l_OUTPUT_349")
	pi = self->__commonstate.params + 12;
	pi->name = "l_OUTPUT";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_l_OUTPUT_349;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -24;
	pi->outputmax = 12;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_l_SC_351")
	pi = self->__commonstate.params + 13;
	pi->name = "l_SC";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_l_SC_351;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_m_DOWNSAMPLE_348")
	pi = self->__commonstate.params + 14;
	pi->name = "m_DOWNSAMPLE";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_m_DOWNSAMPLE_348;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_n_DOWNSAMPLEON_347")
	pi = self->__commonstate.params + 15;
	pi->name = "n_DOWNSAMPLEON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_n_DOWNSAMPLEON_347;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 16 ("m_o_BAND_346")
	pi = self->__commonstate.params + 16;
	pi->name = "o_BAND";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_o_BAND_346;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_p_BANDSOLO_343")
	pi = self->__commonstate.params + 17;
	pi->name = "p_BANDSOLO";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_p_BANDSOLO_343;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_p_DISTON_344")
	pi = self->__commonstate.params + 18;
	pi->name = "p_DISTON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_p_DISTON_344;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 19 ("m_p_SAFELIMITON_342")
	pi = self->__commonstate.params + 19;
	pi->name = "p_SAFELIMITON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_p_SAFELIMITON_342;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 20 ("m_p_TILTPOS_345")
	pi = self->__commonstate.params + 20;
	pi->name = "p_TILTPOS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_p_TILTPOS_345;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 21 ("m_q_TONEON_341")
	pi = self->__commonstate.params + 21;
	pi->name = "q_TONEON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_q_TONEON_341;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 22 ("m_r_TONEFREQ_340")
	pi = self->__commonstate.params + 22;
	pi->name = "r_TONEFREQ";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_r_TONEFREQ_340;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 20;
	pi->outputmax = 20000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 23 ("m_s_TILTON_354")
	pi = self->__commonstate.params + 23;
	pi->name = "s_TILTON";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_s_TILTON_354;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 24 ("m_t_TONEQ_339")
	pi = self->__commonstate.params + 24;
	pi->name = "t_TONEQ";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_t_TONEQ_339;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.70710678118655;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 25 ("m_u_TONEPOS_338")
	pi = self->__commonstate.params + 25;
	pi->name = "u_TONEPOS";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_u_TONEPOS_338;
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

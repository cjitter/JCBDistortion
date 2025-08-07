{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 9,
			"minor" : 0,
			"revision" : 7,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 42.0, 87.0, 1833.0, 887.0 ],
		"gridsize" : [ 15.0, 15.0 ],
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-77",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 255.0, 148.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-78",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 255.0, 179.0, 65.0, 22.0 ],
					"text" : "modout $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-79",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 320.0, 119.0, 21.0, 21.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-81",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 226.0, 118.0, 88.0, 22.0 ],
					"text" : "open, loop 1, 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-84",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 3,
					"outlettype" : [ "signal", "signal", "bang" ],
					"patching_rect" : [ 227.0, 234.0, 121.0, 22.0 ],
					"text" : "sfplay~ 2"
				}

			}
, 			{
				"box" : 				{
					"activedialcolor" : [ 0.242201021442454, 0.242200956343583, 0.242200973354958, 1.0 ],
					"activeneedlecolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"appearance" : 3,
					"dialcolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"fgdialcolor" : [ 0.768399306904929, 0.768399117237748, 0.7683991666346, 1.0 ],
					"fontsize" : 14.0,
					"id" : "obj-122",
					"maxclass" : "live.dial",
					"needlecolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1589.0, 460.0, 75.0, 74.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 717.0, 15.0, 75.0, 74.0 ],
					"saved_attribute_attributes" : 					{
						"activedialcolor" : 						{
							"expression" : "themecolor.live_value_arc_zombie"
						}
,
						"activeneedlecolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"dialcolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"fgdialcolor" : 						{
							"expression" : "themecolor.live_lcd_title"
						}
,
						"needlecolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"textcolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"valueof" : 						{
							"parameter_exponent" : 4.0,
							"parameter_initial" : [ 20000 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "LPF",
							"parameter_mmax" : 20000.0,
							"parameter_mmin" : 20.0,
							"parameter_modmode" : 3,
							"parameter_shortname" : "LPF",
							"parameter_type" : 0,
							"parameter_unitstyle" : 3
						}

					}
,
					"textcolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"varname" : "LPF"
				}

			}
, 			{
				"box" : 				{
					"activedialcolor" : [ 0.242201021442454, 0.242200956343583, 0.242200973354958, 1.0 ],
					"activeneedlecolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"appearance" : 3,
					"fontsize" : 14.0,
					"id" : "obj-121",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 1345.0, 462.0, 75.0, 74.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 556.0, 15.0, 75.0, 74.0 ],
					"saved_attribute_attributes" : 					{
						"activedialcolor" : 						{
							"expression" : "themecolor.live_value_arc_zombie"
						}
,
						"activeneedlecolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"textcolor" : 						{
							"expression" : "themecolor.live_output_curve_outline_color"
						}
,
						"valueof" : 						{
							"parameter_exponent" : 4.0,
							"parameter_initial" : [ 20 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "HPF",
							"parameter_mmax" : 20000.0,
							"parameter_mmin" : 20.0,
							"parameter_modmode" : 3,
							"parameter_shortname" : "HPF",
							"parameter_type" : 0,
							"parameter_unitstyle" : 3
						}

					}
,
					"textcolor" : [ 0.811764705882353, 0.811764705882353, 0.811764705882353, 1.0 ],
					"varname" : "live.dial[11]"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-74",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1589.0, 558.0, 68.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-71",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1345.0, 558.0, 64.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-63",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1482.0, 697.0, 51.0, 22.0 ],
					"text" : "s parms"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-62",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1483.0, 463.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-57",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1483.0, 493.0, 51.0, 22.0 ],
					"text" : "l_SC $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-49",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1589.0, 591.0, 60.0, 22.0 ],
					"presentation_linecount" : 2,
					"text" : "k_LPF $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-36",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1345.0, 591.0, 59.0, 22.0 ],
					"text" : "j_HPF $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-32",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 746.0, 790.0, 648.0, 60.0 ],
					"text" : "// Parámetros de filtros HPF/LPF\nParam j_HPF(20, min=20, default=20, max=20000);       // Input HPF frequency (Hz)\nParam k_LPF(20000, min=20, default=20000, max=20000); // Input LPF frequency (Hz)\nParam l_SC(0, min=0, default=0, max=1);               // Input filter enable"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-13",
					"maxclass" : "flonum",
					"maximum" : 100.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1006.0, 245.0, 103.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-29",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1005.0, 273.0, 129.0, 22.0 ],
					"text" : "m_DOWNSAMPLE $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 852.0, 244.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 852.0, 273.0, 143.0, 22.0 ],
					"text" : "n_DOWNSAMPLEON $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-80",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 39.0, 244.0, 49.0, 22.0 ],
					"text" : "r parms"
				}

			}
, 			{
				"box" : 				{
					"compatibility" : 1,
					"contdata" : 1,
					"id" : "obj-73",
					"maxclass" : "multislider",
					"numinlets" : 1,
					"numoutlets" : 2,
					"orientation" : 0,
					"outlettype" : [ "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1150.0, 129.0, 158.0, 35.0 ],
					"setminmax" : [ 0.0, 7.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-69",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 918.0, 457.0, 80.0, 13.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-64",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "signal" ],
					"patching_rect" : [ 745.0, 514.0, 82.0, 22.0 ],
					"text" : "adoutput~ 1 2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-60",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 745.0, 457.0, 80.0, 13.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-47",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1262.0, 29.0, 29.5, 22.0 ],
					"text" : "7"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-45",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1231.0, 29.0, 29.5, 22.0 ],
					"text" : "6"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-42",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1197.0, 29.0, 29.5, 22.0 ],
					"text" : "5"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-37",
					"maxclass" : "flonum",
					"maximum" : 12.0,
					"minimum" : -12.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1410.0, 69.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-40",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1410.0, 98.0, 84.0, 22.0 ],
					"text" : "l_OUTPUT $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-31",
					"maxclass" : "flonum",
					"maximum" : 12.0,
					"minimum" : -12.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 531.0, 89.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-28",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 531.0, 134.0, 74.0, 22.0 ],
					"text" : "k_INPUT $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-55",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1038.0, 29.0, 29.5, 22.0 ],
					"text" : "0"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-48",
					"maxclass" : "flonum",
					"maximum" : 11.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1150.0, 174.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.33, 0.33, 0.33, 1.0 ],
					"id" : "obj-25",
					"margins" : [ 1.0, 0.0, 1.0, 0.0 ],
					"maxclass" : "plot~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"numpoints" : 441,
					"outlettype" : [ "" ],
					"patching_rect" : [ 745.0, 560.0, 276.0, 219.0 ],
					"prototypename" : "Audio Scope - Light",
					"subplots" : [ 						{
							"color" : [ 0.100000001490116, 0.899999976158142, 0.100000001490116, 1.0 ],
							"thickness" : 1.200000047683716,
							"point_style" : "none",
							"line_style" : "lines",
							"number_style" : "none",
							"filter" : "none",
							"domain_start" : 0.0,
							"domain_end" : 1.0,
							"domain_style" : "linear",
							"domain_markers" : [ 0.0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875, 1.0 ],
							"domain_labels" : [  ],
							"range_start" : -1.0,
							"range_end" : 1.0,
							"range_style" : "linear",
							"range_markers" : [ -0.5, 0.0, 0.5 ],
							"range_labels" : [  ],
							"origin_x" : 0.0,
							"origin_y" : 0.0
						}
 ]
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-61",
					"maxclass" : "flonum",
					"maximum" : 6.0,
					"minimum" : -6.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 764.0, 88.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-58",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 764.0, 135.0, 58.0, 22.0 ],
					"text" : "i_TILT $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-53",
					"maxclass" : "flonum",
					"maximum" : 16.0,
					"minimum" : 3.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 955.0, 145.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-35",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 955.0, 192.0, 65.0, 22.0 ],
					"text" : "g_BITS $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-27",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1028.0, 145.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-33",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1028.0, 192.0, 83.0, 22.0 ],
					"text" : "h_BITSON $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 414.0, 457.0, 80.0, 13.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-23",
					"maxclass" : "meter~",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 245.0, 457.0, 80.0, 13.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-21",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1164.0, 29.0, 29.5, 22.0 ],
					"text" : "4"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-17",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1132.0, 29.0, 29.5, 22.0 ],
					"text" : "3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1101.0, 29.0, 29.5, 22.0 ],
					"text" : "2"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-8",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1069.0, 29.0, 29.5, 22.0 ],
					"text" : "1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-52",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1326.0, 68.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-50",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1326.0, 98.0, 82.0, 22.0 ],
					"text" : "f_BYPASS $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-26",
					"maxclass" : "flonum",
					"maximum" : 6.0,
					"minimum" : -20.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 832.0, 88.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-22",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 832.0, 135.0, 87.0, 22.0 ],
					"text" : "e_CEILING $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-1",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1150.0, 207.0, 75.0, 22.0 ],
					"text" : "d_MODE $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-19",
					"logfreq" : 1,
					"maxclass" : "spectroscope~",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 437.0, 665.0, 139.0, 114.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-16",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 520.0, 566.0, 47.0, 22.0 ],
					"text" : "gate~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-18",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 520.0, 616.0, 40.0, 22.0 ],
					"text" : "*~ 0.1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 125.0, 52.0, 68.0, 22.0 ],
					"text" : "exportcode"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-101",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 437.0, 134.0, 90.0, 22.0 ],
					"text" : "a_DRYWET $1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-95",
					"maxclass" : "flonum",
					"maximum" : 1.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 437.0, 88.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-93",
					"maxclass" : "flonum",
					"maximum" : 1.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 696.0, 88.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-87",
					"maxclass" : "flonum",
					"maximum" : 50.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 611.0, 88.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-15",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 370.0, 478.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-12",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 198.0, 572.0, 47.0, 22.0 ],
					"text" : "gate~"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-44",
					"maxclass" : "flonum",
					"maximum" : 1.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 370.0, 572.0, 50.0, 22.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_initial" : [ 0.25 ],
							"parameter_initial_enable" : 1,
							"parameter_longname" : "number",
							"parameter_mmax" : 1.0,
							"parameter_modmode" : 3,
							"parameter_shortname" : "number",
							"parameter_type" : 0
						}

					}
,
					"varname" : "number"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-11",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 696.0, 135.0, 55.0, 22.0 ],
					"text" : "c_DC $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 611.0, 135.0, 75.0, 22.0 ],
					"text" : "b_DRIVE $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-5",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 352.0, 673.0, 45.0, 45.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-4",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 198.0, 616.0, 40.0, 22.0 ],
					"text" : "*~ 0.1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-3",
					"logfreq" : 1,
					"maxclass" : "spectroscope~",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 173.0, 665.0, 139.0, 114.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 5,
					"outlettype" : [ "signal", "signal", "signal", "signal", "signal" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 9,
							"minor" : 0,
							"revision" : 7,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "dsp.gen",
						"rect" : [ 308.0, 87.0, 939.0, 903.0 ],
						"gridsize" : [ 15.0, 15.0 ],
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-8",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 436.0, 846.0, 35.0, 22.0 ],
									"text" : "out 3"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-7",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 839.0, 853.0, 35.0, 22.0 ],
									"text" : "out 5"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-6",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 638.0, 846.0, 35.0, 22.0 ],
									"text" : "out 4"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-5",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 235.0, 853.0, 35.0, 22.0 ],
									"text" : "out 2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 33.0, 14.0, 28.0, 22.0 ],
									"text" : "in 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-2",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 839.0, 14.0, 28.0, 22.0 ],
									"text" : "in 2"
								}

							}
, 							{
								"box" : 								{
									"code" : "// =============================================================================\n// MULTI-ALGORITHM DISTORTION WITH SIMPLE WORKING FILTERS\n// =============================================================================\n// Plugin de distorsión con múltiples algoritmos y morphing continuo\n// Filtros HPF/LPF simples que funcionan correctamente\n// Dry/Wet mezcla señal original (pre-trim) con señal completamente procesada\n// =============================================================================\n\n// -----------------------------------------------------------------------------\n// FUNCIONES DE DISTORSIÓN (en orden de modo)\n// -----------------------------------------------------------------------------\n\n// MODO 0 - Soft Clipping - Saturación suave con función cúbica\nsoftclip(inl, inr, dr, dc, cell) {\n    // Añadir DC offset para generar asimetría (armónicos pares)\n    lWithDC = inl + (dc * 0.05);\n    rWithDC = inr + (dc * 0.05);\n    \n    // Aplicar drive y normalizar\n    lNorm = (lWithDC * dr) / cell;\n    rNorm = (rWithDC * dr) / cell;\n    \n    lCubic = lNorm - (lNorm * lNorm * lNorm) / 3;\n    rCubic = rNorm - (rNorm * rNorm * rNorm) / 3;\n    \n    lLimited = sign(lNorm) * (2.0 / 3.0);\n    rLimited = sign(rNorm) * (2.0 / 3.0);\n    \n    lOut = (abs(lNorm) <= 1) ? lCubic : lLimited;\n    rOut = (abs(rNorm) <= 1) ? rCubic : rLimited;\n    \n    return lOut * cell, rOut * cell;\n}\n\n// MODO 1 - Sigmoid - Curva en S para saturación suave\nsigmoid(inl, inr, dr, dc, cell) {\n    // Añadir DC offset para generar asimetría\n    lWithDC = inl + (dc * 0.05);\n    rWithDC = inr + (dc * 0.05);\n    \n    factor = (-1) * dr;\n    l = (2 * (1 / (1 + exp(factor * lWithDC)))) - 1;\n    r = (2 * (1 / (1 + exp(factor * rWithDC)))) - 1;\n    \n    // Aplicar ceiling para limitar la salida\n    lOut = clip(l * cell, -cell, cell);\n    rOut = clip(r * cell, -cell, cell);\n    \n    return lOut, rOut;\n}\n\n// MODO 2 - Rectificador Full Wave - Bipolar con compensación de ganancia\nrectF(inl, inr, dr, dc, cell) {\n    // Añadir DC offset para cambiar el punto de rectificación\n    lWithDC = inl + (dc * 0.05);\n    rWithDC = inr + (dc * 0.05);\n    \n    l = sign(lWithDC) * abs(lWithDC * dr) * 0.707;\n    r = sign(rWithDC) * abs(rWithDC * dr) * 0.707;\n    lOut = clip(l, -cell, cell);\n    rOut = clip(r, -cell, cell);\n    return lOut, rOut;\n}\n\n// MODO 3 - Fuzz Exponencial 1 - Distorsión tipo fuzz con curva exponencial\nfuzzExp1(inl, inr, dr, dc, cell) {\n    // Añadir DC offset ANTES del procesamiento para generar asimetría\n    lWithDC = inl + (dc * 0.05);\n    rWithDC = inr + (dc * 0.05);\n    \n    signl = sign(lWithDC);\n    signr = sign(rWithDC);\n    \n    lScaled = abs(lWithDC * dr);\n    rScaled = abs(rWithDC * dr);\n    \n    l = signl * (1 - exp(-lScaled));\n    r = signr * (1 - exp(-rScaled));\n    \n    lOut = clip(l, -cell, cell);\n    rOut = clip(r, -cell, cell);\n    return lOut, rOut;\n}\n\n// MODO 4 - Tangente Hiperbólica - Distorsión suave tipo saturación de cinta\ntangenteHiperbolica(inl, inr, dr, dc, cell) {\n    // Añadir DC offset para generar asimetría\n    lWithDC = inl + (dc * 0.05);\n    rWithDC = inr + (dc * 0.05);\n    \n    l = clip(lWithDC * dr, -cell, cell);\n    r = clip(rWithDC * dr, -cell, cell);\n    lOut = (tanh(l)) / (tanh(dr));\n    rOut = (tanh(r)) / (tanh(dr));\n    return lOut, rOut;\n}\n\n// MODO 5 - Rectificador Half Wave - Solo valores positivos\nrectH(inl, inr, dr, dc, cell) {\n    // Añadir DC offset para cambiar el punto de rectificación\n    lWithDC = inl + (dc * 0.05);\n    rWithDC = inr + (dc * 0.05);\n    \n    lPositive = max(lWithDC, 0);\n    rPositive = max(rWithDC, 0);\n    l = clip((lPositive * dr) * 0.5, -cell, cell);\n    r = clip((rPositive * dr) * 0.5, -cell, cell);\n    return l, r;\n}\n\n// MODO 6 - Arctangente puro - Distorsión suave con compresión natural\narctangent(inl, inr, dr, dc, cell) {\n    // Añadir DC offset para generar asimetría\n    lWithDC = inl + (dc * 0.05);\n    rWithDC = inr + (dc * 0.05);\n    \n    lScaled = lWithDC * dr * 2;\n    rScaled = rWithDC * dr * 2;\n    \n    l = (2 / pi) * atan(lScaled);\n    r = (2 / pi) * atan(rScaled);\n    \n    lOut = l * cell;\n    rOut = r * cell;\n    \n    return lOut, rOut;\n}\n\n// MODO 7 - Hard Clip - Recorte abrupto de la señal\nhardClip(inl, inr, dr, dc, cell) {\n    // Añadir DC offset para generar asimetría\n    lWithDC = inl + (dc * 0.05);\n    rWithDC = inr + (dc * 0.05);\n    \n    // Aplicar drive y calcular threshold\n    lDriven = lWithDC * dr;\n    rDriven = rWithDC * dr;\n    \n    // Clipear a ±cell\n    l = (lDriven > cell) ? cell : ((lDriven < -cell) ? -cell : lDriven);\n    r = (rDriven > cell) ? cell : ((rDriven < -cell) ? -cell : rDriven);\n    \n    return l, r;\n}\n\n// Bit Crusher - Reduce la resolución de bits\nbitCrusher(inl, inr, bits) {\n    steps = pow(2, bits) - 1;\n    invSteps = 1 / steps;\n    l = ceil(inl * steps) * invSteps;\n    r = ceil(inr * steps) * invSteps;\n    return l, r;\n}\n\n// -----------------------------------------------------------------------------\n// PARÁMETROS\n// -----------------------------------------------------------------------------\nParam a_DRYWET(1, min=0, default=1, max=1);\nParam b_DRIVE(1, min=1, default=1, max=50);\nParam c_DC(0, min=0, default=0, max=1);         // DC offset - añade armónicos pares (asimetría)\nParam d_MODE(1, min=0, default=0, max=7);       // Continuo 0-7 (8 algoritmos)\nParam e_CEILING(0, min=-20, default=0, max=6);\nParam f_BYPASS(0, min=0, default=0, max=1);\nParam g_BITS(16, min=3, default=16, max=16);\nParam h_BITSON(0, min=0, default=0, max=1);\nParam i_TILT(0, min=-6, default=0, max=6);\n\n// Parámetros de filtros HPF/LPF\nParam j_HPF(20, min=20, default=20, max=20000);       // Input HPF frequency (Hz)\nParam k_LPF(20000, min=20, default=20000, max=20000); // Input LPF frequency (Hz)\nParam l_SC(0, min=0, default=0, max=1);               // Input filter enable\n\n// Parámetros existentes\nParam k_INPUT(0, min=-12, default=0, max=12);   // Input trim gain\nParam l_OUTPUT(0, min=-12, default=0, max=12);  // Output makeup gain\nParam m_DOWNSAMPLE(0, min=0, default=0, max=99); // Factor de downsampling (0 = sin efecto)\nParam n_DOWNSAMPLEON(0, min=0, default=0, max=1); // Activar downsampling\n\n// -----------------------------------------------------------------------------\n// HISTORIALES PARA SMOOTHING\n// -----------------------------------------------------------------------------\nHistory hDrive(0);\nHistory hDc(0);\nHistory hDrywet(0);\nHistory hBits(0);\nHistory hBitson(0);\nHistory hTilt(0);\nHistory hInput(0);\nHistory hOutput(0);\nHistory hMode(0);     // Para suavizar cambios de modo\n\nHistory hDownsample(0); // Para suavizar factor de downsampling\nHistory hDownsampleOn(0); // Para suavizar activación de downsampling\nHistory hBypass(0);   // Para suavizar bypass y evitar clicks\n\n// Historiales para filtros de 1 polo (más simples)\nHistory hpfL_z1(0);\nHistory hpfR_z1(0);\nHistory lpfL_z1(0);\nHistory lpfR_z1(0);\n\n// Historiales para smoothing de filtros\nHistory hpfFreqHistory(0);\nHistory lpfFreqHistory(0);\nHistory scEnableHistory(0);\n\n// Historiales para el downsampler\nHistory dsCounter(0);\nHistory dsHeldL(0);\nHistory dsHeldR(0);\n\n// Historiales para filtros Tilt\nHistory tiltL1(0), tiltL2(0), tiltL3(0), tiltL4(0);\nHistory tiltR1(0), tiltR2(0), tiltR3(0), tiltR4(0);\n\n// -----------------------------------------------------------------------------\n// PROCESAMIENTO PRINCIPAL\n// -----------------------------------------------------------------------------\n\n// Entrada\nlIn = in1;\nrIn = in2;\n\n// Smoothing de parámetros\nsmoothFactor = 0.999;\nhDrive = hDrive * smoothFactor + b_DRIVE * (1 - smoothFactor);\ndrive = hDrive;\nhDc = hDc * smoothFactor + c_DC * (1 - smoothFactor);\ndc = hDc;\nhDrywet = hDrywet * smoothFactor + a_DRYWET * (1 - smoothFactor);\ndrywet = hDrywet;\nhBits = hBits * smoothFactor + g_BITS * (1 - smoothFactor);\nbits = hBits;\nhBitson = hBitson * smoothFactor + h_BITSON * (1 - smoothFactor);\nbitson = hBitson;\nhTilt = hTilt * smoothFactor + i_TILT * (1 - smoothFactor);\ntiltDb = hTilt;\nhInput = hInput * smoothFactor + k_INPUT * (1 - smoothFactor);\ninputTrimDb = hInput;\nhOutput = hOutput * smoothFactor + l_OUTPUT * (1 - smoothFactor);\noutputMakeupDb = hOutput;\n\n// Suavizado especial para MODE con factor más agresivo para evitar clicks\nmodeSmoothFactor = 0.99;  // Más rápido que otros parámetros pero aún suave\nhMode = hMode * modeSmoothFactor + d_MODE * (1 - modeSmoothFactor);\nsmoothedMode = hMode;\n\n// Suavizado del downsampling\nhDownsample = hDownsample * smoothFactor + m_DOWNSAMPLE * (1 - smoothFactor);\nhDownsampleOn = hDownsampleOn * smoothFactor + n_DOWNSAMPLEON * (1 - smoothFactor);\ndownsampleOn = hDownsampleOn;\n\n// Suavizado del bypass\nhBypass = hBypass * smoothFactor + (1 - f_BYPASS) * (1 - smoothFactor);\nbypass = hBypass;\n\n// Suavizado de parámetros de filtros\nsmoothHpfFreq = (hpfFreqHistory * smoothFactor) + (j_HPF * (1 - smoothFactor));\nhpfFreqHistory = fixdenorm(smoothHpfFreq);\n\nsmoothLpfFreq = (lpfFreqHistory * smoothFactor) + (k_LPF * (1 - smoothFactor));\nlpfFreqHistory = fixdenorm(smoothLpfFreq);\n\nsmoothScEnable = (scEnableHistory * smoothFactor) + (l_SC * (1 - smoothFactor));\nscEnableHistory = fixdenorm(smoothScEnable);\n\n// Conversiones\nceiling = dbtoa(e_CEILING);\ninputTrimLinear = dbtoa(inputTrimDb);\noutputMakeupLinear = dbtoa(outputMakeupDb);\n\n// -----------------------------------------------------------------------------\n// INPUT TRIM\n// -----------------------------------------------------------------------------\nlTrimmed = lIn * inputTrimLinear;\nrTrimmed = rIn * inputTrimLinear;\n\n// -----------------------------------------------------------------------------\n// FILTROS DE 1 POLO SIMPLES (6 dB/oct)\n// -----------------------------------------------------------------------------\n// Estos filtros son más simples y siempre funcionan\n\n// Coeficiente HPF (1 polo)\nhpf_freq = clip(smoothHpfFreq, 20, 20000);\nhpf_coeff = exp(-2 * pi * hpf_freq / samplerate);\n\n// Procesamiento HPF\nhpfL_out = lTrimmed - hpfL_z1;\nhpfL_z1 = lTrimmed - (hpfL_out * hpf_coeff);\n\nhpfR_out = rTrimmed - hpfR_z1;\nhpfR_z1 = rTrimmed - (hpfR_out * hpf_coeff);\n\n// Coeficiente LPF (1 polo)\nlpf_freq = clip(smoothLpfFreq, 20, 20000);\nlpf_coeff = 2 * pi * lpf_freq / samplerate;\nlpf_coeff = clip(lpf_coeff, 0, 1);\n\n// Procesamiento LPF (aplicado a la salida del HPF)\nlpfL_z1 = lpfL_z1 + lpf_coeff * (hpfL_out - lpfL_z1);\nlpfR_z1 = lpfR_z1 + lpf_coeff * (hpfR_out - lpfR_z1);\n\n// Señal filtrada\nfilteredL = lpfL_z1;\nfilteredR = lpfR_z1;\n\n// Mezclar señal filtrada con original según filter enable\nlFiltered = mix(lTrimmed, filteredL, smoothScEnable);\nrFiltered = mix(rTrimmed, filteredR, smoothScEnable);\n\n// -----------------------------------------------------------------------------\n// FILTRO TILT PRE-DISTORSIÓN\n// -----------------------------------------------------------------------------\nfc = 800.0;\nq = 0.7071;\n\n// Cálculo de coeficientes para Tilt (invertido para UI intuitiva)\ntiltGain = dbtoa(-tiltDb);\nomega = (fc * twopi) / samplerate;\nsn = sin(omega);\ncs = cos(omega);\nA = sqrt(tiltGain);\nbeta = sqrt((A * A + 1) / q - (A - 1) * (A - 1));\n\n// Coeficientes Low Shelf\nb0Ls = 1 / ((A + 1) + (A - 1) * cs + beta * sn);\na0Ls = A * ((A + 1) - (A - 1) * cs + beta * sn) * b0Ls;\na1Ls = 2 * A * ((A - 1) - (A + 1) * cs) * b0Ls;\na2Ls = A * ((A + 1) - (A - 1) * cs - beta * sn) * b0Ls;\nb1Ls = -2 * ((A - 1) + (A + 1) * cs) * b0Ls;\nb2Ls = ((A + 1) + (A - 1) * cs - beta * sn) * b0Ls;\n\n// Aplicar Low Shelf\nlLs = a0Ls * lFiltered + a1Ls * tiltL2 + a2Ls * tiltL1 - b1Ls * tiltL4 - b2Ls * tiltL3;\ntiltL1 = tiltL2;\ntiltL2 = lFiltered;\ntiltL3 = tiltL4;\ntiltL4 = lLs;\n\nrLs = a0Ls * rFiltered + a1Ls * tiltR2 + a2Ls * tiltR1 - b1Ls * tiltR4 - b2Ls * tiltR3;\ntiltR1 = tiltR2;\ntiltR2 = rFiltered;\ntiltR3 = tiltR4;\ntiltR4 = rLs;\n\n// Coeficientes High Shelf\naInv = sqrt(1/tiltGain);\nbetaHs = sqrt((aInv * aInv + 1) / q - (aInv - 1) * (aInv - 1));\n\nb0Hs = 1 / ((aInv + 1) - (aInv - 1) * cs + betaHs * sn);\na0Hs = aInv * ((aInv + 1) + (aInv - 1) * cs + betaHs * sn) * b0Hs;\na1Hs = -2 * aInv * ((aInv - 1) + (aInv + 1) * cs) * b0Hs;\na2Hs = aInv * ((aInv + 1) + (aInv - 1) * cs - betaHs * sn) * b0Hs;\nb1Hs = 2 * ((aInv - 1) - (aInv + 1) * cs) * b0Hs;\nb2Hs = ((aInv + 1) - (aInv - 1) * cs - betaHs * sn) * b0Hs;\n\nlTilt = a0Hs * lLs + a1Hs * tiltL2 + a2Hs * tiltL1 - b1Hs * tiltL4 - b2Hs * tiltL3;\nrTilt = a0Hs * rLs + a1Hs * tiltR2 + a2Hs * tiltR1 - b1Hs * tiltR4 - b2Hs * tiltR3;\n\n// -----------------------------------------------------------------------------\n// PROCESAMIENTO DE DISTORSIÓN CON MORPHING\n// -----------------------------------------------------------------------------\n\n// Ejecutar TODOS los algoritmos con implementación consistente de DC\nsoftL, softR = softclip(lTilt, rTilt, drive, dc, ceiling);\nsigmL, sigmR = sigmoid(lTilt, rTilt, drive, dc, ceiling);\nrectL, rectR = rectF(lTilt, rTilt, drive, dc, ceiling);\nfuzz1L, fuzz1R = fuzzExp1(lTilt, rTilt, drive, dc, ceiling);\ntanhL, tanhR = tangenteHiperbolica(lTilt, rTilt, drive, dc, ceiling);\nrecthL, recthR = rectH(lTilt, rTilt, drive, dc, ceiling);\natanL, atanR = arctangent(lTilt, rTilt, drive, dc, ceiling);\nhardL, hardR = hardClip(lTilt, rTilt, drive, dc, ceiling);\n\n// Sistema de morphing continuo\nmode = smoothedMode;  // Usar el modo suavizado\n\n// Calcular pesos (ahora solo 8 algoritmos)\nw0 = max(0, 1 - abs(mode - 0));      // Softclip\nw1 = max(0, 1 - abs(mode - 1));      // Sigmoid\nw2 = max(0, 1 - abs(mode - 2));      // RectF\nw3 = max(0, 1 - abs(mode - 3));      // Fuzz1\nw4 = max(0, 1 - abs(mode - 4));      // TanH\nw5 = max(0, 1 - abs(mode - 5));      // RectH\nw6 = max(0, 1 - abs(mode - 6));      // Arctangent\nw7 = max(0, 1 - abs(mode - 7));      // HardClip\n\n// Normalizar pesos\nsumWeights = w0 + w1 + w2 + w3 + w4 + w5 + w6 + w7 + 0.0001;\nw0 /= sumWeights; w1 /= sumWeights; w2 /= sumWeights; w3 /= sumWeights;\nw4 /= sumWeights; w5 /= sumWeights; w6 /= sumWeights; w7 /= sumWeights;\n\n// Mezclar algoritmos\ndistL = softL * w0 + sigmL * w1 + rectL * w2 + fuzz1L * w3 +\n        tanhL * w4 + recthL * w5 + atanL * w6 + hardL * w7;\n\ndistR = softR * w0 + sigmR * w1 + rectR * w2 + fuzz1R * w3 +\n        tanhR * w4 + recthR * w5 + atanR * w6 + hardR * w7;\n\n// DC Blocker\nprocessedL = dcblock(distL);\nprocessedR = dcblock(distR);\n\n// -----------------------------------------------------------------------------\n// BIT CRUSHER Y DOWNSAMPLING OPCIONAL (ANTES DEL DRY/WET)\n// -----------------------------------------------------------------------------\n// Bit Crusher\nbitL, bitR = bitCrusher(processedL, processedR, bits);\nbcL = dcblock(bitL);\nbcR = dcblock(bitR);\n\nwithBitCrusherL = mix(processedL, bcL, bitson);\nwithBitCrusherR = mix(processedR, bcR, bitson);\n\n// Downsampling simple\n// Incrementar contador\ndsCounter = dsCounter + 1;\n\n// Calcular cuántas muestras saltar (0 = ninguna, 99 = saltar 99)\nskipSamples = floor(hDownsample) + 1;\n\n// Si es momento de tomar nueva muestra o no hay downsampling\nif (dsCounter >= skipSamples || hDownsample < 0.5) {\n    dsHeldL = withBitCrusherL;\n    dsHeldR = withBitCrusherR;\n    dsCounter = 0;\n}\n\n// Aplicar downsampling\nwetFinalL = mix(withBitCrusherL, dsHeldL, downsampleOn);\nwetFinalR = mix(withBitCrusherR, dsHeldR, downsampleOn);\n\n// -----------------------------------------------------------------------------\n// OUTPUT MAKEUP (SOLO A LA SEÑAL WET)\n// -----------------------------------------------------------------------------\n// Aplicar makeup gain ANTES del dry/wet para que solo afecte a la señal procesada\nwetWithMakeupL = wetFinalL * outputMakeupLinear;\nwetWithMakeupR = wetFinalR * outputMakeupLinear;\n\n// -----------------------------------------------------------------------------\n// MEZCLA DRY/WET\n// -----------------------------------------------------------------------------\n// Dry = señal original sin procesar (pre-trim, pre-filtros)\n// Wet = señal completamente procesada (trim + filtros + tilt + distorsión + efectos + makeup)\n// Parámetro drywet: 0 = solo dry, 1 = solo wet\nmixedL = mix(lIn, wetWithMakeupL, drywet);\nmixedR = mix(rIn, wetWithMakeupR, drywet);\n\n// -----------------------------------------------------------------------------\n// SALIDA FINAL CON BYPASS\n// -----------------------------------------------------------------------------\n// Ya no aplicamos makeup aquí porque ya está en la señal wet\nfinalL = mixedL;\nfinalR = mixedR;\n\n// DC Blocker final antes de la salida\nfinalDcBlockedL = dcblock(finalL);\nfinalDcBlockedR = dcblock(finalR);\n\n// Salidas principales\nout1 = mix(lIn, finalDcBlockedL, bypass);\nout2 = mix(rIn, finalDcBlockedR, bypass);\n\n// Salida 3 vacía para mantener consistencia\nout3 = 0;\n\n// Salidas post Input Trim (para medidores)\nout4 = lTrimmed;  // L post trim\nout5 = rTrimmed;  // R post trim\n",
									"fontface" : 0,
									"fontname" : "<Monospaced>",
									"fontsize" : 12.0,
									"id" : "obj-3",
									"maxclass" : "codebox",
									"numinlets" : 2,
									"numoutlets" : 5,
									"outlettype" : [ "", "", "", "", "" ],
									"patching_rect" : [ 33.0, 56.0, 825.0, 776.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-4",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 33.0, 846.0, 35.0, 22.0 ],
									"text" : "out 1"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 0 ],
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-3", 1 ],
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 0 ],
									"source" : [ "obj-3", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"source" : [ "obj-3", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"source" : [ "obj-3", 3 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-7", 0 ],
									"source" : [ "obj-3", 4 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-3", 2 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 226.0, 419.0, 711.5, 22.0 ],
					"saved_object_attributes" : 					{
						"autoexport" : 0,
						"exportfolder" : "Sequoia:/Users/jcb/JUCEProjects/JCBDistortion/exported-code/"
					}
,
					"text" : "gen~ @title JCBDistortion @autoexport 0"
				}

			}
, 			{
				"box" : 				{
					"attr" : "exportfolder",
					"id" : "obj-43",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 102.0, 19.0, 458.0, 22.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 1159.5, 389.0, 235.5, 389.0 ],
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 861.5, 357.0, 235.5, 357.0 ],
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 446.5, 389.0, 235.5, 389.0 ],
					"source" : [ "obj-101", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 705.5, 389.0, 235.5, 389.0 ],
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-71", 0 ],
					"source" : [ "obj-121", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-74", 0 ],
					"source" : [ "obj-122", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-29", 0 ],
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1110.5, 108.0, 1159.5, 108.0 ],
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"midpoints" : [ 379.5, 549.0, 207.5, 549.0 ],
					"order" : 1,
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"midpoints" : [ 379.5, 549.0, 529.5, 549.0 ],
					"order" : 0,
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1141.5, 108.0, 1159.5, 108.0 ],
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 1 ],
					"midpoints" : [ 529.5, 653.04296875, 387.5, 653.04296875 ],
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 1 ],
					"order" : 1,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 1 ],
					"midpoints" : [ 408.625, 521.0, 557.5, 521.0 ],
					"order" : 0,
					"source" : [ "obj-2", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-19", 0 ],
					"midpoints" : [ 408.625, 517.953125, 446.5, 517.953125 ],
					"order" : 1,
					"source" : [ "obj-2", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"midpoints" : [ 235.5, 448.0, 254.5, 448.0 ],
					"order" : 0,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"midpoints" : [ 408.625, 451.5, 423.5, 451.5 ],
					"order" : 2,
					"source" : [ "obj-2", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"midpoints" : [ 235.5, 504.0, 182.5, 504.0 ],
					"order" : 2,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-60", 0 ],
					"source" : [ "obj-2", 3 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-69", 0 ],
					"source" : [ "obj-2", 4 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1173.5, 108.0, 1159.5, 108.0 ],
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 841.5, 389.0, 235.5, 389.0 ],
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-33", 0 ],
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 540.5, 389.5, 235.5, 389.5 ],
					"source" : [ "obj-28", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 1014.5, 357.0, 235.5, 357.0 ],
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 0 ],
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 1037.5, 389.0, 235.5, 389.0 ],
					"source" : [ "obj-33", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 964.5, 389.0, 235.5, 389.0 ],
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-63", 0 ],
					"midpoints" : [ 1354.5, 672.0, 1491.5, 672.0 ],
					"source" : [ "obj-36", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-40", 0 ],
					"source" : [ "obj-37", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"midpoints" : [ 207.5, 652.296875, 361.5, 652.296875 ],
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 1419.5, 387.0, 235.5, 387.0 ],
					"source" : [ "obj-40", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1206.5, 108.0, 1159.5, 108.0 ],
					"source" : [ "obj-42", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 111.5, 98.0, 111.359375, 98.0, 111.359375, 388.8515625, 235.5, 388.8515625 ],
					"source" : [ "obj-43", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 1 ],
					"midpoints" : [ 379.5, 608.0, 550.5, 608.0 ],
					"order" : 0,
					"source" : [ "obj-44", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 1 ],
					"midpoints" : [ 379.5, 608.5, 228.5, 608.5 ],
					"order" : 1,
					"source" : [ "obj-44", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1240.5, 108.0, 1159.5, 108.0 ],
					"source" : [ "obj-45", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1271.5, 108.0, 1159.5, 108.0 ],
					"source" : [ "obj-47", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"midpoints" : [ 1159.5, 209.0, 1159.5, 209.0 ],
					"source" : [ "obj-48", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-63", 0 ],
					"midpoints" : [ 1598.5, 672.0, 1491.5, 672.0 ],
					"source" : [ "obj-49", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 1335.5, 389.0, 235.5, 389.0 ],
					"source" : [ "obj-50", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-50", 0 ],
					"source" : [ "obj-52", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"source" : [ "obj-53", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1047.5, 108.0, 1159.5, 108.0 ],
					"source" : [ "obj-55", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-63", 0 ],
					"midpoints" : [ 1492.5, 622.5, 1491.5, 622.5 ],
					"source" : [ "obj-57", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 773.5, 389.0, 235.5, 389.0 ],
					"source" : [ "obj-58", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 134.5, 388.7890625, 235.5, 388.7890625 ],
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-58", 0 ],
					"source" : [ "obj-61", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-57", 0 ],
					"source" : [ "obj-62", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"source" : [ "obj-64", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"source" : [ "obj-64", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 620.5, 389.0, 235.5, 389.0 ],
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-36", 0 ],
					"source" : [ "obj-71", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-48", 0 ],
					"source" : [ "obj-73", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-49", 0 ],
					"source" : [ "obj-74", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-78", 0 ],
					"source" : [ "obj-77", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-84", 0 ],
					"midpoints" : [ 264.5, 229.714952761627956, 236.5, 229.714952761627956 ],
					"source" : [ "obj-78", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-84", 0 ],
					"midpoints" : [ 329.5, 228.523546511627956, 236.5, 228.523546511627956 ],
					"source" : [ "obj-79", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"midpoints" : [ 1078.5, 108.0, 1159.5, 108.0 ],
					"source" : [ "obj-8", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"midpoints" : [ 48.5, 387.7578125, 235.5, 387.7578125 ],
					"source" : [ "obj-80", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-84", 0 ],
					"midpoints" : [ 235.5, 229.953234011627956, 236.5, 229.953234011627956 ],
					"source" : [ "obj-81", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 1 ],
					"midpoints" : [ 287.5, 337.5, 928.0, 337.5 ],
					"source" : [ "obj-84", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"source" : [ "obj-84", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"source" : [ "obj-87", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"source" : [ "obj-9", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"source" : [ "obj-93", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-101", 0 ],
					"source" : [ "obj-95", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-121" : [ "HPF", "HPF", 0 ],
			"obj-122" : [ "LPF", "LPF", 0 ],
			"obj-44" : [ "number", "number", 0 ],
			"parameterbanks" : 			{
				"0" : 				{
					"index" : 0,
					"name" : "",
					"parameters" : [ "-", "-", "-", "-", "-", "-", "-", "-" ]
				}

			}
,
			"inherited_shortname" : 1
		}
,
		"dependency_cache" : [  ],
		"autosave" : 0
	}

}

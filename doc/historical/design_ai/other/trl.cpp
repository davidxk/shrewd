HAND_TYPE?
=MONSTERS	- RAISE
=BIG_PAIRS	- CNT_RAISE?	=0 - RAISE
							=1 - RAISE
							=d - FOLD
=MID_PAIRS	- CNT_RAISE?	=0 - WHICH_POS?	=EARLY_POS	- CALL
											=MIDDLE_POS	- CNT_LIMP? <2	- RAISE
																	=d	- CALL
											=LATE_POS 	^
											=d			*

							=1 - CNT_COPEN?	>=2			- CALL
											=d 			- EXP_NHAND?	>=5	- CALL
																		=d	- FOLD
							=d - FOLD
=SMA_PAIRS	- CNT_RAISE?	=0 - CALL
							=1 - EXP_NHAND?	>=5	- CALL
											=d	- FOLD
							=d - FOLD
=BIG_SU_BRDWY-CNT_RAISE?	=0 - IS_LOOSE?	=1	- RAISE
											=d	- FOLD
							=1 - FIG_0?		=A	- FIG_1?	=K	- RAISE
															=Q	- CALL
															=J	- EXP_NHAND?	=m	- CALL
																				=d	- FOLD
															=d	- FOLD
											=d	- FOLD
							=d - FOLD
=LTL_SU_BRDWY-CNT_RAISE?	=0 - WHICH_POS?	=EARLY_POS	- CALL
											=MIDDLE_POS	^
											=LATE_POS	- RAISE
											=d			*
							=1 - EXP_NHAND?	=m			- CALL
											=d			- FOLD
							=d - FOLD
=SUITED_ACES -CNT_RAISE?	=0 - IS_AGGR?	=f	- WHICH_POS?	=EARLY_POS	- AVR_BET?	>=3	- FOLD
																						=d	- FIG_1?=8 -CALL
																									=9 ^
																									=d -FOLD
																=MIDDLE_POS	- IS_LOOSE?	=t	- FIG_1?=8 -RAISE
																									=9 ^
																									=d CALL
																						=d	- CALL
																=LATE_POS 	^
																=d			*
											=d - CALL
							=d - FOLD
=SUITED_KINGS-CNT_RAISE?	=0 - WHICH_POS?	=EARLY_POS	- FIG_1?	=9	- CALL
																	=d	- FOLD
											=BUTTON_POS	- CALL
											=d			- FOLD
							=d - FOLD
=SUITED_CONN -CNT_RAISE?	=0 - WHICH_POS?	=EARLY_POS	- IS_AGGR?	=N	- FIG_1?	=9	-FIG_0?	=T - CALL
																								=J ^
																								=d - FOLD
																					=d	FOLD
																	=d	- FOLD
											=BUTTON_POS	- CALL
											=d			- FOLD
							=d - FOLD
=BIG_OFF_BRDWY-CNT_RAISE?	=0 - RAISE
							=1 - FIG_1?		=K			- RAISE
											=Q			- IS_RS_WLD?=t	- RAISE
																	=d	- FOLD
											=d			- FOLD
							=d - FOLD
=LTL_OFF_BRDWY-CNT_RAISE?	=0 - WHICH_POS?	=EARLY_POS	- FIG_0?	=A	- FIG_1?	=T	CALL		
																					=d	FOLD
																	=K	- FIG_1?	=J	CALL
																					=d	FOLD
																	=d	- FOLD
											=BUTTON_POS	- CALL
											=d *
							=d - FOLD
=JUNK_HAND	- FOLD
=NOT_THIS_HOLE^
=d	^

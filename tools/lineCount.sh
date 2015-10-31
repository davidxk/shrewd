cd ../source/
ls -R | perl ../tools/i_lsR_o_wc.pl 
#ls -R | perl ../tools/i_lsR_o_wc.pl | wc
#for each in $(ls -R | perl ../tools/i_lsR_o_wc.pl); do wc $each; done

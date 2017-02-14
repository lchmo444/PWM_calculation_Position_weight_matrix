# PWM_score(dna)
PWM_score(dna) is a simplified calculation tool.

A PWM_score has two matrix structure for position frequency matrix(PFM) and position 
probability matrix(PPM).

Formally, given a set X of string sequences of length l and each row value calculate
For instance, selected value multiply by value is Information content score with pssm.

This program calculates the sum selected item of colum.



Geecee tool method is an alternative to using to Prior residue probability for residue.

Usage of PWM_score(dna) with Information content
==============
```
pwm_tool.exe dnaWithbindings_2.fasta

Inpute Sequence = gaggtaaac
Prior residue probability for residue
residue_a = 0.3
residue_c = 0.2
residue_g = 0.2
residue_t = 0.3

1_ps = -1.62558e-008 | 2_ps = 0.370341 | 3_ps = -0.110093 | 4_ps = -0.653971 | 5_ps = -0.0653971 | 6_ps = 0.370341 |
7_ps = 0.526895 | 8_ps = -0.0754846 | 9_ps = -0.110093 |

Calaculated score = 0.841112
```

# Additional Items
Material update as soon as possible(Cpp -> Python).


# References
[1] https://en.wikipedia.org/wiki/Position_weight_matrix

[2] http://homepages.ulb.ac.be/~dgonze/TEACHING/info_content.pdf

[3] http://www.bioinformatics.nl/cgi-bin/emboss/geecee

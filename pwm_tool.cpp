#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <string>
#include <new>
#include <windows.h>
#include <iostream>

#include <vector>
#include <malloc.h>

#define Malloc(type,n) (type *)malloc((n)*sizeof(type))

float residue_a;
float residue_c;
float residue_g;
float residue_t;


double roundoff(double x);

using namespace std;
static char *line = NULL;
static int max_line_len;

static int aaa = 0;

static char* readline(FILE *input)
{
	
	if (fgets(line, max_line_len, input) == NULL)
		return NULL;
	
	return line;
	
}

int main(int argc, char **argv)
{
	int ll = 0;
	std::vector<char *>    pwm_s;			

	
	//string in_f = "\C:\\lee\\dnaWithbindings_125.fasta";
	string in_f = "\C:\\lee\\test.fasta";

	char * input_file_name = new char[in_f.length() + 1];
	//char *input_file_name = new char[1024];
	strcpy(input_file_name, in_f.c_str());

	//strcpy(input_file_name, argv[1]);
	FILE *fp = fopen(input_file_name, "r");		//original



	char *idx, *val, *label;

	int aa_t = 0;
	int ll_1 = 1;
	int ott = 0;
	max_line_len = 1024;
	line = Malloc(char, max_line_len);
	while (readline(fp) != NULL)
	{
		char *p = strtok(line, " \n"); // label

		if (ll_1 == 2)
		{
			aa_t = strlen(p);
		}

		++ll_1;
	}
	ll_1 = ll_1 / 2;

	
	int **matrix = (int**)calloc(aa_t, sizeof(int));

	for (int j = 0; j < aa_t; j++)
	{
		*(matrix + j) = (int*)calloc(4, sizeof(int));
	}
	
	
	if (fp == NULL)
	{
		fprintf(stderr, "can't open input file %s\n", input_file_name);
		exit(1);
	}

	fclose(fp);
	fp = fopen(input_file_name, "r");		//original

	int l = 1;
	int elements = 0;

	max_line_len = 1024;
	line = Malloc(char, max_line_len);


	int aa, cc, gg, tt = 0;


	int ot = 0;
	while (readline(fp) != NULL)
	{
		
		char *p = strtok(line, " \n"); // label
		if(l % 2 == 0)
		{
			
			for (int kk = 0; kk < aa_t; ++kk)
			{
				if (p[kk] == 'a' || p[kk] == 'A')
					++*(*(matrix + kk) + 0);
				if (p[kk] == 'c' || p[kk] == 'C')
					++*(*(matrix + kk) + 1);
				if (p[kk] == 'g' || p[kk] == 'G')
					++*(*(matrix + kk) + 2);
				if (p[kk] == 't' || p[kk] == 'T')
					++*(*(matrix + kk) + 3);
			}
			++ot;
			pwm_s.push_back(p);

		}

		++l;
	}
	double l_sum = 0.0;		//modified_part
	l_sum = (l-2) / 2.0;	//modified_part

	int *op;
	float *residue_i;			//residue value_4
	//char *op_prior_2;			//prior value input
	float *op_prior;

	char *op2;
	op2 = (char*)malloc(sizeof(int)*aa_t);

	op = (int*)calloc(aa_t, sizeof(int));			//count value
	op_prior = (float*)calloc(aa_t, sizeof(float));		//prior_matrix
	residue_i = (float*)malloc(sizeof(float)*4);		//prior value save


	if (strlen(op2) < aa_t){
		cout << "input error" << endl;
		return 0;
	}

	std::cout << "Inpute Sequence = ";
	gets(op2);
	if (strlen(op2) < aa_t){
		cout << "input error" << endl;
		return 0;
	}


	//free(op2);


	////////////////prior_value_old_ver////////////////////////
	/*
	/////////////////////////prior_value /////////////////////////
	for (int zz = 0; zz < aa_t; ++zz)
	{
		if (op2[zz] == 'A' || op2[zz] == 'a')
			op_prior[zz] = 0.30;
		if (op2[zz] == 'C' || op2[zz] == 'c')
			op_prior[zz] = 0.20;
		if (op2[zz] == 'G' || op2[zz] == 'g')
			op_prior[zz] = 0.20;
		if (op2[zz] == 'T' || op2[zz] == 't')
			op_prior[zz] = 0.30;
		fflush(stdin);
	}
	*/

	/*
	std::cout << "Prior residue probability for residue \n";
	cout << "residue_a = ";
	//gets(op2);
	cin >> residue_i[0];
	//cout << "\n";
	cout << "residue_c = ";
	cin >> residue_i[1];
	//cout << "\n";
	cout << "residue_g = ";
	cin >> residue_i[2];
	//cout << "\n";
	cout << "residue_t = ";
	cin >> residue_i[3];
	//cout << "\n";

	////////////////prior_value_new_ver////////////////////////
	/////////////////////////prior_value /////////////////////////
	for (int zz = 0; zz < aa_t; ++zz)
	{
		if (op2[zz] == 'A' || op2[zz] == 'a')
			op_prior[zz] = residue_i[0];
		if (op2[zz] == 'C' || op2[zz] == 'c')
			op_prior[zz] = residue_i[1];
		if (op2[zz] == 'G' || op2[zz] == 'g')
			op_prior[zz] = residue_i[2];
		if (op2[zz] == 'T' || op2[zz] == 't')
			op_prior[zz] = residue_i[3];
		fflush(stdin);
	}
	*/



	float score = 1.0;

	float score_2 = 1;

	for (int jj = 0; jj < aa_t; ++jj)
	{
		if (op2[jj] == 'A' || op2[jj] == 'a')
			op[jj] = 0;
		if (op2[jj] == 'C' || op2[jj] == 'c')
			op[jj] = 1;
		if (op2[jj] == 'G' || op2[jj] == 'g')
			op[jj] = 2;
		if (op2[jj] == 'T' || op2[jj] == 't')
			op[jj] = 3;
		fflush(stdin);
	}
	

	float value = 0.0;
	/////print_caluted_value/////////////////////////
	std::cout << "\n";
	for (int jj_1 = 0; jj_1 < aa_t; ++jj_1)
	{
		std::cout << jj_1+1 << "_ps = ";
		/////////////Calculated_Old_Term/////////
		/*
		if (1 == (float)(*(*(matrix + jj_1) + op[jj_1])) / l_sum)		//original_
			std::cout << (float)op_prior[jj_1] / (l_sum + 1.0);
			//std::cout << "1.0";

		else*/
		
		/*
		/////////////////DNA_Information_Content_with_pssm_Calculated_New_Term///////////////////
		///////////////////I_sum(sigmai=1,A n,ij) is each row of residue total , (matrix+jj_1+op[jj_1])+op_prior[jj_1] have term ni,j+pik(representation) , op_prior[jj_1] is residue probability with matrix low/////// 
		cout.precision(6);
		std::cout << (float)(((*(*(matrix + jj_1) + op[jj_1])) + op_prior[jj_1]) / (l_sum + 1.0))*log((((*(*(matrix + jj_1) + op[jj_1])) + op_prior[jj_1]) / (l_sum + 1.0)) / op_prior[jj_1]);		//modified_part

		float value = (float)(((*(*(matrix + jj_1) + op[jj_1])) + op_prior[jj_1]) / (l_sum + 1.0))*log((((*(*(matrix + jj_1) + op[jj_1])) + op_prior[jj_1]) / (l_sum + 1.0)) / op_prior[jj_1]);
		*/
		////20161207  op[jj_1] ´Â ÀÜ±âÀÇ À§Ä¡¸¦ ³ªÅ¸³¿
		std::cout << log2(((*(*(matrix + jj_1) + op[jj_1])) / (float)ll_1) / 0.25);
		value = log2(((*(*(matrix + jj_1) + op[jj_1])) / (float)ll_1) / 0.25);
		std::cout << " | ";
		score_2 = score_2 * value;		//modified_part
	}
	cout.precision(15);
	std::cout << "\n\nCalaculated score = " << score_2;
	
	score_2 = 0;

	free(matrix);


	free(input_file_name);
	free(op2);
	free(op_prior);
	free(residue_i);

	fclose(fp);

	
	return 0;
}

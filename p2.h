#include <iostream>
#include <fstream>
#include <string.h>
#include "/ee259/tools/pro_2/sample_p1.h" // implementation of base class

using namespace std;

ifstream input_file_p2("studentName.txt", ios::in);
//ofstream output_file_p2("out.1", ios::app);

  class SORT_INFO:public STUDENT_GRADE{
   public:      // public interfaces for this class

        SORT_INFO(int, int); // example: b.SORT_INFO(x, y);
				// constructor;
				// x is noof students, y is noof projects

        void SORT_ID(char *); // example: b.SORT_GRADE("ASCENDING");
				// interface to sort student ids in 
				// ascending order; returns no values;

        void SORT_GRADE(char *, int); // example: b.SORT_GRADE("ASCENDING", 2);
				// interface to sort exam 2 grades in 
				// ascending order; returns no values;

        void SORT_NAME(char *); // example: b.SORT_NAME("ASCENDING");
			    	// interface to sort students by last names
			    	// in alphabetical or reverse alphabetical order; 
			    	// returns no values;

   // protected vars below can only be accessed within this class and inherited classes
   // they are not directly accessible from main
   protected: 
	char LastName[20][12];   // array to hold student's last name
	char FirstName[20][12];  // array to hold student,s first name
   };

SORT_INFO::SORT_INFO(int x, int y)
	: STUDENT_GRADE(x, y) // call to base class which requires two parameters
{
	int i;
	output_file_p2 << "++++ P2 START ++++" << endl;
	output_file_p2 << "++++ P2 OUTPUT FROM SORT_INFO CONSTRUCTOR:" << endl;	

	for(i = 0; i < n; i++)
	{
		input_file_p2 >> LastName[i] >> FirstName[i];
	}
	output_file_p2 << "++++ P2 AN OBJECT OF SORT_INFO IS CREATED." << endl;
	output_file_p2 << "++++ P2 END ++++" << endl;
}

void
SORT_INFO::SORT_ID(char * DIRECTION)
{
	int i, j, k;
	int min, min_pos, max, max_pos, tempo = 0;
	char tempo_name[12];

	// your code goes below:
	output_file_p2 << "++++ P2 START ++++" << endl
				   << "++++ P2 OUTPUT FROM SORT_ID METHOD:" << endl;
	if(DIRECTION == "ASCENDING"){
		output_file_p2 << "++++ P2 BEFORE SORTING IN " << DIRECTION << " ORDER:" << endl;
		LIST_IDS();
		for (i = 0; i < n; i++){
		max = ids[i];
		max_pos = i;
			for(j = 0; j < n; j++){
				if(max < ids[j]){
					max = ids[j];
					max_pos = j;
					tempo = ids[i];
					ids[i] = ids[max_pos];
					ids[max_pos] = tempo;

					strcpy(&tempo_name[0], &LastName[i][0]);
					strcpy(&LastName[i][0], &LastName[max_pos][0]);
					strcpy(&LastName[max_pos][0], &tempo_name[0]);

					strcpy(&tempo_name[0], &FirstName[i][0]);
					strcpy(&FirstName[i][0], &FirstName[max_pos][0]);
					strcpy(&FirstName[max_pos][0], &tempo_name[0]);

					for(k= 0; k<p; k++){
						tempo =grades[i][k];
						grades[i][k]=grades[max_pos][k];
						grades[max_pos][k]=tempo;
					}
				} else {}
				
			//swap ids[i] w/ ids [min_pos]
			}
		//swap ids[i] w/ ids [min_pos]
		} 
		output_file_p2 << "++++ P2 AFTER SORTING IN " << DIRECTION << " ORDER: " << endl;
		LIST_IDS();
	} else if (DIRECTION == "DESCENDING"){
		output_file_p2 << "++++ P2 BEFORE SORTING IN " << DIRECTION << " ORDER:" << endl;
		LIST_IDS();
		for (i = 0; i < n; i++){
		min = ids[i];
		min_pos = i;
			for(j = 0; j < n; j++){
				if(min > ids[j]){
					min = ids[j];
					min_pos = j;
					tempo = ids[i];
					ids[i] = ids[min_pos];
					ids[min_pos] = tempo;
					strcpy(&tempo_name[0], &LastName[i][0]);
					strcpy(&LastName[i][0], &LastName[min_pos][0]);
					strcpy(&LastName[min_pos][0], &tempo_name[0]);

					strcpy(&tempo_name[0], &FirstName[i][0]);
					strcpy(&FirstName[i][0], &FirstName[min_pos][0]);
					strcpy(&FirstName[min_pos][0], &tempo_name[0]);

					for(k= 0; k<p; k++){
						tempo =grades[i][k];
						grades[i][k]=grades[min_pos][k];
						grades[min_pos][k]=tempo;
					}
				}
			}
		} //swap ids[i] w/ ids [min_pos]
		output_file_p2 << "++++ P2 AFTER SORTING IN " << DIRECTION << " ORDER: " << endl;
		LIST_IDS();
	} else {
		output_file_p2 << "++++ P2 INPUT ERROR" << endl;
	}
output_file_p2 << "++++ P2 END ++++" << endl;
}


void
SORT_INFO::SORT_GRADE(char * DIRECTION, int x) //AHHH it's sort students by their grade in descending order!
{
	int i, j, k;
	int min, min_pos, max, max_pos, tempo;
	char tempo_name[12];

	// your code goes below:
	output_file_p2 << "++++ P2 START ++++" << endl
				   << "++++ P2 OUTPUT FROM SORT_GRADE METHOD:" << endl
				   << "++++ P2 BEFORE SORTING IN " << DIRECTION << " ORDER:" << endl;
	if(DIRECTION == "DESCENDING" && x >= 0 && x < p){
		LIST_IDS();
			for (i = 0; i < n; i++){
				max = grades[i][x];
				max_pos = i;
				for(j = i; j < n; j++){
					if(max < grades[j][x]){
						max = grades[j][x];
						max_pos = j;
					} else {}
				}
				tempo = ids[i];
				ids[i] = ids[max_pos];
				ids[max_pos] = tempo;

				strcpy(&tempo_name[0], &LastName[i][0]);
				strcpy(&LastName[i][0], &LastName[max_pos][0]);
				strcpy(&LastName[max_pos][0], &tempo_name[0]);

				strcpy(&tempo_name[0], &FirstName[i][0]);
				strcpy(&FirstName[i][0], &FirstName[max_pos][0]);
				strcpy(&FirstName[max_pos][0], &tempo_name[0]);

				for(k= 0; k<p; k++){
					tempo =grades[i][k];
					grades[i][k]=grades[max_pos][k];
					grades[max_pos][k]=tempo;
				}
			//swap ids[i] w/ ids [min_pos]
			} 
		
		output_file_p2 << "++++ P2 AFTER SORTING IN " << DIRECTION << " ORDER: " << endl;
		LIST_IDS();
	} else if (DIRECTION == "ASCENDING" && x >= 0 && x < p){
		LIST_IDS();
		for (i = 0; i < n; i++){
			min = grades[i][x];
			min_pos = i;
				for(j = i; j < n; j++){
					if(min > grades[j][x]){
						min = grades[j][x];
						min_pos = j;
					} else {}
				}
				tempo = ids[i];
				ids[i] = ids[min_pos];
				ids[min_pos] = tempo;
				strcpy(&tempo_name[0], &LastName[i][0]);
				strcpy(&LastName[i][0], &LastName[min_pos][0]);
				strcpy(&LastName[min_pos][0], &tempo_name[0]);

				strcpy(&tempo_name[0], &FirstName[i][0]);
				strcpy(&FirstName[i][0], &FirstName[min_pos][0]);
				strcpy(&FirstName[min_pos][0], &tempo_name[0]);

				for(k= 0; k<p; k++){
					tempo =grades[i][k];
					grades[i][k]=grades[min_pos][k];
					grades[min_pos][k]=tempo;
				}
			//swap ids[i] w/ ids [min_pos]
			} 
		output_file_p2 << "++++ P2 AFTER SORTING IN " << DIRECTION << " ORDER: " << endl;
		LIST_IDS();
	} else {
		output_file_p2 << "++++ P2 INPUT ERROR" << endl;
}
output_file_p2 << "++++ P2 END ++++" << endl;
}

void
SORT_INFO::SORT_NAME(char * DIRECTION)
{
	int i, j, k;
	int min_pos, max_pos, tempo;
	char min_name[12], max_name[12], tempo_name[12];

	// your code goes below:
	output_file_p2 << "++++ P2 START ++++" << endl
				   << "++++ P2 OUTPUT FROM SORT_NAME METHOD:" << endl
				   << "++++ P2 BEFORE SORTING LAST NAMES IN ALPHABETICAL ORDER:" << endl;
	if(DIRECTION == "DESCENDING"){
		LIST_IDS();
		for (i = 0; i < n; i++){
			strcpy(&max_name[0], &LastName[i][0]);
			max_pos = i;
				for(j = i; j < n; j++){
					if(strcmp(&max_name[0], &LastName[j][0]) < 0){
						strcpy(&max_name[0], &LastName[j][0]);
						max_pos = j;
					} else {}
				}
				tempo = ids[i];
				ids[i] = ids[max_pos];
				ids[max_pos] = tempo;

				strcpy(&tempo_name[0], &LastName[i][0]);
				strcpy(&LastName[i][0], &LastName[max_pos][0]);
				strcpy(&LastName[max_pos][0], &tempo_name[0]);

				strcpy(&tempo_name[0], &FirstName[i][0]);
				strcpy(&FirstName[i][0], &FirstName[max_pos][0]);
				strcpy(&FirstName[max_pos][0], &tempo_name[0]);

				for(k= 0; k<p; k++){
					tempo =grades[i][k];
					grades[i][k]=grades[max_pos][k];
					grades[max_pos][k]=tempo;
				}
			//swap ids[i] w/ ids [min_pos]
			} 
		output_file_p2 << "++++ P2 AFTER SORTING LAST NAMES IN REVERSE ALPHABETICAL ORDER:" << endl;
		LIST_IDS();
	} else if (DIRECTION == "ASCENDING"){
		LIST_IDS();
		for (i = 0; i < n; i++){
			strcpy(&min_name[0], &LastName[i][0]);
			min_pos = i;
				for(j = i; j < n; j++){
					if(strcmp(&min_name[0], &LastName[j][0]) > 0){
						strcpy(&min_name[0], &LastName[j][0]);
						min_pos = j;
					} else {}
				} 
				tempo = ids[i];
				ids[i] = ids[min_pos];
				ids[min_pos] = tempo;
				strcpy(&tempo_name[0], &LastName[i][0]);
				strcpy(&LastName[i][0], &LastName[min_pos][0]);
				strcpy(&LastName[min_pos][0], &tempo_name[0]);

				strcpy(&tempo_name[0], &FirstName[i][0]);
				strcpy(&FirstName[i][0], &FirstName[min_pos][0]);
				strcpy(&FirstName[min_pos][0], &tempo_name[0]);

				for(k= 0; k<p; k++){
					tempo =grades[i][k];
					grades[i][k]=grades[min_pos][k];
					grades[min_pos][k]=tempo;
				}

			//swap ids[i] w/ ids [min_pos]
			} 
		output_file_p2 << "++++ P2 AFTER SORTING LAST NAMES IN ALPHABETICAL ORDER:" << endl;
		LIST_IDS();
	} else {
		output_file_p2 << "++++ P2 INPUT ERROR" << endl;
}
output_file_p2 << "++++ P2 END ++++" << endl;
}// end method

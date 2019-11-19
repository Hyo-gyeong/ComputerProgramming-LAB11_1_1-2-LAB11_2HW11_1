#include <stdio.h> 
#include <stdlib.h> 

struct score{
	int midterm;
	int final;
};

typedef struct score Score; //�ѹ��� ������ ������  
 
void printScore(Score *p) //2)
{     
	printf("�߰���� ������ %d\n", p->midterm );    
	printf("�б⸻��� ������ %d\n", p->final); 
}
Score *biggerScore(Score *p1, Score *p2) //3)  // ��ȯŸ�� ����, �Ű����� ����
{ 
	if (p1->midterm + p1->final > p2->midterm + p2->final)
		return p1;
	else
		return p2;

} 
Score totalScore(Score *p1, Score *p2, Score *tp) //4) // ��ȯŸ�� ����, �Ű����� �� �� �߰� 
{ 
	tp->midterm = p1->midterm + p2->midterm;
	tp->final = p1->final + p2->final;

	return *tp; 
} 
Score createScore(int m, int f) //5)
{ 
	Score temp;

	temp.midterm = m;
	temp.final = f;

	return temp;
 
} 
int main(void)
{ 
     Score s1, s2, temp;       
	 s1.midterm = 50;     
	 s1.final = 100;     
	 s2.midterm = 70;   
	 s2.final = 70;       
	 printf("1)-----------------------------\n");  
	 printScore(&s1);   
	 printScore(&s2); 
 
     printf("2)-----------------------------\n");  
	 printf("���� ������ ���� ����:\n");  
	 printScore(biggerScore(&s1, &s2));        
	 printf("3)-----------------------------\n");  
	 printf("�� ������ �� ��:\n");   
	 totalScore(&s1, &s2, &temp);   
	 printScore(&temp); 
 
     printf("4)-----------------------------\n");  
	 temp = createScore(99, 99); 
	 printScore(&temp); 
} 
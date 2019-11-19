#include <stdio.h> 
#include <stdlib.h> 

struct score{
	int midterm;
	int final;
};

typedef struct score Score; //한번에 쓰려면 위에다  
 
void printScore(Score *p) //2)
{     
	printf("중간고사 성적은 %d\n", p->midterm );    
	printf("학기말고사 성적은 %d\n", p->final); 
}
Score *biggerScore(Score *p1, Score *p2) //3)  // 반환타입 변경, 매개변수 변경
{ 
	if (p1->midterm + p1->final > p2->midterm + p2->final)
		return p1;
	else
		return p2;

} 
Score totalScore(Score *p1, Score *p2, Score *tp) //4) // 반환타입 변경, 매개변수 한 개 추가 
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
	 printf("둘중 성적이 좋은 점수:\n");  
	 printScore(biggerScore(&s1, &s2));        
	 printf("3)-----------------------------\n");  
	 printf("두 성적의 총 합:\n");   
	 totalScore(&s1, &s2, &temp);   
	 printScore(&temp); 
 
     printf("4)-----------------------------\n");  
	 temp = createScore(99, 99); 
	 printScore(&temp); 
} 
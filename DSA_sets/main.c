#include <stdio.h>
#include <stdlib.h>

#include "Sets.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	String menu[7] = {"Add Element", "Remove Element", "Display", "Union of Set",
						"Intersection of Set", "Difference of a Set", "Symmetric Difference"};
	int choice = 1, i, ch;
	bool insertTry, deleteTry;
	int temp, tempSet, card;
	Set a, b, c;
	a = newSet();
	b = newSet();
	c = newSet();		
	while(choice != 0)
		{
			system("cls");
			printf("MENU\n");
			printf("----------\n");
			
			for(i = 0; i < 7; i++)
				{
					printf("[%d] %s\n", i + 1, menu[i]);
				}
			
			
			printf("[INPUT YOUR CHOICE<0 TO EXIT THE PROGRAM>]: ");
			scanf("%d", &ch);
			
			switch(ch)
				{
					case 1:	printf("\nADD ELEMENT\n");
							printf("---------------\n");
							printf("[INPUT A NUMBER FROM 0 - 19]: ");
							scanf("%d", &temp);
							
							printf("\n[CHOOSE THE SET YOU WANT TO STORE THE NUMBER]: ");
							printf("\n[1] A\n[2] B\n\n");
							printf("[INPUT CHOICE]: ");
							scanf("%d", &tempSet);
							
								switch(tempSet)
									{
										case 1:
												insertTry = addElement(&a, temp);
												if(insertTry)
													{
														printf("\nSUCCESSFULLY INSERTED . . .\n");
													}
												else
													{
														printf("\nUNSUCCESSFUL . . . \n");
													}
												break;
												
										case 2:
												insertTry = addElement(&b, temp);
												if(insertTry)
													{
														printf("\nSUCCESSFULLY INSERTED . . .\n");
													}
												else
													{
														printf("\nUNSUCCESSFUL . . . \n");
													}
												break;
										default: printf("\nINVALID SET . . . \n\n");
									}
							break;
					
					case 2: printf("\nREMOVE ELEMENT\n");
							printf("---------------\n");
							printf("[INPUT A NUMBER FROM 0 - 19]: ");
							scanf("%d", &temp);
							
							printf("\n[CHOOSE THE SET YOU WANT THE NUMBER TO BE REMOVED]: ");
							printf("\n[1] A\n[2] B\n\n");
							printf("[INPUT CHOICE]: ");
							scanf("%d", &tempSet);
							
								switch(tempSet)
									{
										case 1:
												deleteTry = removeElement(&a, temp);
												if(deleteTry)
													{
														printf("\nSUCCESSFULLY DELETED . . .\n");
													}
												else
													{
														printf("\nUNSUCCESSFUL . . . \n");
													}
												break;
												
										case 2:
												deleteTry = removeElement(&b, temp);
												if(deleteTry)
													{
														printf("\nSUCCESSFULLY DELETED . . .\n");
													}
												else
													{
														printf("\nUNSUCCESSFUL . . . \n");
													}
												break;
										default: printf("\nINVALID SET . . . \n\n");
									}
							break;
							
					case 3: printf("\nDISPLAY\n");
							printf("---------------\n");
							printf("[CHOOSE WHAT SET TO DISPLAY]: \n[1] A\n[2] B\n[3] C\n\n");
							printf("[INPUT YOUR CHOICE]: ");
							scanf("%d", &tempSet);
								switch(tempSet)
									{
										case 1: displaySet(a);
												card = cardinality(a);
												printf("\n\n[CARDINALITY]: %d\n\n", card);
												break;
												
										case 2: displaySet(b);
												card = cardinality(b);
												printf("\n\n[CARDINALITY]: %d\n\n", card);
												break;
												
										case 3: displaySet(c);
												card = cardinality(c);
												printf("\n\n[CARDINALITY]: %d\n\n", card);
												break;
										default: printf("\nINVALID SET . . . \n\n");
									}
							break;
					
					case 4: printf("\nUNION OF A SET\n");
							printf("---------------\n");
							c = unionSet(a,b);
							displaySet(c);
							break;
							
					case 5: printf("\nINTERSECTION OF A SET\n");
							printf("---------------\n");
							c = intersectionSet(a,b);
							displaySet(c);
							break;
					
					case 6: printf("\nDIFFERENCE OF A SET\n");
							printf("---------------\n");
							c = differenceSet(a,b);
							displaySet(c);
							break;
					
					case 7: printf("\nSYMMETRIC DIFFERENCE OF A SET\n");
							printf("---------------\n");
							c = symmetricDiffSet(a,b);
							displaySet(c);
							break;
																
					default: printf("\nINVALID OPTION . . . \n\n");
				}
			
			system("pause");
		}
	
	
	
	
	return 0;
}

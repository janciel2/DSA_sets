#include <stdio.h>
#include <stdlib.h>

#include "Sets.h"

Set newSet()
{
	Set s;
	int i;
	
	for(i = 0; i < MAX; i++)
		{
			s.elems[i] = false;
		}
	s.count = 0;

	return s;
}

bool addElement(Set *s, int item)
{
	bool inserted = false;
	if((*s).elems[item] != true && (*s).count < MAX)
		{
			(*s).elems[item] = true;
			(*s).count++;
			inserted = true;
		}
	return inserted;	
}

bool removeElement(Set *s, int item)
{
	bool deleted = false;
	if((*s).elems[item] == true)
		{
			(*s).elems[item] = false;
			deleted = true;
		}
	return deleted;
	
}

void displaySet(Set s)
{
   int i;
   
   printf("{ ");
   for(i = 0; i < MAX; i++)
   	{
   		if(s.elems[i])
   			{
   				printf(" %d ",i);	
			}
		else
			{
				printf("");
			}
		
	}	
	printf(" }");
}

Set unionSet(Set a, Set b)
{
	Set r;
	r = newSet();
	
	int i; 
	for(i = 0;i < MAX; i++)
		{
			if(a.elems[i] || b.elems[i])
				{
					r.elems[i] = true;
					r.count++;
				}
			
		}
	return r;
}

Set intersectionSet(Set a, Set b)
{
	Set r;
	r = newSet();
	
	int i; 
	for(i = 0;i < MAX; i++)
		{
			if(a.elems[i] && b.elems[i])
				{
					r.elems[i] = true;
					r.count++;
				}
			
		}
	return r;
}

Set differenceSet(Set a, Set b)
{
	Set r;
	r = newSet();
	
	int i; 
	for(i = 0;i < MAX; i++)
		{
			if(!b.elems[i] && a.elems[i])
				{
					r.elems[i] = true;
					r.count++;
				}
			
		}
	return r;
}

Set symmetricDiffSet(Set a, Set b)
{
	Set r;

	r = newSet();
	
	int i; 
	for(i = 0;i < MAX; i++)
		{
			if(!b.elems[i] && a.elems[i] || !a.elems[i] && b.elems[i])
				{
					r.elems[i] = true;
					r.count++;
				}	
		}
				
	return r;
}

int cardinality(Set x)
{
	return x.count;
}


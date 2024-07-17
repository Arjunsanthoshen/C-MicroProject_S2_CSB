#include <stdio.h>

void displayCandidate();
void registerVoter();
void vote();
void voteCount();

struct voting {
    int voter_id;
    char name[40];
    int voted;
    }voter[100];

struct candidate {
    int candidate_id;
    char name[40];
    int votes;
}candidates[10]={{1,"A",0},{2,"B",0},{3,"C",0}};

int num_voter = 0,i,voter_id,candidate_choice;
int main(){
    int choice;
    do {
        printf("\n\t Menu \n");
        printf("1. Register voter \n");
        printf("2. Vote \n");
        printf("3. count of votes \n");
        printf("4. Exit \n");
        printf("enter your choice : ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                registerVoter();
                break;
            case 2:
                
                vote();
                break;
            case 3:
                voteCount();
                break;
            case 4:
                printf("exiting..");
                return 0;
            
            default:
                printf("Invalid choice");
        }
    }while(1);
}

void registerVoter(){
    printf("enter your name: ");
    scanf(" %[^\n]",voter[num_voter].name);
    voter[num_voter].voter_id = num_voter+1;
    voter[num_voter].voted = 0;
    printf("\nregistered succesfully.  voter id =%d\n",++num_voter);
}

void displayCandidate(){
    printf("\ncandidates: \n");
    for(i=0;i<3;i++){
        printf("%d. %s\n",i+1,candidates[i].name);
    }
}

void vote(){
    printf("\nenter voter_id: ");
    scanf("%d",&voter_id);
    if(voter_id>=1 && voter_id<=100){
        if(voter[voter_id-1].voter_id==voter_id){
            if(voter[voter_id-1].voted==0){
                displayCandidate();
                printf("enter your candidate choice(1 to 3) : ");
                scanf("%d",&candidate_choice);
                if(candidate_choice<1 ||candidate_choice>3){
                    printf("invalid choice");
                }else{
                    voter[voter_id-1].voted = 1;
                    candidates[candidate_choice-1].votes++;
                    printf("voted succesfully\n");
                }
            }else{
                printf("you have already voted");
            }
        }else{
            printf("Please register before voting\n");
        }
    }else{
        printf("invalid voter_id");
    }
}

void voteCount(){
    printf("vote count\n");
    printf("candidate\tvotes\n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %s\t\t %d\n",candidates[i].name,candidates[i].votes);
    }
    
}
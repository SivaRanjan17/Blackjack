#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>


struct details{
    char p_name[100];
    int s_amount;
}pdetails;

void text1();
void text();
int play();

int samount = 0;

int show_info(int res){
 GtkWidget *dialog;
 GtkWidget *window;

window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    if (res == 1)
    {
        dialog = gtk_message_dialog_new(GTK_WINDOW(window),
        GTK_DIALOG_DESTROY_WITH_PARENT,
        GTK_MESSAGE_INFO,
        GTK_BUTTONS_OK,"Player Wins!");
        gtk_window_set_title(GTK_WINDOW(dialog), "Result");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
  }

  else if (res == 2){
        dialog = gtk_message_dialog_new(GTK_WINDOW(window),
        GTK_DIALOG_DESTROY_WITH_PARENT,
        GTK_MESSAGE_INFO,
        GTK_BUTTONS_OK,"Computer Wins!");
        gtk_window_set_title(GTK_WINDOW(dialog), "Result");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }

  else {
    dialog = gtk_message_dialog_new(GTK_WINDOW(window),
        GTK_DIALOG_DESTROY_WITH_PARENT,
        GTK_MESSAGE_INFO,
        GTK_BUTTONS_OK,"Draw!, Player and Computer get the same score!");
        gtk_window_set_title(GTK_WINDOW(dialog), "Result");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
  }

  return 0;
}

void show_error(int c){

  GtkWidget *dialog;
  GtkWidget *window;

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  if (c == 1){
  dialog = gtk_message_dialog_new(GTK_WINDOW(window),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_ERROR,
            GTK_BUTTONS_OK,
            "Error loading file");
  gtk_window_set_title(GTK_WINDOW(dialog), "Error");
  gtk_dialog_run(GTK_DIALOG(dialog));
    }

    else {
        FILE *f1;
        if ((f1 = fopen("Details.txt", "a+")) == NULL){

            show_error(1);
            exit(0);
        }

        else{

            fprintf (f1, "%s %d %d\n", pdetails.p_name, samount, pdetails.s_amount);
            dialog = gtk_message_dialog_new(GTK_WINDOW(window),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_ERROR,
            GTK_BUTTONS_OK,
            "You have exhausted your money!");
            gtk_window_set_title(GTK_WINDOW(dialog), "Error");
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_main_quit();

        }
    }

    gtk_main_quit();
}

void write_file(){

    FILE *f1;

    if ((f1 = fopen("Details.txt", "a+")) == NULL){

        show_error(1);
        exit(0);
    }

    else {

        fprintf(f1, "%s %d %d\n", pdetails.p_name, samount, pdetails.s_amount);
        exit(0);
    }
}

void choice(){

    GtkWidget *button = NULL;
    GtkWidget *win = NULL;
    GtkWidget *vbox = NULL;

  /* Initialize GTK+ */
    g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
    g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);

      /* Create the main window */
    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width (GTK_CONTAINER (win), 8);
    gtk_window_set_title (GTK_WINDOW (win), "Would You Like To Continue?");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(win), 480, 240);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);

    /* Create a vertical box with buttons */
    vbox = gtk_vbox_new (TRUE, 6);
    gtk_container_add (GTK_CONTAINER (win), vbox);


    button = gtk_button_new_with_label("Yes");
    g_signal_connect (G_OBJECT(button), "clicked", G_CALLBACK(play), (gpointer) win);
    gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

    button = gtk_button_new_with_label("No");
    g_signal_connect (G_OBJECT(button), "clicked", G_CALLBACK(write_file), (gpointer) win);
    gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

    /* Enter the main loop */
    gtk_widget_show_all (win);
    gtk_main ();


}

int shuff(int cards[]){

	int t;
	int i;
	int desk[52];
	for (i=0;i<52;i++){
		desk[i] = (i/13+3)*100 + i%13 + 1;
		//printf("%d ", desk[i]);
}

	srand(time(NULL));
	for (i = 0; i < 52; i++)
	{
		do
		{
			t = rand() % 52;
		} while (desk[t] == 0);
		cards[i] = desk[t];
		desk[t] = 0;
	}

	return 0;
}

int convert_jkq(int a) {
	if ((a%100==11) ||(a%100==12) ||(a%100==13)){
        return (a/100)*100+10;
    }
	else{
	} return a;
}

void pic(int num) {
	int po_num;
	po_num = num % 100;
	switch (po_num)
	{
		case 1:
		{
			printf("*******\n");
			printf("*     *\n");
			printf("*     *\n");
			printf("*   A *\n");
			printf("*     *\n");
			printf("*******\n");
			break;
		}
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		{
			printf("*******\n");
			printf("*     *\n");
			printf("*     *\n");
			printf("*   %d *\n", po_num);
			printf("*     *\n");
			printf("*******\n");
			break;
		}
		case 11:
		{
			printf("*******\n");
			printf("*     *\n");
			printf("*     *\n");
			printf("*   J *\n");
			printf("*     *\n");
			printf("*******\n");
			break;
		}
		case 12:
		{
			printf("*******\n");
			printf("*     *\n");
			printf("*     *\n");
			printf("*   Q *\n");
			printf("*     *\n");
			printf("*******\n");
			break;
		}
		case 13:
		{
			printf("*******\n");
			printf("*     *\n");
			printf("*     *\n");
			printf("*   K *\n");
			printf("*     *\n");
			printf("*******\n");
			break;
		}

	}
}

int play(void) {
	int i, bet;
	int psum=0;
	int bsum=0;
	int pcards[5]={0};
	int bcards[5]={0};
	int cards[52];
	char go_on;
	char d;
	int count = 0;

	if (samount == 0){

        printf("\nInvalid Amount! Enter Amount Again!");
        exit(0);
    }


	printf("\nWelcome to BlackJack!\n"
	"\nPress Enter to Start:");

	do{
		go_on = getchar();
	} while (go_on != '\n');
	printf("\n");

	//shuffle the cards
	shuff(cards);

    printf ("\nPlayer name: %s", pdetails.p_name);
	printf ("\nYour money: %d", pdetails.s_amount);

	l1: printf ("\nHow much would you like to bet: ");
	scanf("%d", &bet);

	if (bet > pdetails.s_amount){
        count++;
        if (count >= 10){
            printf ("\nToo many Invalid Inputs!");
            exit(0);
        }
        printf ("\nInvalid bet!\n Please bet again!\n");
        goto l1;

	}

	//give the cards
	pcards[0]=cards[0];
	pcards[1]=cards[1];
	bcards[0]=cards[2];
	bcards[1]=cards[3];



	//the 2 cards player get
	printf("One Of The  Dealer's cards:\n");
	pic(bcards[0]);
	printf("\n");
	printf("Cards of player:\n");
	pic(pcards[0]);

	pic(pcards[1]);


	i=0;
	for (i=0; i<2; i++)
	{
		if (pcards[i]%100 == 1)
		{
			printf("choose A value of the card %d, input 'y' for 11 or 'n' for 1 :\n", i+1);
			do{
				d = getchar();
			} while (d!='y' && d!='n');

			if (d == 'y')
			{
				printf("You've chosen value 11 for card A.\n");
				psum = psum + 11;
			}
			else if(d == 'n')
			{
				printf("You've chosen value 1 for card A.\n");
				psum = psum +1;
			}
		}
		else if (convert_jkq(pcards[i]) %100 ==10){
            psum = psum + 10;
		}

		else psum = psum + pcards[i]%100;

		if (psum > 21)
		{
			printf("Sum of player's cards now:%d\n\n",psum);
			//printf("Computer wins!\n");
			pdetails.s_amount -= bet;
			show_info(2);
			return 1;
		}
		else if (psum == 21)
		{
			printf("Sum of player's cards now:%d\n\n",psum);
			//printf("Player win!\n");
			pdetails.s_amount += bet;
			show_info(1);
			goto c;
			return 0;
		}
	}
	printf("Sum of player's cards now:%d\n\n",psum);

	//whether player get another cards

	i=0;
	for (i=0; i<3; i++)
	{
		char j = 'n';

		printf("Want more cards (hit or stay)? Input (HIT)y or (STAY)n: \n");
		do{
			j = getchar();
		} while (j!='y' &&j!='n');

		if (j=='y')
		{
			printf("You've got another card now!\n");
			pcards[i+2]=cards[i+4];
			printf("And your card %d is:\n", i+3);
			pic(pcards[i+2]);

			if (pcards[i+2]%100 == 1)
			{
				printf("Choose A value of the card %d, input 'y' for 11 or 'n' for 1:\n", i+3);
				do{
					d = getchar();
				} while (d!='y' && d!='n');
				if (d == 'y')
				{
					printf("You've chosen value 11 for card A.\n");
					psum = psum + 11;
				}
				else if(d == 'n')
				{
					printf("You've chosen value 1 for card A.\n");
					psum = psum +1;
				}
			}
			else if (convert_jkq(pcards[i+2]) %100 ==10) psum = psum + 10;
			else psum = psum + pcards[i+2]%100;

			if (psum > 21)
			{
				printf("Sum of player's cards now:%d\n\n",psum);
				//printf("Computer win!\n");
				pdetails.s_amount -= bet;
				show_info(2);
				goto c;
				return 1;
			}
			else if (psum == 21)
			{
				printf("Sum of player's cards now:%d\n\n",psum);
				//printf("Player win!\n");
				pdetails.s_amount += bet;
				show_info(1);
				goto c;
				return 0;
			}
			else printf("Sum of player's cards now:%d\n\n",psum);
		}
		else
		{
			printf("Sum of player's cards now:%d\n\n",psum);
			break;
		}
	}
	if (i == 3)
	{
		printf("Player win! Because the sum of your 5 cards is no larger than 21!\n");
		pdetails.s_amount += bet;
		show_info(1);
		goto c;
		return 0;
	}

	//the 2 cards of boss/computer
	//i=0;
	printf("Computer's cards:\n");
	pic(bcards[0]);
	pic(bcards[1]);

	if (bcards[0]%100 + bcards[1]%100 == 2)
	{
		bsum=12; //two A cards
		printf("Sum of computer's cards now:%d\n\n", bsum);
	}
	else if (((convert_jkq(bcards[0]))%100 + (convert_jkq(bcards[1]))%100) ==1)
	{
		bsum=21;
		printf("Sum of computer's cards now:%d\n\n", bsum);
		pdetails.s_amount -= bet;

		//printf("Computer win!\n");
        show_info(2);
        goto c;
		return 1;
	}
	else if (bcards[0]%100==1 || bcards[1]%100==1)
	{
		bsum=(bcards[0]+bcards[1])%100+(rand()%2)*10;
		printf("Sum of computer's cards now:%d\n\n", bsum);
	}
	else
	{
		bsum = (convert_jkq(bcards[0]))%100 + (convert_jkq(bcards[1]))%100;
		printf("Sum of computer's cards now:%d\n\n", bsum);
	}

	//whether computer get another cards until bsum>16
	//i=0;
	for (i=0; i<3 && bsum<17; i++)
	{
		bcards[i+2]=cards[i+7];
		printf("Computer's card %d is:\n", i+3);
		pic(bcards[i+2]);

		if (bcards[i+2]%100 == 1)
		{
			if (bsum+11 <= 21)
			{
				printf("Computer has chosen A as 11\n");
				bsum = bsum+11;
				printf("Sum of computer's cards now:%d\n\n", bsum);
			}
			else
			{
				printf("Computer has chosen A as 1\n");
				bsum = bsum+1;
				printf("Sum of computer's cards now:%d\n\n", bsum);
			}
		}
		else
		{
			bsum = bsum + convert_jkq(bcards[i+2])%100;
			printf("Sum of computer's cards now:%d\n\n", bsum);
		}
	}
	if (i == 3)
	{
		printf("Computer win! Because the sum of its 5 cards is no larger than 21!\n");
		pdetails.s_amount -= bet;
		show_info(2);
		goto c;
		return 1;
	}

	//the last step
	if (bsum>21 || psum>bsum)
	{
	    pdetails.s_amount += bet;
        show_info(1);
        goto c;
		//printf("Player win!\n");
		return 0;
	}
	else if (psum == bsum)
	{
	    show_info(3);
	    goto c;
		//printf("Oh, player and computer get the same score!\n");
		return 3;
	}
	else if (psum < bsum)
	{
	    pdetails.s_amount -= bet;
		//printf("Computer win!\n");
		show_info(2);
		goto c;
		return 1;
	}

	c: if (pdetails.s_amount <= 0){

            show_error(2);
        }

       else{
	    choice();
       }

	return 3;
}

void intstructions (GtkWidget *wid, GtkWidget *win){
  GtkWidget *dialog = NULL;

  dialog = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Get 21 points on the player's first two cards, without a dealer blackjack\n\n"
                                   "Reach a final score higher than the dealer without exceeding 21; or\n\n"
                                   "Let the dealer draw additional cards until their hand exceeds 21.\n\n"
                                   "-----Developed By Sivaranjan and Rahul Leonard-----");
  gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);



}

void enter_callback( GtkWidget *widget, GtkWidget *entry ){
    gchar *pl_name;
    pl_name = gtk_entry_get_text (GTK_ENTRY (entry));
    strcpy(pdetails.p_name, pl_name);
    text1();
}

void text () {

    GtkWidget *window;
    GtkWidget *vbox, *hbox;
    GtkWidget *entry;
    GtkWidget *button;

    gint tmp_pos;

    /* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (GTK_WIDGET (window), 200, 100);
    gtk_window_set_title (GTK_WINDOW (window), "Name");
    g_signal_connect (window, "destroy",
                      G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect_swapped (window, "delete-event",
                              G_CALLBACK (gtk_widget_destroy),
                              window);

    vbox = gtk_vbox_new (FALSE, 0);
    gtk_container_add (GTK_CONTAINER (window), vbox);
    gtk_widget_show (vbox);

    entry = gtk_entry_new ();
    gtk_entry_set_max_length (GTK_ENTRY (entry), 50);
    g_signal_connect (entry, "activate",
		      G_CALLBACK (enter_callback),
		      entry);
    gtk_entry_set_text (GTK_ENTRY (entry), "Enter Your");
    tmp_pos = GTK_ENTRY (entry)->text_length;
    gtk_editable_insert_text (GTK_EDITABLE (entry), " Name", -1, &tmp_pos);
    gtk_editable_select_region (GTK_EDITABLE (entry),
			        0, GTK_ENTRY (entry)->text_length);
    gtk_box_pack_start (GTK_BOX (vbox), entry, TRUE, TRUE, 0);
    gtk_widget_show (entry);

    hbox = gtk_hbox_new (FALSE, 0);
    gtk_container_add (GTK_CONTAINER (vbox), hbox);
    gtk_widget_show (hbox);

    button = gtk_button_new_from_stock (GTK_STOCK_CLOSE);
    g_signal_connect (button, "clicked", gtk_main_quit,  window);
    gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
    gtk_widget_set_can_default (button, TRUE);
    gtk_widget_grab_default (button);
    gtk_widget_show (button);




    gtk_widget_show (window);
}

void  enter_callback1( GtkWidget *widget, GtkWidget *entry ){
    gchar *p_bet;
    p_bet = gtk_entry_get_text(GTK_ENTRY (entry));

    p_bet = atoi(p_bet);

    printf ("\nStarting amount: %d\n", p_bet);
    pdetails.s_amount = p_bet;
    samount = p_bet;
    play();
}

void text1(){

    GtkWidget *window;
    GtkWidget *vbox, *hbox;
    GtkWidget *entry;
    GtkWidget *button;

    gint tmp_pos;

    /* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (GTK_WIDGET (window), 200, 100);
    gtk_window_set_title (GTK_WINDOW (window), "Amount");
    g_signal_connect (window, "destroy",
                      G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect_swapped (window, "delete-event",
                              G_CALLBACK (gtk_widget_destroy),
                              window);

    vbox = gtk_vbox_new (FALSE, 0);
    gtk_container_add (GTK_CONTAINER (window), vbox);
    gtk_widget_show (vbox);

    entry = gtk_entry_new ();
    gtk_entry_set_max_length (GTK_ENTRY (entry), 50);
    g_signal_connect (entry, "activate",
		      G_CALLBACK (enter_callback1),
		      entry);
    gtk_entry_set_text (GTK_ENTRY (entry), "Enter your");
    tmp_pos = GTK_ENTRY (entry)->text_length;
    gtk_editable_insert_text (GTK_EDITABLE (entry), " starting amount", -1, &tmp_pos);
    gtk_editable_select_region (GTK_EDITABLE (entry),
			        0, GTK_ENTRY (entry)->text_length);
    gtk_box_pack_start (GTK_BOX (vbox), entry, TRUE, TRUE, 0);
    gtk_widget_show (entry);

    hbox = gtk_hbox_new (FALSE, 0);
    gtk_container_add (GTK_CONTAINER (vbox), hbox);
    gtk_widget_show (hbox);



    button = gtk_button_new_from_stock (GTK_STOCK_OK);
    g_signal_connect_swapped (button, "clicked",
			      G_CALLBACK (play),
			      window);
    gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
    gtk_widget_set_can_default (button, TRUE);
    gtk_widget_grab_default (button);
    gtk_widget_show (button);

    gtk_widget_show (window);

}

int main (int argc, char *argv[]){
    GtkWidget *button = NULL;
    GtkWidget *win = NULL;
    GtkWidget *vbox = NULL;

    /* Initialize GTK+ */
    g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
    gtk_init (&argc, &argv);
    g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);
      /* Create the main window */
    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width (GTK_CONTAINER (win), 8);
    gtk_window_set_title (GTK_WINDOW (win), "Blackjack v1.0");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(win), 720, 480);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);

    /* Create a vertical box with buttons */
    vbox = gtk_vbox_new (TRUE, 6);
    gtk_container_add (GTK_CONTAINER (win), vbox);

    button = gtk_button_new_from_stock (GTK_STOCK_DIALOG_INFO);
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (intstructions), (gpointer) win);
    gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

    button = gtk_button_new_with_label("Start Game");
    g_signal_connect (G_OBJECT(button), "clicked", G_CALLBACK(text), (gpointer) win);
    gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

    button = gtk_button_new_from_stock (GTK_STOCK_CLOSE);
    g_signal_connect (button, "clicked", gtk_main_quit, NULL);
    gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

    gtk_widget_show_all (win);
    gtk_main ();

      return 0;

}

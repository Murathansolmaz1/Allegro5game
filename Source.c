#include<time.h>
#include<stdio.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro5.h>
#include<allegro5/allegro_image.h>
#include<math.h>
#include<allegro5\allegro_native_dialog.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>

int main(){


	if (!al_init()) {
		al_show_native_message_box(NULL, "Allegro Error", "Error", "Coudn't Initilize Allegro !", NULL, NULL);
		return -1;
	}

	ALLEGRO_DISPLAY *display = al_create_display(375, 600);
	al_clear_to_color(al_map_rgb(0, 178, 178));
	al_set_window_title(display, "2048 Bricks");


	if (!display) {
		al_show_native_message_box(display, "Sample Title", "Error", "Display Window was nor created succesfully", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / 1.0);
	al_start_timer(timer);

	al_install_keyboard();

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_clear_to_color(al_map_rgb(0, 178, 178));


	ALLEGRO_FONT *font = al_load_font("C:/Users/solma/source/repos/2048 Bricks Allegro5/2048 Bricks Allegro5/ariblk.ttf", 12, 0);
	srand(time(NULL));

	int x = 150, y = 75;
	int movespeed = 25;
	int arry[] = { 2, 4, 8, 16, 32, 64 };
	int *a[7][5] = { { 0,0,0,0,0 },
	{ 0,0,0,0,0 },
	{ 0,0,0,0,0 },
	{ 0,0,0,0,0 },
	{ 0,0,0,0,0 },
	{ 0,0,0,0,0 },
	{ 0,0,0,0,0 } };

	al_draw_line(0, 70, 500, 70, al_map_rgb(175, 175, 175), 2);
	al_draw_filled_rounded_rectangle(175, 45, 200, 70, 5, 5, al_map_rgb(221, 68, 26));
	al_draw_filled_rounded_rectangle(x, y, x + 75, y + 75, 10, 10, al_map_rgb(255, 170, 86));
	al_flip_display();
	al_clear_to_color(al_map_rgb(0, 178, 178));

	while (1) {

		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);

		if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT && !(x > 290)) {
			x += movespeed;
		}
		else if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT && !(x < 10)) {
			x -= movespeed;
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER && !(y > 490)) {
			y += movespeed * 3;
		}
		else if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN && !(y > 490)) {
			y += movespeed * 3;
		}

		al_draw_filled_rounded_rectangle(175, 45, 200, 70, 5, 5, al_map_rgb(221, 68, 26));
		al_draw_filled_rounded_rectangle(x, y, x + 75, y + 75, 10, 10, al_map_rgb(255, 170, 86));
		al_draw_line(0, 70, 500, 70, al_map_rgb(255, 255, 255), 2);
		al_draw_text(font, al_map_rgb(0, 0, 0), 187, 57, 0, "SM");
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 178, 178));
	}


	/*   for(int i=0;i<6;i++){

	al_draw_line(0, 70, 500, 70, al_map_rgb(0,0,0), 2);
	al_draw_filled_rounded_rectangle(175,45,200,70,5,5, al_map_rgb(221, 68, 26));
	al_draw_filled_rounded_rectangle(x,y,x+75,y+75,10,10, al_map_rgb(255, 170, 86));
	arry[rand()%6] = arry[i];

	ALLEGRO_FONT *font = al_load_font("/Users/macbookpro/Documents/Simge Dosyalar/allegrodeneme/allegrodeneme/Arial Black.ttf", 12, 0);
	al_draw_textf(font,al_map_rgb(0,0,0),187,57,0,"%d",arry[rand()%6]);
	al_flip_display();
	al_rest(7.0);
	al_destroy_font(font);
	}
	*/


		getchar();
		getchar();
		getchar();
		getchar();
		return 0;
	}

// Prints a 5x7 image

void drawLetter(int color, int brightness, int startx, int starty, char letter) {
	char letterBytes[7][5];
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 7; y++){
			letterBytes[y][x] = '#';
		}

	}
	switch( letter ){
		case 'a': case 'A':
			letterBytes[0] = {' ',' ','#',' ',' '};
			letterBytes[1] = {' ','#',' ','#',' '};
			letterBytes[2] = {'#',' ',' ',' ','#'};
			letterBytes[3] = {'#','#','#','#','#'};
			letterBytes[4] = {'#',' ',' ',' ','#'};
			letterBytes[5] = {'#',' ',' ',' ','#'};
			letterBytes[6] = {'#',' ',' ',' ','#'};
			break;
	}
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 7; y++){
			if (letterBytes[y][x] == '#') {
				drawLed(color,brightness,starty+y,startx+x);
			}
		}

	}
}
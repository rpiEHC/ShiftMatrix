// Prints a 5x7 image

void drawLetter(int color, int brightness, int startx, int starty, char letter) {
	char L[7][5];
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 7; y++){
			L[y][x] = '#';
		}
	}

	char* letterLine0 = "     ";
	char* letterLine1 = "     ";
	char* letterLine2 = "     ";
	char* letterLine3 = "     ";
	char* letterLine4 = "     ";
	char* letterLine5 = "     ";
	char* letterLine6 = "     ";

	if (letter == 'a' || letter == 'A') {
		letterLine0 = "  #  ";
		letterLine1 = " # # ";
		letterLine2 = "#   #";
		letterLine3 = "#####";
		letterLine4 = "#   #";
		letterLine5 = "#   #";
		letterLine6 = "#   #";
	}
	else if (letter == 'b' || letter == 'B') {
		letterLine0 = "#### ";
		letterLine1 = "#   #";
		letterLine2 = "#   #";
		letterLine3 = "#### ";
		letterLine4 = "#   #";
		letterLine5 = "#   #";
		letterLine6 = "#### ";
	}
	else if (letter == 'c' || letter == 'C') {
		letterLine0 = " ####";
		letterLine1 = "#    ";
		letterLine2 = "#    ";
		letterLine3 = "#    ";
		letterLine4 = "#    ";
		letterLine5 = "#    ";
		letterLine6 = " ####";
	}
	else if (letter == 'd' || letter == 'D') {
		letterLine0 = "#### ";
		letterLine1 = "#   #";
		letterLine2 = "#   #";
		letterLine3 = "#   #";
		letterLine4 = "#   #";
		letterLine5 = "#   #";
		letterLine6 = "#### ";
	}
	else if (letter == 'e' || letter == 'E') {
		letterLine0 = "#####";
		letterLine1 = "#    ";
		letterLine2 = "#    ";
		letterLine3 = "#####";
		letterLine4 = "#    ";
		letterLine5 = "#    ";
		letterLine6 = "#####";
	}	
	
	else if (letter == 'f' || letter == 'F') {
		letterLine0 = "#####";
		letterLine1 = "#    ";
		letterLine2 = "#    ";
		letterLine3 = "#####";
		letterLine4 = "#    ";
		letterLine5 = "#    ";
		letterLine6 = "#    ";
	}
	else if (letter == 'g' || letter == 'G') {
		letterLine0 = " ####";
		letterLine1 = "#    ";
		letterLine2 = "#    ";
		letterLine3 = "#  ##";
		letterLine4 = "#   #";
		letterLine5 = "#   #";
		letterLine6 = " ### ";
	}
	else if (letter == 'h' || letter == 'H') {
		letterLine0 = "#   #";
		letterLine1 = "#   #";
		letterLine2 = "#   #";
		letterLine3 = "#####";
		letterLine4 = "#   #";
		letterLine5 = "#   #";
		letterLine6 = "#   #";
	}
	else if (letter == 'i' || letter == 'I') {
		letterLine0 = "#####";
		letterLine1 = "  #  ";
		letterLine2 = "  #  ";
		letterLine3 = "  #  ";
		letterLine4 = "  #  ";
		letterLine5 = "  #  ";
		letterLine6 = "#####";
	}
	else if (letter == 'j' || letter == 'J') {
		letterLine0 = "#####";
		letterLine1 = "   # ";
		letterLine2 = "   # ";
		letterLine3 = "   # ";
		letterLine4 = "   # ";
		letterLine5 = "#  # ";
		letterLine6 = " ##  ";
	}
	else if (letter == 'k' || letter == 'K') {
		letterLine0 = "#  # ";
		letterLine1 = "# #  ";
		letterLine2 = "##   ";
		letterLine3 = "##   ";
		letterLine4 = "# #  ";
		letterLine5 = "#  # ";
		letterLine6 = "#   #";
	}
	else if (letter == 'l' || letter == 'L') {
		letterLine0 = "#    ";
		letterLine1 = "#    ";
		letterLine2 = "#    ";
		letterLine3 = "#    ";
		letterLine4 = "#    ";
		letterLine5 = "#    ";
		letterLine6 = "#####";
	}
	else if (letter == 'm' || letter == 'M') {
		letterLine0 = "#   #";
		letterLine1 = "## ##";
		letterLine2 = "# # #";
		letterLine3 = "#   #";
		letterLine4 = "#   #";
		letterLine5 = "#   #";
		letterLine6 = "#   #";
	}
	else if (letter == 'n' || letter == 'N') {
		letterLine0 = "#   #";
		letterLine1 = "##  #";
		letterLine2 = "##  #";
		letterLine3 = "# # #";
		letterLine4 = "#  ##";
		letterLine5 = "#  ##";
		letterLine6 = "#   #";
	}
	else if (letter == 'o' || letter == 'O') {
		letterLine0 = " ### ";
		letterLine1 = "#   #";
		letterLine2 = "#   #";
		letterLine3 = "#   #";
		letterLine4 = "#   #";
		letterLine5 = "#   #";
		letterLine6 = " ### ";
	}
	else if (letter == 'p' || letter == 'P') {
		letterLine0 = "#### ";
		letterLine1 = "#   #";
		letterLine2 = "#   #";
		letterLine3 = "#### ";
		letterLine4 = "#    ";
		letterLine5 = "#    ";
		letterLine6 = "#    ";
	}
	else if (letter == 'q' || letter == 'Q') {
		letterLine0 = " ### ";
		letterLine1 = "#   #";
		letterLine2 = "#   #";
		letterLine3 = "#   #";
		letterLine4 = "# # #";
		letterLine5 = "#  # ";
		letterLine6 = " ## #";
	}
	else if (letter == 'r' || letter == 'R') {
		letterLine0 = "#### ";
		letterLine1 = "#   #";
		letterLine2 = "#   #";
		letterLine3 = "#### ";
		letterLine4 = "# #  ";
		letterLine5 = "#  # ";
		letterLine6 = "#   #";
	}
	else if (letter == 's' || letter == 'S') {
		letterLine0 = " ####";
		letterLine1 = "#    ";
		letterLine2 = "#    ";
		letterLine3 = " ### ";
		letterLine4 = "    #";
		letterLine5 = "    #";
		letterLine6 = "#### ";
	}
	else if (letter == 't' || letter == 'T') {
		letterLine0 = "#####";
		letterLine1 = "  #  ";
		letterLine2 = "  #  ";
		letterLine3 = "  #  ";
		letterLine4 = "  #  ";
		letterLine5 = "  #  ";
		letterLine6 = "  #  ";
	}
	else if (letter == 'u' || letter == 'U') {
		letterLine0 = "#   #";
		letterLine1 = "#   #";
		letterLine2 = "#   #";
		letterLine3 = "#   #";
		letterLine4 = "#   #";
		letterLine5 = "#   #";
		letterLine6 = " ### ";
	}
	else if (letter == 'v' || letter == 'V') {
		letterLine0 = "#   #";
		letterLine1 = "#   #";
		letterLine2 = "#   #";
		letterLine3 = "#   #";
		letterLine4 = "#   #";
		letterLine5 = " # # ";
		letterLine6 = "  #  ";
	}
	else if (letter == 'w' || letter == 'W') {
		letterLine0 = "#   #";
		letterLine1 = "#   #";
		letterLine2 = "#   #";
		letterLine3 = "#   #";
		letterLine4 = "# # #";
		letterLine5 = "## ##";
		letterLine6 = "#   #";
	}
	else if (letter == 'x' || letter == 'X') {
		letterLine0 = "#   #";
		letterLine1 = "#   #";
		letterLine2 = " # # ";
		letterLine3 = "  #  ";
		letterLine4 = " # # ";
		letterLine5 = "#   #";
		letterLine6 = "#   #";
	}
	else if (letter == 'y' || letter == 'Y') {
		letterLine0 = "#   #";
		letterLine1 = "#   #";
		letterLine2 = " # # ";
		letterLine3 = "  #  ";
		letterLine4 = "  #  ";
		letterLine5 = "  #  ";
		letterLine6 = "  #  ";
	}
	else if (letter == 'z' || letter == 'Z') {
		letterLine0 = "#####";
		letterLine1 = "    #";
		letterLine2 = "   # ";
		letterLine3 = "  #  ";
		letterLine4 = " #   ";
		letterLine5 = "#    ";
		letterLine6 = "#####";
	}
	else if (letter == '0') {
		letterLine0 = " ### ";
		letterLine1 = "#   #";
		letterLine2 = "#  ##";
		letterLine3 = "# # #";
		letterLine4 = "##  #";
		letterLine5 = "#   #";
		letterLine6 = " ### ";
	}
	else if (letter == '1') {
		letterLine0 = "  #  ";
		letterLine1 = " ##  ";
		letterLine2 = "# #  ";
		letterLine3 = "  #  ";
		letterLine4 = "  #  ";
		letterLine5 = "  #  ";
		letterLine6 = "#####";
	}
	else if (letter == '2') {
		letterLine0 = " ### ";
		letterLine1 = "#   #";
		letterLine2 = "    #";
		letterLine3 = "   # ";
		letterLine4 = "  #  ";
		letterLine5 = " #  ";
		letterLine6 = "#####";
	}
	else if (letter == '3') {
		letterLine0 = " ### ";
		letterLine1 = "#   #";
		letterLine2 = "    #";
		letterLine3 = "   # ";
		letterLine4 = "    #";
		letterLine5 = "#   #";
		letterLine6 = " ### ";
	}
	else if (letter == '4') {
		letterLine0 = "#   #";
		letterLine1 = "#   #";
		letterLine2 = "#   #";
		letterLine3 = "#####";
		letterLine4 = "    #";
		letterLine5 = "    #";
		letterLine6 = "    #";
	}
	else if (letter == '5') {
		letterLine0 = "#####";
		letterLine1 = "#    ";
		letterLine2 = "#    ";
		letterLine3 = "#### ";
		letterLine4 = "    #";
		letterLine5 = "    #";
		letterLine6 = "#### ";
	}
	else if (letter == '6') {
		letterLine0 = " ### ";
		letterLine1 = "#    ";
		letterLine2 = "#    ";
		letterLine3 = "#### ";
		letterLine4 = "#   #";
		letterLine5 = "#   #";
		letterLine6 = " ### ";
	}
	else if (letter == '7') {
		letterLine0 = "#####";
		letterLine1 = "    #";
		letterLine2 = "   # ";
		letterLine3 = "  # ";
		letterLine4 = "  #  ";
		letterLine5 = "  #  ";
		letterLine6 = "  #  ";
	}
	else if (letter == '8') {
		letterLine0 = " ### ";
		letterLine1 = "#   #";
		letterLine2 = "#   #";
		letterLine3 = " ### ";
		letterLine4 = "#   #";
		letterLine5 = "#   #";
		letterLine6 = " ### ";
	}
	else if (letter == '9') {
		letterLine0 = " ### ";
		letterLine1 = "#   #";
		letterLine2 = "#   #";
		letterLine3 = " ####";
		letterLine4 = "    #";
		letterLine5 = "    #";
		letterLine6 = " ### ";
	}
	else if (letter == '.') {
		letterLine0 = "     ";
		letterLine1 = "     ";
		letterLine2 = "     ";
		letterLine3 = "     ";
		letterLine4 = "     ";
		letterLine5 = "     ";
		letterLine6 = "  #  ";
	}
	else if (letter == ',') {
		letterLine0 = "     ";
		letterLine1 = "     ";
		letterLine2 = "     ";
		letterLine3 = "     ";
		letterLine4 = "     ";
		letterLine5 = "  #  ";
		letterLine6 = " #   ";
	}
	else if (letter == '!') {
		letterLine0 = "  #  ";
		letterLine1 = "  #  ";
		letterLine2 = "  #  ";
		letterLine3 = "  #  ";
		letterLine4 = "  #  ";
		letterLine5 = "     ";
		letterLine6 = "  #  ";
	}
	else if (letter == '?') {
		letterLine0 = " ### ";
		letterLine1 = "#   #";
		letterLine2 = "    #";
		letterLine3 = "   # ";
		letterLine4 = "  #  ";
		letterLine5 = "     ";
		letterLine6 = "  #  ";
	}
	else if (letter == ' ') {
		letterLine0 = "     ";
		letterLine1 = "     ";
		letterLine2 = "     ";
		letterLine3 = "     ";
		letterLine4 = "     ";
		letterLine5 = "     ";
		letterLine6 = "     ";
	}

	char* letterBytes[7];
	letterBytes[0] = letterLine0;
	letterBytes[1] = letterLine1;
	letterBytes[2] = letterLine2;
	letterBytes[3] = letterLine3;
	letterBytes[4] = letterLine4;
	letterBytes[5] = letterLine5;
	letterBytes[6] = letterLine6;
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 7; y++){
			if (letterBytes[y][x] == '#') {
				drawLed(color,brightness,starty+y,startx+x);
			}
		}

	}
}
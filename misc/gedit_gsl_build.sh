g++  -lgsl -lgslcblas -lm -I/usr/include  -o "${GEDIT_CURRENT_DOCUMENT_PATH%.*}" "$GEDIT_CURRENT_DOCUMENT_PATH" 
exec "${GEDIT_CURRENT_DOCUMENT_PATH%.*}"

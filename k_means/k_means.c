#include <stdio.h>
#include <jpeglib.h>

int main (int argc, char *argv[]){
	if (argc != 2){
		fprintf(stderr, "Usage: %s <input_file.jpg>\n", argv[0]);
		return 1;
	}
	
	const char *input_filename = argv[1];

	FILE *input_file = fopen(input_filename, "rb");
	if (!input_file) {
		fprintf(stderr, "Error: Could not open input file %s\n", input_filename);
		return 1;
	}

	struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;

	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_decompress(&cinfo);

	jpeg_stdio_src(&cinfo, input_file);
	jpeg_read_header(&cinfo, TRUE);
	jpeg_start_decompress(&cinfo);

	printf("Image width: %d\n", cinfo.output_width);
	printf("Image height: %d\n", cinfo.output_height);
	printf("Number of color components: %d\n", cinfo.out_color_components);

	jpeg_finish_decompress(&cinfo);
	jpeg_destroy_decompress(&cinfo);
	fclose(input_file);

	return 0;
}

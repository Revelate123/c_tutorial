#include <stdio.h>
#include <jpeglib.h>

int main (int argc, char *argv[]){
	if (argc != 2){
		fprintf(stderr, "Usage: %s <input_file.jpg>\n", argv[0]);
		return 1;
	}
	
	const char *input_filename = argv[1];

	FILE *input_file = fopen(input_filename, "rb");
	JSAMPARRAY buffer;
	int row_stride;

	if (!input_file) {
		fprintf(stderr, "Error: Could not open input file %s\n", input_filename);
		return 1;
	}

	/*First need to decompress JPEG file. Then perform operations on the data, e.g. k_means.
	 * Then finally recompress into new JPEG file. */

	/*IMPORTANT: JPEG's can be either in colour or in grayscale (three samples per pixel or one) */

	struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;

	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_decompress(&cinfo);


	jpeg_stdio_src(&cinfo, input_file);
	jpeg_read_header(&cinfo, TRUE);
	jpeg_start_decompress(&cinfo);
	
	row_stride = cinfo.output_width * cinfo.output_components;
	buffer = (*cinfo.mem->alloc_sarray)
		((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);
	
	int image_buffer[cinfo.output_width * cinfo.output_height * 3];
	int dest = 0;
	while (cinfo.output_scanline < cinfo.output_height)
	{
		jpeg_read_scanlines(&cinfo,buffer,1);
		for (int src=0;src<cinfo.output_width;src++)
		{
			image_buffer[dest*3] = buffer[0][src*3];
			image_buffer[dest*3+1] = buffer[0][src*3+1];
			image_buffer[dest*3+2] = buffer[0][src*3+2];	
			dest++;
		}
	}
	
	printf("%d\n",image_buffer[0]);	
	printf("Image width: %d\n", cinfo.output_width);
	printf("Image height: %d\n", cinfo.output_height);
	printf("Number of color components: %d\n", cinfo.out_color_components);
	printf("Number of color components per pixel: %d\n", cinfo.output_components);

	jpeg_finish_decompress(&cinfo);
	jpeg_destroy_decompress(&cinfo);
	fclose(input_file);

	return 0;
}

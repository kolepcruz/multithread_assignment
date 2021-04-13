#include "parser.h"

int parse_pbm_BW(FILE *filePointer, BW *image)
{
    // TODO verificar se o ponteiro não é nulo
    int number;
    for (int i = 0; i < image->size.height; i++)
    {
        for (int j = 0; j < image->size.width; j++)
        {
            number = getc(filePointer);
            while (number == '\n') //Ignore \n's
                number = getc(filePointer);
            if (number == EOF)
            {
                //TODO adicionar o erro errno =
                fprintf(stderr, "EOF found before it was espected");
                return -1;
            }
            image->pixels[i][j] = number - '0';
        }
    }
    return 0;
}

BW *open_pbm(char *image_name)
{
    // So, the file can be opened as
    FILE *filePointer = fopen(image_name, "r");
    if (!filePointer)
    {
        // errno = ENOENT; Não precisa fopen seta errno sozinho
        perror("Couldn't read the specified file");
        return NULL;
    }
    // BW *image = malloc(sizeof(RGB));

    int temp1 = fgetc(filePointer);
    int temp2 = fgetc(filePointer);
    if (temp1 == EOF || temp2 == EOF)
    {
        errno = ENOEXEC; /* Exec format error */
        perror("EOF found before magic number");
        fclose(filePointer);
        return NULL;
    }

    int magicNumber = 16 * 16 * temp1 + temp2; // 16*16 to move "casas para o lado"
    uint32_t width, height;
    BW *image;

    switch (magicNumber)
    {
    case P1:
        fscanf(filePointer, "%u %u", &width, &height);
        image = new_BW_fast_image(width, height);
        parse_pbm_BW(filePointer, image);
        break;
    case P2:
    case P3:
    case P4:
    case P5:
    case P6:
        errno = ENOEXEC; /* Exec format error */
        perror("raw/binary or grayscale/RBR not implemented");
        fclose(filePointer);
        return NULL;
        break;
    default:
        errno = ENOEXEC; /* Exec format error */
        perror("Not a valid pbm file!");
        fclose(filePointer);
        return NULL;
        break;
    }

    return image;
}

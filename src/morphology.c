#include "morphology.h"

bool prepare_algorithm(uint32_t kernel_size, BW *image, BW *result)
{
    if (image == NULL)
    {
        perror("Received Null Pointer");
        exit(EXIT_FAILURE);
    }

    uint32_t x_len = image->size.width;
    uint32_t y_len = image->size.height;

    if (kernel_size * kernel_size >= x_len * y_len)
    {
        perror("Kernel Size too big for operation!");
        exit(EXIT_FAILURE);
    }

    printf("Initializing algorithm Kernel");
    BW *kernel;
    kernel = init_kernel(kernel_size);
    bool exact_fit = !(y_len % 10);
    uint32_t n_threads = y_len / 5;
    pthread_t threads = malloc(n_threads * sizeof(pthread_t));

    result = copy_image(image);

    apply_erosion(image, 0, y_len, kernel, result);

  
    // if(exact_fit){

    // }

    // else{

    // }
    return true;
}
bool *apply_erosion(BW *image, uint32_t starting_y, uint32_t extraleny, BW *kernel, BW *result)
{
    int32_t kradius = (int32_t)kernel->size.width / 2;
    int32_t x_len = image->size.width;
    printf("BEFORE PROCESSING THE IMAGE\n");

    for (uint32_t i = 0; i < image->size.height; i++)
    {
        for (uint32_t j = 0; j < image->size.width; j++)
        {
            printf("%u ", result->pixels[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");


    //kernel center is at kernel->pixels[kradius][kradius]
    for (int32_t y = starting_y + kradius; y < starting_y + extraleny - kradius; ++y)
    {
        for (int32_t x = kradius; x < x_len - kradius; x++)
        {
            // printf("Checking image at %d %d\n",y,x);
            {
                if (image->pixels[y][x] == BLACK)
                // printf("Found 0 at %d %d\n",y,x);
                for (int32_t i = y - kradius; i <= y + kradius; ++i)
                {
                    for (int32_t j = x - kradius; j <= x + kradius; ++j)
                    {
                        result->pixels[i][j] = BLACK;
                    }
                }
            }
        }
    }
    for (uint32_t i = 0; i < image->size.height; i++)
    {
        for (uint32_t j = 0; j < image->size.width; j++)
        {
            printf("%u ", result->pixels[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    return true;
    }

    // BW* iteration_loop();

    // BW* apply_dilation(BW *image, uint32_t startx, uint32_t starty,
    //                    uint32_t extralenx, uint32_t extraleny, uint32_t kernel_size)
    // {
    //     printf("Applying dilation algorithm\n");

    //     printf("SUCCESS!!!\nPRINTING RESULT ...\n\n");
        // for (uint32_t i = 0; i < image->size.height; i++)
        // {
        //     for (uint32_t j = 0; j < image->size.width; j++)
        //     {
        //         printf("%u ", result->pixels[i][j]);
        //     }
        //     printf("\n");
        // }

    //     return result;

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

    // printf("Initializing algorithm Kernel");
    BW *kernel;
    kernel = init_kernel(kernel_size);
    bool exact_fit = true; //!(y_len % 10);
    uint32_t n_threads = 4;
    pthread_t *threads = malloc(n_threads * sizeof(pthread_t));

    result = copy_image(image);

    for (int i = 0; i < image->size.height; i++)
    {
        for (int j = 0; j < image->size.width; j++)
        {
            printf("%d", result->pixels[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    if (exact_fit)
    {
        for (uint32_t n = 0; n < n_threads; ++n)
        {
            ME_args *args;
            args = malloc(sizeof(ME_args));
            args->image = image;
            args->kernel = kernel;

            args->starting_y = n * y_len/n_threads;
            args->extraleny = y_len/n_threads ;

            args->result = result;
            if (pthread_create(&threads[n], NULL, apply_erosion, (void *)(args)) != 0)
            {
                perror("Unable to create Thread");
                exit(EXIT_FAILURE);
            }
        }
        for (uint32_t t = 0; t < n_threads; t++)
        {
            pthread_join(threads[t], NULL);
        }
    }

    for (int i = 0; i < image->size.height; i++)
    {
        for (int j = 0; j < image->size.width; j++)
        {
            printf("%d", result->pixels[i][j]);
        }
        printf("\n");
    }

    return true;
}
void *apply_erosion(void *args)
{
    BW *image = ((ME_args *)args)->image;
    uint32_t starting_y = ((ME_args *)args)->starting_y;
    uint32_t extraleny = ((ME_args *)args)->extraleny;
    BW *kernel = ((ME_args *)args)->kernel;
    BW *result = ((ME_args *)args)->result;

    int32_t kradius = (int32_t)kernel->size.width / 2;
    int32_t x_len = image->size.width;

    //kernel center is at kernel->pixels[kradius][kradius]
    for (int32_t y = starting_y; y < starting_y + extraleny; ++y)
    {
        if(!(y < kradius) && !(y > image->size.height - kradius -1 )){ // Sacergod
            for (int32_t x = kradius; x < x_len - kradius; x++)
            {
                if (image->pixels[y][x] == BLACK)
                {
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
    } 
}
#include <stdlib.h>

#include <singly_linked.h>

int alloc_frame(List *frames);
int free_frame(List *frames, int frame_number);

int main(int argc, char **argv)
{
    return 0;
}

int alloc_frame(List *frames)
{
    int frame_number;
    int *data;

    if (list_size(frames) == 0)
    {
        return -1;
    }
    else
    {
        if (list_rem_next(frames, NULL, (void **)&data) != 0)
        {
            // frame could not be retrieved.
            return -1;
        }
        else
        {
            // store the number of the available frame.
            frame_number = *data;
            free(data);
        }
    }

    return frame_number;
}

int free_frame(List *frames, int frame_number)
{
    int *data = (int *)malloc(sizeof(int));

    if (data == NULL)
    {
        return -1;
    }

    // put them back in the list of available frames.
    *data = frame_number;

    if (list_ins_next(frames, NULL, data) != 0)
    {
        return -1;
    }

    return 0;
}

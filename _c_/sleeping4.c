 #include <stdlib.h>
    #include <stdio.h>
    #include <pthread.h>
    #include <time.h>

    #define TRUE 1

    pthread_mutex_t mutex;
    pthread_cond_t fill;

    int counter;

    int* buffer;
    int size;

    void* producer(void*);
    void* consumer(void*);

    void initialize_variables();
    void insert(void);
    void remove_item(void);

    int main(int argc, char *argv[]) {

        int random_num;
        int num=0;
        pthread_t barber;

        srand( time(NULL) );

        if(argc!=2){
            printf("Not enough parameters\n");
            exit(0);
        }

        size=atoi(argv[1]);

        initialize_variables();

        pthread_create(&barber,NULL,consumer,NULL);

        while(TRUE){

            pthread_t customer;
            pthread_create(&customer,NULL,producer,NULL);

        }

        printf("Exit the program\n");
        return 0;
    }

    void initialize_variables(){

        int i;

        if(! (buffer=(int*)malloc(size*sizeof(int))) ){
            printf("Error while allocating memory for buffer\n");
            exit(1);
        }

        for(i=0; i<size; i++)
            buffer[i]=0;

        pthread_mutex_init(&mutex,NULL);

        pthread_cond_init(empty, NULL);
        pthread_cond_init(&fill, NULL);

        counter = 0;
    }

  void* producer(void* arg){

    pthread_mutex_lock(&mutex);

        while(counter==size)
            pthread_cond_wait(&empty,&mutex);

        printf("One Customer has arrived and sit on the  #%d chair\n", counter);
        insert();
        sleep(1);
        pthread_cond_signal(&fill);

    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

void* consumer(void* arg){

    while(TRUE){

        pthread_mutex_lock(&mutex);

            while(counter==0){
                printf("Barber is sleeping now\n");
                pthread_cond_wait(&fill,&mutex);
            }

            remove_item();
            sleep(1);
            pthread_cond_broadcast(&empty);

        pthread_mutex_unlock(&mutex);

    }
}

void insert(void){

    buffer[counter]=1;
    counter++;
}

void remove_item(void){

    buffer[counter]=0;
    printf("The barber is started to cut the hair of the customer at chair #%d\n", counter);
    counter--;
}

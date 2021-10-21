#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <stdint.h>
#include "../queue/queue.h"

void  SC(Queue *arrivedQ, Queue *waitingQ)
{
  int arrivedTime = 0;
  float average = 0;
  int cnt = 1;
  int service = 0;
  int i;
  SimCustomer *SC;
  while(!isEmpty(waitingQ))
  {
    if(!service && !isEmpty(waitingQ))
    {
      SC = deQueue(waitingQ);
      printf("%d번째 고객 도착 시작 %d초\n", cnt, SC->arrivalTime);
      if (arrivedTime < SC->arrivalTime)
        arrivedTime = SC->arrivalTime;
      printf("%d번째 고객 서비스 시작 %d초\n", cnt, arrivedTime);
      service = 1;
    }
    if(service)
    {
      SC->endTime = SC ->serviceTime + arrivedTime;
      average += SC->endTime - SC->arrivalTime;
      arrivedTime = SC->endTime;
      printf("%d번째 고객 서비스 종료 %d초\n", cnt, SC->endTime);
      service =0;
      cnt++;
      free(SC);
    }
    printf("\n");
    i++;
    }
    printf("평균 서비스 시간: %f\n", (float)(average/(cnt -1)));
}

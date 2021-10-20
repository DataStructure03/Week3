#ifndef CUSTOMER_H
#define CUSTOMER_H

typedef enum SimStatusType
{
	arrival, start, end
}	SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime;
	int serviceTime;
	int startTime;
	int endTime;
}	SimCustomer;

#endif

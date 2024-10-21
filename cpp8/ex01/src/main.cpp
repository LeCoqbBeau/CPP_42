//
// Created by mscheman on 8/16/24.
//

#include <unistd.h>
#include <Span.h>

#define SPAN_SIZE 10
#define SPAN_SIZE_HALF (SPAN_SIZE / 2)

int	main()
{
	{
		Span	small(SPAN_SIZE);

		for (int i = 0; i < SPAN_SIZE_HALF; ++i) {
			small.addNumber(1 + i);
		}

		const t_intListIt &start = small.getList().begin();
		const t_intListIt &finish =  small.getList().end();

		small.addNumber(start, finish);

		NEWL;
		small.print();
		NEWL;

		PRINT BCYN "Shortest small's span: " CLR AND small.shortestSpan() ENDL;
		PRINT BCYN "Longest small's span: " CLR AND small.longestSpan() ENDL;
	}
//	sleep(3);
//	NEWL;
//	{
//		Span	huge(SPAN_SIZE * 1e5);
//
//		huge.fillMemory();
//
//		NEWL;
//		huge.print();
//		NEWL;
//
//		PRINT BCYN "Shortest small's span: " CLR AND huge.shortestSpan() ENDL;
//		PRINT BCYN "Longest huge's span: " CLR AND huge.longestSpan() ENDL;
//	}
}

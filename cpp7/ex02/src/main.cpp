//
// Created by mscheman on 8/16/24.
//

#include <iostream>

#include "iter.h"
#include "array.h"
#include "colors.h"
#include "printUtils.h"


typedef enum e_zone {
	ALPHA = 0,
	BRAVO,
	CHARLIE,
	DELTA,
	ECHO,
	E_ZONE_END
}	t_zone;

typedef struct s_drill {
	s_drill() : sector(E_ZONE_END), output(0), type("None") {};
	s_drill(t_zone zone, size_t veinDensity, const std::string &ore)
			: sector(zone), output(veinDensity), type(ore) {};
	t_zone		sector;
	size_t		output;
	std::string	type;
}	t_drill;

static std::string zoneToStr(t_zone zone);
static void printDrill(const t_drill &drill);

int main() {
	Array<t_drill> drills(5);

	NEWL;
	PRINT BPRP "-----[ Initiating Sector Alpha Expansion Process ]-----" CLR ENDL;
	NEWL;

	PRINT PRP " Producing drills, number expected: 10" CLR ENDL;
	for (int i = 0; i < 10; ++i) {
		try {
			drills[i] = t_drill(ALPHA, 70, "Diamond");
			PRINT "  Successfully produced drill number " AND i ENDL;
		} catch (std::exception &e) {
			ERROR BRED "  Not enough resources for drill number " AND i AND CLR ENDL;
		}
	}
	PRINT PRP " Produced and deployed " CLR AND drills.size() AND PRP " drills on ALPHA" CLR ENDL;

	NEWL;
	PRINT PRP " Now examining all new drills behaviour:" CLR ENDL;
	::iter(drills.data(), drills.size(), printDrill);

	NEWL;
	PRINT BPRP "-----[ Terminated Sector Alpha Expansion Process ]-----" CLR ENDL;
	NEWL;
}

static std::string zoneToStr(t_zone zone) {
	switch (zone) {
		case ALPHA:
			return "ALPHA";
		case BRAVO:
			return "BRAVO";
		case CHARLIE:
			return "CHARLIE";
		case DELTA:
			return "DELTA";
		case ECHO:
			return "ECHO";
		case E_ZONE_END:
			return "UNKNOWN";
	}
}

static void printDrill(const t_drill &drill) {
	PRINT TAB;
	PRINT BYLW "Drill on " CLR AND zoneToStr(drill.sector);
	PRINT BYLW " producing " CLR AND  drill.output AND " " AND drill.type ;
	PRINT BYLW "/day." CLR;
	NEWL;
}

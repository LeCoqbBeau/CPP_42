//
// Created by mscheman on 8/16/24.
//

#include <iostream>

#include "iter.h"
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
	inline s_drill(t_zone zone, size_t veinDensity, const std::string &ore)
	: sector(zone), output(veinDensity), type(ore) {};
	t_zone		sector;
	size_t		output;
	std::string	type;
}	t_drill;

static void printZone(t_zone zone);
static std::string zoneToStr(t_zone zone);

static void printDrill(const t_drill &drill);

int main() {
	t_zone availableZone[] = {
			ALPHA,
			BRAVO,
			CHARLIE,
			DELTA,
			ECHO,
	};

	const t_drill workingDrills[] = {
			s_drill(ALPHA, 51, "Diamond"),
			s_drill(ALPHA, 60, "Diamond"),
			s_drill(BRAVO, 3, "Uranium"),
			s_drill(BRAVO, 9, "Uranium"),
			s_drill(CHARLIE, 79, "Gold"),
			s_drill(CHARLIE, 62, "Gold"),
			s_drill(DELTA, 956, "Coal"),
			s_drill(DELTA, 840, "Coal"),
			s_drill(ECHO, 146, "Iron"),
			s_drill(ECHO, 155, "Iron"),
	};

	NEWL;
	PRINT BPRP "-----[ Initiating Advanced Mining Zone Analysis ]-----" CLR ENDL;
	NEWL;
	PRINT PRP " Now listing all producing sectors:" CLR ENDL;
	::iter(availableZone, 5, printZone);
	NEWL;
	PRINT PRP " Now examining all drills on all zones:" CLR ENDL;
	::iter(workingDrills, 10, printDrill);
	NEWL;
	PRINT BPRP "-----[ Terminated Advanced Mining Zone Analysis ]-----" CLR ENDL;
	NEWL;
}

static void printZone(t_zone zone) {
	PRINT TAB "- " AND zoneToStr(zone) ENDL;
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

//
// Created by mscheman on 8/16/24.
//

#include "utils.h"
#include "iter.h"

typedef enum e_zone {
	ALPHA = 0,
	BRAVO,
	CHARLIE,
	DELTA,
	ECHO,
	E_ZONE_END
}	t_zone;

typedef struct s_drill {
	// Constructor
	inline s_drill(const t_zone zone, const size_t veinDensity, str cref ore)
		: sector(zone), output(veinDensity), type(ore) {};

	// Attributes
	t_zone	sector;
	size_t	output;
	str		type;
}	t_drill;

static void printZone(t_zone zone);
static str zoneToStr(t_zone zone);

static void printDrill(t_drill cref drill);

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
	PRINT PRP BOLD "-----[ Initiating Advanced Mining Zone Analysis ]-----" CENDL;
	NEWL;
	PRINT PRP " Now listing all producing sectors:" CENDL;
	::iter(availableZone, 5, printZone);
	NEWL;
	PRINT PRP " Now examining all drills on all zones:" CENDL;
	::iter(workingDrills, 10, printDrill);
	NEWL;
	PRINT PRP BOLD "-----[ Terminated Advanced Mining Zone Analysis ]-----" CENDL;
	NEWL;
}

static void printZone(const t_zone zone) {
	PRINT TAB "- " AND zoneToStr(zone) ENDL;
}

static std::string zoneToStr(const t_zone zone) {
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
		default:
			return "HOLY JESUS";
	}
}

static void printDrill(t_drill cref drill) {
	PRINT TAB;
	PRINT YLW BOLD "Drill on " CLR AND zoneToStr(drill.sector);
	PRINT YLW BOLD " producing " CLR AND drill.output AND " " AND drill.type ;
	PRINT YLW BOLD "/day." CLR;
	NEWL;
}

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
	inline s_drill(const t_zone zone = ALPHA, const size_t veinDensity = 0, str cref ore = "Nothing")
		: sector(zone), output(veinDensity), type(ore) {};

	// Attributes
	t_zone	sector;
	size_t	output;
	str		type;
}	t_drill;

static void printZone(t_zone zone);
static str zoneToStr(t_zone zone);
static void examine(t_drill cref drill);
static void boost(t_drill ref drill);

int main() {
	t_zone availableZone[] = {
			ALPHA,
			BRAVO,
			CHARLIE,
			DELTA,
			ECHO,
	};

	const t_drill constWorkingDrills[] = {
			s_drill(ALPHA, 50, "Diamond"),
			s_drill(ALPHA, 60, "Diamond"),
			s_drill(BRAVO, 5, "Uranium"),
			s_drill(BRAVO, 10, "Uranium"),
			s_drill(CHARLIE, 80, "Gold"),
			s_drill(CHARLIE, 60, "Gold"),
			s_drill(DELTA, 950, "Coal"),
			s_drill(DELTA, 850, "Coal"),
			s_drill(ECHO, 140, "Iron"),
			s_drill(ECHO, 160, "Iron"),
	};

	t_drill workingDrills[10];
	std::copy(constWorkingDrills, constWorkingDrills + 10, workingDrills);


	NEWL;
	PRINT PRP BOLD "-----[ Initiating Advanced Mining Zone Analysis ]-----" CENDL;
	NEWL;
	PRINT PRP " Now listing all producing sectors:" CENDL;
	::iter(availableZone, 5, printZone);
	NEWL;
	PRINT PRP " Now examining all drills on all zones:" CENDL;
	::iter(constWorkingDrills, 10, examine);
	NEWL;
	PRINT PRP " Now boosting all drills on all zones:" CENDL;
	::iter(workingDrills, 10, boost);
	::iter(workingDrills, 10, examine);
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

static void examine(t_drill cref drill) {
	PRINT TAB;
	PRINT CYN BOLD "Drill on " CLR AND zoneToStr(drill.sector);
	PRINT CYN BOLD " producing " CLR AND drill.output AND " " AND drill.type ;
	PRINT CYN BOLD "/day." CLR;
	NEWL;
}

static void boost(t_drill ref drill) {
	drill.output *= 2;
}
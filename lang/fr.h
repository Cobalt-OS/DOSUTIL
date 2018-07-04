/* fr.h - DOS Coreutils French Language header file
   Written by Atnode. */


#define FR 3

#if LANGUAGE == FR
   #define STRING_BASE64_ARGUMENTS "  -d, --decode          decode data\r\n  -i, --ignore-garbage  when decoding, ignore non-alphabet characters\r\n  -w, --wrap=COLS       wrap encoded lines after COLS character (default 76).\r\n                        Use 0 to disable line wrapping\r\n\r\n"
   #define STRING_BASE64_CLOSING_STANDARD_INPUT "closing standard input"
   #define STRING_BASE64_DESCRIPTION "\r\nThe data are encoded as described for the %s alphabet in RFC 4648.\r\nWhen decoding, the input may contain newlines in addition to the bytes of\r\nthe formal %s alphabet.  Use --ignore-garbage to attempt to recover\r\nfrom any other non-alphabet bytes in the encoded stream.\r\n"
   #define STRING_BASE64_EXTRA_OPERAND "extra operand %s"
   #define STRING_BASE64_INVALID_INPUT "invalid input"
   #define STRING_BASE64_INVALID_WRAP_SIZE "invalid wrap size"
   #define STRING_BASE64_READ_ERROR "read error"
   #define STRING_BASE64_USAGE "Usage: %s [OPTION]... [FILE]\r\nBase%d encode or decode FILE, or standard input, to standard output.\r\n"
   #define STRING_BASE64_WRITE_ERROR "write error"
   #define STRING_BEEP_FREQUENCY "  -f Fr‚quence : Sp‚cifie la fr‚quence du son."
   #define STRING_BEEP_LENGTH "  -l Longueur : Sp‚cifie la longueur du son en millisecondes."
   #define STRING_BEEP_USAGE "  beep [Options]"
   #define STRING_BEEP_DESCRIPTION "beep - Emettre un bip depuis le haut-parleur interne de l'ordinateur."
   #define STRING_CAN_NOT_COPY "%s ne peut ˆtre copi‚.\r\n"
   #define STRING_CAT_DESCRIPTION  "cat - Afficher le contenu d'un fichier."
   #define STRING_CAT_ENDS "  -E: Les caractŠres de fin de ligne sont affich‚s avec le symbole \"$\"."
   #define STRING_CAT_TABS "  -T: Les tabulations sont affich‚s avec le symbole \"^I\"."
   #define STRING_CAT_USAGE "  cat [Options] Fichiers"
   #define STRING_CLEAR_DESCRIPTION "clear - Effacer l'‚cran du terminal."
   #define STRING_CP_DESCRIPTION "cp - Copier un fichier ou un r‚pertoire sp‚cifi‚ dans un r‚pertoire sp‚cifi‚."
   #define STRING_CP_USAGE "  cp Source Destination"
   #define STRING_DATE_DEFAULT_FORMAT "        Le format par d‚faut est le format ISO."
   #define STRING_DATE_DESCRIPTION "date - Afficher ou d‚finir la date et l'heure du systŠme."
   #define STRING_DATE_EXAMPLE_FORMAT "  Example: \"%d-%d-%d %d:%d%:%d\""
   #define STRING_DATE_FORMAT "Format  Sp‚cifie la chaŒne de sortie format‚e. Le format de chaŒne est de type C printf."
   #define STRING_DATE_SET_TIME_AND_DATE "  -s: D‚finir la date et l'heure du systŠme."
   #define STRING_DATE_USAGE_1 "  date [Format]"
   #define STRING_DATE_USAGE_2 "  date -s [Format]"
   #define STRING_DIRNAME_ZERO "  -z, --zero: Terminer chaque ligne de sortie avec NUL, pas de retour … la ligne."
   #define STRING_DIRNAME_DESCRIPTION "dirname - Supprimer le suffixe du nom de fichier."
   #define STRING_DIRNAME_EXAMPLE_1 "  dirname C:\\dir1\\dir2          -> \"C:\\dir1\""
   #define STRING_DIRNAME_EXAMPLE_2 "  dirname dir1\\str dir2\\str     -> \"dir1\" suivi de \"dir2\""
   #define STRING_DIRNAME_EXAMPLE_3 "  dirname autoexec.bat          -> \".\""
   #define STRING_DIRNAME_USAGE_1 "dirname [Option] Nom..."
   #define STRING_DIRNAME_USAGE_2 "Affiche chaque NOM en supprimant son dernier composant et sa barre oblique finale"
   #define STRING_DIRNAME_USAGE_3 "si NOM ne contient pas de '\\', la sortie sera '.' (signifant le r‚pertoire actuel)."
   #define STRING_ECHO_CHARACTERS_ARE "    les caractŠres sont : \\a \\b \\c \\e \\f \\r \\t \\v"
   #define STRING_ECHO_DESCRIPTION "echo - Afficher des caratŠres sp‚cifique."
   #define STRING_ECHO_NEWLINE_CHARACTER "-n  Affiche en plus les caratŠres de nouvelles lignes."
   #define STRING_ECHO_SPECIAL_CHARACTERS "-e  Affiche des caractŠres sp‚ciaux. Le message doit ˆtre entre guillemets."
   #define STRING_ECHO_USAGE "  echo [Options] Messages"
   #define STRING_EMIT_TRY_HELP "Essayez '%s --help' pour plus d'informations.\n"
   #define STRING_EXAMPLES "Examples :"
   #define STRING_FALSE_DESCRIPTION "false - Retourner un ‚chec."
   #define STRING_DOES_NOT_DIRECTORY "%s n\'est pas un r‚pertoire\r\n"
   #define STRING_DOS_COREUTILS_VERSION "DOS Coreutils Version: 0.6"
   #define STRING_HELP_DOS_COREUTILS_COMMANDS "Commandes de DOS Coreutils :\r\n"
   #define STRING_HELP_OPTION_DESCRIPTION "  --help: Affiche l'aide de la commande."
   #define STRING_INVALID_SYNTAX "Syntaxe invalide."
   #define STRING_LS_DESCRIPTION "ls - Liste le contenu d'un r‚pertoire."
   #define STRING_LS_DISPLAY_LONG_LISTING_FORMAT "-l  Utilise le long format d\'affichage."
   #define STRING_LS_DISPLAY_OUTPUT_AS_ONE_COLUMN "-1  Affiche un fichier par ligne."
   #define STRING_LS_DO_NOT_IGNORE "-a  Ne pas ignorer les entr‚es d‚butant par \".\" et \"..\"."
   #define STRING_LS_USAGE "  ls [Options] [Fichiers]"
   #define STRING_MISSING_OPERAND "Op‚rande manquant.\n"
   #define STRING_MKDIR_CAN_NOT_CREATE_DIRECTORY "Le r‚pertoire %s ne peut pas ˆtre cr‚‚.\r\n"
   #define STRING_MKDIR_DESCRIPTION "mkdir - Cr‚er des r‚pertoires."
   #define STRING_MKDIR_USAGE "  mkdir R‚pertoire"
   #define STRING_MV_CAN_NOT_MOVE "Le r‚pertoire ou le fichier %s ne peut pas ˆtre d‚plac‚.\r\n"
   #define STRING_MV_DESCRIPTION_1 "mv - D‚placer et/ou renommer un r‚pertoire ou un ficher"
   #define STRING_MV_DESCRIPTION_2 "vers un r‚pertoire."
   #define STRING_MV_USAGE "  mv Source Destination"
   #define STRING_NO_ENOUGH_ARGUMENTS "Pas assez d'arguments.\r\n"
   #define STRING_NOTE "Remarque :"
   #define STRING_OPTION "Option :"
   #define STRING_OPTIONS "Options :"
   #define STRING_PWD_DESCRIPTION "pwd - Affiche le nom du r‚pertoire actuel."
   #define STRING_RM_CAN_NOT_REMOVE "%s ne peut pas ˆtre supprim‚.\r\n"
   #define STRING_RM_DESCRIPTION "rm - Supprimer des fichiers."
   #define STRING_RM_REMOVE_RECURSIVELY "-r  Supprimer un r‚pertoire et son contenu de maniŠre r‚cursive."
   #define STRING_RM_USAGE "  rm [-r] R‚pertoire/Fichier"
   #define STRING_RMDIR_CAN_NOT_REMOVE "Le r‚pertoire %s ne peut pas ˆtre supprimer.\r\n"
   #define STRING_RMDIR_DESCRIPTION "rmdir - Supprimer un r‚pertoire"
   #define STRING_RMDIR_USAGE "  rmdir R‚pertoires"
   #define STRING_SH_DESCRIPTION "sh - Shell de DOS Coreuils"
   #define STRING_SH_TYPE_EXIT "  Dans le shell de DOS Coreutils, tapez \"exit\" pour quitter le shell."
   #define STRING_TIME_ARGUMENTS "  time Commande [Argument]"
   #define STRING_TIME_DESCRIPTION "time - Mesurer le temps d'ex‚cution de la commande sp‚cifi‚e en seconde."
   #define STRING_TRUE_DESCRIPTION "true - Retourner un succŠs."
   #define STRING_TOO_MUCH_ARGUMENTS "Trop d'arguments.\r\n"
   #define STRING_VERSION_OPTION_DESCRIPTION "  --version: Affiche la version actuelle de DOS Coreutils."
#endif

// sync'ed with help_mp-en.h 1.56
// Updates & fixes by pl <p_l@gmx.fr>
// Original transation by Firebird <firebird@chez.com>

// ========================= Aide MPlayer ===========================

#ifdef HELP_MP_DEFINE_STATIC
static char* banner_text=
"\n\n"
"MPlayer " VERSION "(C) 2000-2002 Arpad Gereoffy (lisez les DOCS!)\n"
"\n";

static char help_text[]=
"Utilisation:   mplayer [options] [r�pertoire/]fichier\n"
"\n"
"Options de base (voir la page man pour TOUTES les autres options):\n"
" -vo <pil[:p�r]>  S�l. le pil. et le p�riph. vid�o ('-vo help' pour la liste)\n"
" -ao <pil[:p�r]>  S�l. le pil. et le p�riph. audio ('-ao help' pour la liste)\n"
#ifdef HAVE_VCD
" -vcd <n�piste>   Joue � partir d'un VCD plut�t que d'un fichier\n"
#endif
#ifdef HAVE_LIBCSS
" -dvdauth <p�r>   Pr�cise le chemin du lecteur DVD (pour les DVD crypt�s)\n"
#endif
#ifdef USE_DVDREAD
" -dvd <nrtitre>   Joue � partir du lecteur DVD plut�t que d'un fichier\n"
" -alang/-slang    S�lectionne la langue pour l'audio/les sous-titres (fr,en,...)\n"
#endif
" -ss <temps>      D�marre la lecture � 'temps' (temps en secondes ou hh:mm:ss)\n"
" -nosound         Ne joue aucun son\n"
" -fs -vm -zoom    Options plein-�cran (fs: plein-�cran, vm: changement de mode\n"
"                  vid�o, zoom: changement de taille software)\n"
" -x <x> -y <y>    R�solution de l'affichage (chgts. de mode vid�o ou zoom soft)\n"
" -sub <fich>      Sp�cifie les sous-titres � utiliser (cf. -subfps, -subdelay)\n"
" -playlist <fich> Sp�cifie la liste des fichiers � jouer\n"
" -vid x -aid y    Sp�cifie les flux vid�os (x) et audio (y) � jouer\n"
" -fps x -srate y  Options pour changer les fr�q. vid�o (x fps) et audio (y Hz)\n"
" -pp <qualit�>    Filtres de sorties (voir page man et les docs)\n"
" -framedrop       \"Drop\" d'images (pour les machines lentes)\n"
"\n"
"Fonctions au clavier: (voir la page man et regarder dans input.conf)\n"
" <- ou ->         + / - 10 secondes\n"
" haut ou bas      + / - 1 minute\n"
" PgUp ou PgDown   + / - de 10 minutes\n"
" < ou >           Fichier suivant / pr�c�dent dans la playlist\n"
" p ou ESPACE      Pause (presser n'importe quelle touche pour continuer)\n"
" q ou ESC         Quitter\n"
" + ou -           Synchro audio / vid�o: +/- 0.1 seconde\n"
" o                Change l'OSD: rien / barre de recherche / barre rech. + temps\n"
" * ou /           Augmente/diminue le volume PCM\n"
" z ou x           Synchro des sous-titres: +/- 0.1 seconde\n"
" r ou t           Pos. des sous-titres: plus haut/plus bas (cf. -vop expand !)\n"
"\n"
" *** VOIR LA PAGE MAN POUR LES DETAILS ET LES AUTRES OPTIONS (AVANCEES) ***\n"
"\n";
#endif

// ========================= Messages MPlayer ===========================

// mplayer.c: 

#define MSGTR_Exiting "\nSortie... (%s)\n"
#define MSGTR_Exit_quit "Fin"
#define MSGTR_Exit_eof "Fin du fichier"
#define MSGTR_Exit_error "Erreur fatale"
#define MSGTR_IntBySignal "\nMPlayer interrompu par le signal %d dans le module: %s \n"
#define MSGTR_NoHomeDir "Ne peut trouver r�pertoire HOME\n"
#define MSGTR_GetpathProblem "Probl�me get_path(\"config\")\n"
#define MSGTR_CreatingCfgFile "Cr�ation du fichier de config: %s\n"
#define MSGTR_InvalidVOdriver "Nom du pilote de sortie vid�o invalide: %s\nUtiliser '-vo help' pour avoir une liste des pilotes disponibles.\n"
#define MSGTR_InvalidAOdriver "Nom du pilote de sortie audio invalide: %s\nUtiliser '-ao help' pour avoir une liste des pilotes disponibles.\n"
#define MSGTR_CopyCodecsConf "Copiez/liez etc/codecs.conf (dans le source de MPlayer) vers ~/.mplayer/codecs.conf)\n"
#define MSGTR_CantLoadFont "Ne peut charger la police: %s\n"
#define MSGTR_CantLoadSub "Ne peut charger les sous-titres: %s\n"
#define MSGTR_ErrorDVDkey "Erreur avec la cl� du DVD.\n"
#define MSGTR_CmdlineDVDkey "La cl� DVD demand�e sera utilis�e pour le d�cryptage.\n"
#define MSGTR_DVDauthOk "La s�quence d'authentification DVD semble OK.\n"
#define MSGTR_DumpSelectedSteramMissing "dump: FATAL: le flux s�lectionn� est manquant\n"
#define MSGTR_CantOpenDumpfile "Ne peut ouvrir un fichier dump!!!\n"
#define MSGTR_CoreDumped "core dumped :)\n"
#define MSGTR_FPSnotspecified "FPS non sp�cifi� (ou invalide) dans l'ent�te! Utiliser l'option -fps!\n"
#define MSGTR_TryForceAudioFmtStr "Tente de forcer famille de pilotes codec audio de famille %d ...\n"
#define MSGTR_CantFindAfmtFallback "Ne peut trouver de codec audio pour famille de pilotes impos�e, utilisation d'autres.\n"
#define MSGTR_CantFindAudioCodec "Ne peut trouver codec pour format audio 0x%X !\n"
#define MSGTR_TryUpgradeCodecsConfOrRTFM "*** Tentez de mettre � jour %s � partir de etc/codecs.conf\n*** Si ce n'est toujours pas bon, alors lisez DOCS/codecs.html!\n"
#define MSGTR_CouldntInitAudioCodec "Ne peut trouver de codec audio! -> Aucun son\n"
#define MSGTR_TryForceVideoFmtStr "Tente de forcer famille de pilotes codec vid�o %d ...\n"
#define MSGTR_CantFindVideoCodec "Ne peut trouver codec pour format vid�o 0x%X !\n"
#define MSGTR_VOincompCodec "D�sol�, le pilote de sortie vid�o choisi n'est pas compatible avec ce codec.\n"
#define MSGTR_CannotInitVO "FATAL: Ne peut initialiser le pilote vid�o!\n"
#define MSGTR_CannotInitAO "Ne peut ouvrir/initialiser le p�riph�rique audio -> Aucun son\n"
#define MSGTR_StartPlaying "D�marre la reproduction...\n"
#define MSGTR_SystemTooSlow "\n***********************************************************************"\
			    "\n** Votre syst�me est trop lent. Essayez l'option -framedrop ou RTFM! **"\
			    "\n***********************************************************************\n"\
			    "!!! Raisons possibles, probl�mes, solutions: \n"\
			    "- Le plus probable: pilote audio _bugg�_ => essayer -ao sdl ou\n"\
			    "  ALSA 0.5 ou l'�mulation OSS d'ALSA 0.9 => lire DOCS/sound.html\n"\
			    "- Vid�o lente => essayer avec plusieurs pilotes -vo (pour la liste: -vo help) ou\n"\
			    "  avec -framedrop => lire DOCS/video.html\n"\
			    "- CPU lent => �viter les gros DVD/DivX => essayer -hardframedrop\n"\
			    "- Fichier corrompu => essayer des m�langes de -nobps -ni -mc 0 -forceidx\n"\
			    "- -cache est utilis� avec un fichier mal multiplex� => essayer avec -nocache\n"\
			    "Si rien de tout cela ne r�sout le probl�me, lire DOCS/bugreports.html !\n\n"



#define MSGTR_NoGui "MPlayer a �t� compil� SANS support GUI!\n"
#define MSGTR_GuiNeedsX "MPlayer GUI a besoin de X11!\n"
#define MSGTR_Playing "Joue %s\n"
#define MSGTR_NoSound "Audio: Aucun son!!!\n"
#define MSGTR_FPSforced "FPS forc� � %5.3f  (ftime: %5.3f)\n"
#define MSGTR_CompiledWithRuntimeDetection "Compil� avec d�tection du CPU � l'ex�cution - attention, c'est sous-optimal! Pour de meilleures performances, recompilez MPlayer avec l'option --disable-runtime-cpudetection\n"
#define MSGTR_CompiledWithCPUExtensions "Compil� pour CPU x86 avec les extensions:"
#define MSGTR_AvailableVideoOutputPlugins "Plugins de sortie vid�o:\n"
#define MSGTR_AvailableVideoOutputDrivers "Modules de sortie vid�o disponibles:\n"
#define MSGTR_AvailableAudioOutputDrivers "Modules de sortie audio disponibles::\n"
#define MSGTR_AvailableAudioCodecs "Codecs audio disponibles:\n"
#define MSGTR_AvailableVideoCodecs "Codecs vid�o disponibles:\n"
#define MSGTR_AvailableAudioFm "\n(Familles de) Codecs audio disponibles (inclus � la compilation):\n"
#define MSGTR_AvailableVideoFm "\n(Familles de) Codecs vid�o disponibles (inclus � la compilation):\n"
#define MSGTR_UsingRTCTiming "Utilisation de la synchronisation mat�rielle par RTC (%ldHz)\n"
#define MSGTR_CannotReadVideoPropertiers "Vid�o: ne pas pas lire les propri�t�s\n"
#define MSGTR_NoStreamFound "Pas de flux trouv�\n"
#define MSGTR_InitializingAudioCodec "Initialisation des codecs audio...\n"
#define MSGTR_ErrorInitializingVODevice "Erreur � l'ouverture/l'initialisation de la sortie vid�o choisie (-vo)!\n"
#define MSGTR_ForcedVideoCodec "Codec vid�o forc�: %s\n"
#define MSGTR_AODescription_AOAuthor "AO: Description: %s\nAO: Auteur: %s\n"
#define MSGTR_AOComment "AO: Commentaire: %s\n"
#define MSGTR_Video_NoVideo "Vid�o: pas de vid�o!!!\n"
#define MSGTR_NotInitializeVOPorVO "\nFATAL: n'a pas pu initialiser les filtres vid�o (-vop) ou la sortie vid�o (-vo) !\n"
#define MSGTR_Paused "\n------ EN PAUSE -------\r"
#define MSGTR_PlaylistLoadUnable "\nNe peut pas charger la playlist %s\n"

// mencoder.c

#define MSGTR_MEncoderCopyright "(C) 2000-2002 Arpad Gereoffy (see DOCS!)\n"
#define MSGTR_UsingPass3ControllFile "Utilisation du fichier de controle de la passe 3\n"
#define MSGTR_MissingFilename "\nNom de fichier manquant!\n\n"
#define MSGTR_CannotOpenFile_Device "Ne peut pas ouvrir le fichier/le device\n"
#define MSGTR_ErrorDVDAuth "Erreur � l'authentification du DVD...\n"
#define MSGTR_CannotOpenDemuxer "Ne peut pas ouvrir le d�multiplexeur\n"
#define MSGTR_NoAudioEncoderSelected "\nPas d'encodeur audio (-oac) choisi! Choisissez en un ou utilisez -nosound. Essayez -oac help !\n"
#define MSGTR_NoVideoEncoderSelected "\nPas d'encodeur vid�o (-ovc) choisi! Choisissez-en un, essayez -ovc help !\n"
#define MSGTR_CannotOpenOutputFile "Ne peut pas ouvrir le fichier de sortie '%s'\n"
#define MSGTR_EncoderOpenFailed "N'a pas pu ouvrir l'encodeur\n"
#define MSGTR_ForcingOutputFourcc "Code fourcc de sortie forc� � %x [%.4s]\n"
#define MSGTR_WritingAVIHeader "Ecriture de l'ent�te AVI...\n"
#define MSGTR_DuplicateFrames "\n%d trame(s) dupliqu�e(s)!!!    \n"
#define MSGTR_SkipFrame "\ntrame supprim�e!!!    \n"
#define MSGTR_ErrorWritingFile "%s: erreur � l'�criture du fichier.\n"
#define MSGTR_WritingAVIIndex "\nEcriture de l'index AVI...\n"
#define MSGTR_FixupAVIHeader "Correction de l'ent�te AVI...\n"
#define MSGTR_RecommendedVideoBitrate "Bitrate vid�o recommand� pour %s CD: %d\n"
#define MSGTR_VideoStreamResult "\nFlux vid�o: %8.3f kbit/s  (%d bps)  size: %d bytes  %5.3f secs  %d trames\n"
#define MSGTR_AudioStreamResult "\nFlux audio: %8.3f kbit/s  (%d bps)  size: %d bytes  %5.3f secs\n"

// open.c, stream.c:
#define MSGTR_CdDevNotfound "Lecteur CD-ROM '%s' non trouv�!\n"
#define MSGTR_ErrTrackSelect "Erreur lors du choix de la piste VCD!"
#define MSGTR_ReadSTDIN "Lecture depuis stdin...\n"
#define MSGTR_UnableOpenURL "Ne peut ouvrir l'URL: %s\n"
#define MSGTR_ConnToServer "Connect� au serveur: %s\n"
#define MSGTR_FileNotFound "Fichier non trouv�: '%s'\n"

#define MSGTR_CantOpenDVD "Ne peut ouvrir le lecteur DVD: %s\n"
#define MSGTR_DVDwait "Lecture de la structure du disque, veuillez attendre...\n"
#define MSGTR_DVDnumTitles "Il y a %d titres sur ce DVD.\n"
#define MSGTR_DVDinvalidTitle "Num�ro de titre DVD invalide: %d\n"
#define MSGTR_DVDnumChapters "Il y a %d chapitres sur ce titre DVD.\n"
#define MSGTR_DVDinvalidChapter "Num�ro de chapitre DVD invalide: %d\n"
#define MSGTR_DVDnumAngles "Il y a %d s�quences sur ce titre DVD.\n"
#define MSGTR_DVDinvalidAngle "Num�ro de s�quence DVD invalide: %d\n"
#define MSGTR_DVDnoIFO "Ne peut ouvrir le fichier IFO pour le titre DVD %d.\n"
#define MSGTR_DVDnoVOBs "Ne peut ouvrir titre VOBS (VTS_%02d_1.VOB).\n"
#define MSGTR_DVDopenOk "DVD ouvert avec succ�s!\n"

// demuxer.c, demux_*.c:
#define MSGTR_AudioStreamRedefined "Attention! Ent�te du flux audio %d red�fini!\n"
#define MSGTR_VideoStreamRedefined "Attention! Ent�te du flux vid�o %d red�fini!\n"
#define MSGTR_TooManyAudioInBuffer "\nDEMUXER: Trop (%d dans %d octets) de packets audio dans le tampon!\n"
#define MSGTR_TooManyVideoInBuffer "\nDEMUXER: Trop (%d dans %d octets) de packets vid�o dans le tampon!\n"
#define MSGTR_MaybeNI "Peut-�tre jouez-vous un flux/fichier mal multiplex�, ou le codec n'est pas l�...\n"\
                      "Pour les fichier .AVI, essayez l'option -ni."
#define MSGTR_SwitchToNi "\nFichier .AVI mal multiplex� - passage en mode -ni!\n"
#define MSGTR_DetectedFILMfile "Fichier de type FILM d�tect�!\n"
#define MSGTR_DetectedFLIfile "Fichier de type FLI d�tect�!\n"
#define MSGTR_DetectedROQfile "Fichier de type RoQ d�tect�!\n"
#define MSGTR_DetectedREALfile "Fichier de type REAL d�tect�!\n"
#define MSGTR_DetectedAVIfile "Fichier de type AVI d�tect�!\n"
#define MSGTR_DetectedASFfile "Fichier de type ASF d�tect�!\n"
#define MSGTR_DetectedMPEGPESfile "Fichier de type MPEG-PES d�tect�!\n"
#define MSGTR_DetectedMPEGPSfile "Fichier de type MPEG-PS d�tect�!\n"
#define MSGTR_DetectedMPEGESfile "Fichier de type MPEG-ES d�tect�!\n"
#define MSGTR_DetectedQTMOVfile "Fichier de type QuickTime/MOV d�tect�!\n"
#define MSGTR_DetectedYUV4MPEG2file "Fichier de type YUV4MPEG2 d�tect�!\n"
#define MSGTR_DetectedNuppelVideofile "Fichier de type NuppelVideo d�tect�!\n"
#define MSGTR_DetectedVIVOfile "Fichier de type VIVO d�tect�!\n"
#define MSGTR_DetectedBMPfile "Fichier de type BMP d�tect�!\n"
#define MSGTR_DetectedOGGfile "Fichier de type OGG d�tect�!\n"
#define MSGTR_DetectedRAWDVfile "Fichier de type RAWDV d�tect�!\n"
#define MSGTR_DetectedAudiofile "Fichier audio d�tect�!\n"
#define MSGTR_NotSystemStream "Pas un flux de type MPEG System... (peut-�tre un flux de transport?)\n"
#define MSGTR_InvalidMPEGES "Flux MPEG-ES invalide??? Contactez l'auteur, c'est peut-�tre un bug :(\n"
#define MSGTR_FormatNotRecognized "========== D�sol�, ce format de fichier n'est pas reconnu/support� ===========\n"\
				  "========= Si ce fichier est un fichier AVI, ASF ou MPEG en bon �tat, =========\n"\
				  "======================= merci de contacter l'auteur ! ========================\n"
#define MSGTR_MissingVideoStream "Ne peut trouver de flux vid�o!\n"
#define MSGTR_MissingAudioStream "Ne peut trouver de flux audio...  -> pas de son\n"
#define MSGTR_MissingVideoStreamBug "Flux vid�o manquant!? Contactez l'auteur, c'est peut-�tre un bug :(\n"

#define MSGTR_DoesntContainSelectedStream "Demux: le fichier ne contient pas le flux audio ou vid�o s�lectionn�\n"

#define MSGTR_NI_Forced "Forc�"
#define MSGTR_NI_Detected "D�tect�"
#define MSGTR_NI_Message "%s format de fichier AVI mal multiplex�!\n"

#define MSGTR_UsingNINI "Utilise le support des fichiers AVI mal multiplex�s!\n"
#define MSGTR_CouldntDetFNo "Ne peut d�terminer le nombre de frames (pour recherche absolue)\n"
#define MSGTR_CantSeekRawAVI "Ne peut chercher dans un flux .AVI brut! (Index requis, essayez l'option -idx!)\n"
#define MSGTR_CantSeekFile "Ne peut chercher dans ce fichier!  \n"

#define MSGTR_EncryptedVOB "Fichier VOB crypt� (support libcss NON compil�!) Lire DOCS/cd-dvd.html\n"
#define MSGTR_EncryptedVOBauth "Flux crypt� mais l'authentification n'a pas �t� demand�e explicitement!\n"

#define MSGTR_MOVcomprhdr "MOV: Les ent�tes compress�es ne sont pas (encore) support�s!\n"
#define MSGTR_MOVvariableFourCC "MOV: Attention! Variable FOURCC d�tect�e!?\n"
#define MSGTR_MOVtooManyTrk "MOV: Attention! Trop de pistes!"
#define MSGTR_FoundAudioStream "==> Flux audio trouv�: %d\n"
#define MSGTR_FoundVideoStream "==> Flux vid�o trouv�: %d\n"
#define MSGTR_DetectedTV "TV d�tect�e! ;-)\n"
#define MSGTR_ErrorOpeningOGGDemuxer "Ne peut pas ouvrir le demuxer ogg\n"
#define MSGTR_ASFSearchingForAudioStream "ASF: recherche du flux audio (id:%d)\n"
#define MSGTR_CannotOpenAudioStream "Ne peut pas ouvrir le flux audio: %s\n"
#define MSGTR_CannotOpenSubtitlesStream "Ne peut pas ouvrir le flux des sous-titres: %s\n"
#define MSGTR_OpeningAudioDemuxerFailed "N'a pas pu ouvrir le demuxer audio: %s\n"
#define MSGTR_OpeningSubtitlesDemuxerFailed "N'a pas pu ouvrir le demuxer de sous-titres: %s\n"
#define MSGTR_TVInputNotSeekable "Impossible de rechercher sur l'entr�e TV! (cette op�ration correspondra surement � un changement de cha�nes ;)\n"
#define MSGTR_DemuxerInfoAlreadyPresent "Info du demuxer %s d�j� pr�sentes!\n"
#define MSGTR_ClipInfo "Information sur le clip: \n"

// dec_video.c & dec_audio.c:
#define MSGTR_CantOpenCodec "Ne peut ouvrir le codec\n"
#define MSGTR_CantCloseCodec "Ne peut fermer le codec\n"

#define MSGTR_MissingDLLcodec "ERREUR: Ne peut trouver le codec DirectShow n�cessaire: %s\n"
#define MSGTR_ACMiniterror "Ne peut charger/initialiser le codec AUDIO Win32/ACM (fichier DLL manquant?)\n"
#define MSGTR_MissingLAVCcodec "Ne peut trouver le codec '%s' de libavcodec...\n"

#define MSGTR_MpegNoSequHdr "MPEG: FATAL: Fin du fichier lors de la recherche d'ent�te de s�quence\n"
#define MSGTR_CannotReadMpegSequHdr "FATAL: Ne peut lire l'ent�te de s�quence!\n"
#define MSGTR_CannotReadMpegSequHdrEx "FATAL: Ne peut lire l'extension d'ent�te de s�quence!\n"
#define MSGTR_BadMpegSequHdr "MPEG: Mauvais ent�te de s�quence!\n"
#define MSGTR_BadMpegSequHdrEx "MPEG: Mauvaise extension d'ent�te de s�quence!\n"

#define MSGTR_ShMemAllocFail "Ne peut allouer de m�moire partag�e\n"
#define MSGTR_CantAllocAudioBuf "Ne peut allouer de tampon de sortie audio\n"

#define MSGTR_UnknownAudio "Format audio inconnu/manquant -> pas de son\n"

#define MSGTR_UsingExternalPP "[PP] Utilisation de filtres de postprocessing externes, max q = %d\n"
#define MSGTR_UsingCodecPP "[PP] Utilisation du postprocessing du codec, max q = %d\n"
#define MSGTR_VideoAttributeNotSupportedByVO_VD "L'attribut vid�o '%s' n'est pas support� par ce vo & ce vd! \n"
#define MSGTR_VideoCodecFamilyNotAvailableStr "Famille de codecs vid�o demand�e [%s] (vfm=%s) non disponible (activez-les � la compilation!)\n"
#define MSGTR_AudioCodecFamilyNotAvailableStr "Famille de codecs audio demand�e [%s] (afm=%s) non disponible (activez-les � la compilation!)\n"
#define MSGTR_OpeningVideoDecoder "Ouverture du d�codeur vid�o: [%s] %s\n"
#define MSGTR_OpeningAudioDecoder "Ouverture du d�codeur audio: [%s] %s\n"
#define MSGTR_UninitVideoStr "D�sinitialisation vid�o: %s  \n"
#define MSGTR_UninitAudioStr "D�sinitialistion audio: %s  \n"
#define MSGTR_VDecoderInitFailed "Echec de l'initialisation du VDecoder :(\n"
#define MSGTR_ADecoderInitFailed "Echec de l'initialisation de l'ADecoder :(\n"
#define MSGTR_ADecoderPreinitFailed "Echec de la pr�-initialisation de l'ADecoder :(\n"
#define MSGTR_AllocatingBytesForInputBuffer "dec_audio: allocation de %d bytes comme tampon d'entr�e\n"
#define MSGTR_AllocatingBytesForOutputBuffer "dec_audio: allocation %d + %d = %d bytes comme tampon de sortie\n"

// LIRC:
#define MSGTR_SettingUpLIRC "Mise en place du support LIRC...\n"
#define MSGTR_LIRCdisabled "Vous ne pourrez pas utiliser votre t�l�commande\n"
#define MSGTR_LIRCopenfailed "Impossible d'activer le support LIRC!\n"
#define MSGTR_LIRCcfgerr "Impossible de lire le fichier de configuration LIRC %s !\n"

// vf.c
#define MSGTR_CouldNotFindVideoFilter "N'a pas pu trouv� le filtre vid�o '%s'\n"
#define MSGTR_CouldNotOpenVideoFilter "N'a pas pu ouvrir le filtre vid�o '%s'\n"
#define MSGTR_OpeningVideoFilter "Ouverture du filtre vid�o: "
#define MSGTR_CannotFindColorspace "Ne peut pas trouver d'espace de couleurs commun, m�me en utilisant 'scale' :(\n"

// vd.c
#define MSGTR_CodecDidNotSet "VDec: le codec n'a pas d�fini sh->disp_w and sh->disp_h, essai de workaround!\n"
#define MSGTR_VoConfigRequest "VDec: requ�te de configuration du vo - %d x %d (csp pr�fer�: %s)\n"
#define MSGTR_CouldNotFindColorspace "N'a pas pu trouver d'espace de couleur correspondant - nouvel essai avec -vop scale...\n"
#define MSGTR_MovieAspectIsSet "L'aspect du film est %.2f:1 - pr�-redimensionnement � l'aspect correct.\n"
#define MSGTR_MovieAspectUndefined "L'aspect du film est ind�fini - pas de pr�-redimensionnement appliqu�.\n"

// ====================== messages/boutons GUI ========================

#ifdef HAVE_NEW_GUI

// --- labels ---
#define MSGTR_About "� propos ..."
#define MSGTR_FileSelect "Choisir un fichier ..."
#define MSGTR_SubtitleSelect "Choisir un sous-titre ..."
#define MSGTR_OtherSelect "Choisir ..."
#define MSGTR_AudioFileSelect "Choisir une source audio ext�rieure ..."
#define MSGTR_FontSelect "Choisir une police ..."
#define MSGTR_PlayList "PlayList"
#define MSGTR_Equalizer "Equaliseur"
#define MSGTR_SkinBrowser "Browser de skins"
#define MSGTR_Network "Streaming sur le r�seau ..."
#define MSGTR_Preferences "Pr�f�rences"
#define MSGTR_OSSPreferences "Configuration du pilote OSS"
#define MSGTR_NoMediaOpened "pas de m�dia ouvert"
#define MSGTR_VCDTrack "Piste du VCD %d"
#define MSGTR_NoChapter "Pas de chapitre"
#define MSGTR_Chapter "Chapitre %d"
#define MSGTR_NoFileLoaded "Pas de fichier charg�"

// --- boutons ---
#define MSGTR_Ok "Ok"
#define MSGTR_Cancel "Annuler"
#define MSGTR_Add "Ajouter"
#define MSGTR_Remove "Supprimer"
#define MSGTR_Clear "Effacer"
#define MSGTR_Config "Configurer"
#define MSGTR_ConfigDriver "Configuration du pilote"
#define MSGTR_Browse "Browser"

// --- messages d'erreur ---
#define MSGTR_NEMDB "D�sol�, pas assez de m�moire pour le tampon de dessin."
#define MSGTR_NEMFMR "D�sol�, pas assez de m�moire pour le rendu des menus."
#define MSGTR_IDFGCVD "D�sol�, pas de pilote de sortie vid�o compatible avec le GUI."
#define MSGTR_NEEDLAVCFAME "D�sol�, vous ne pouvez pas jouer de fichier non-MPEG avec votre DXR3/H+ device sans r�encodage\nVeuillez activer lavc ou fame dans la bo�te de configuration DXR3/H+."

// --- messages d'erreurs du chargement de skin ---
#define MSGTR_SKIN_ERRORMESSAGE "[Skin] Erreur � la ligne %d du fichier de config de skin: %s" 
#define MSGTR_SKIN_WARNING1 "[Skin] Attention � la ligne %d du fichier de config de skin: Widget trouv� mais \"section\" n'a pas �t� trouv� avant (%s)"
#define MSGTR_SKIN_WARNING2 "[Skin] Attention � la ligne %d du fichier de config de skin: Widget trouv� mais \"subsection\" n'a pas �t� trouv� avant (%s)"
#define MSGTR_SKIN_BITMAP_16bit  "Bitmaps de 16 bits ou moins ne sont pas support�s ( %s ).\n"
#define MSGTR_SKIN_BITMAP_FileNotFound  "Fichier non trouv� ( %s )\n"
#define MSGTR_SKIN_BITMAP_BMPReadError "Erreur de lecture BMP ( %s )\n"
#define MSGTR_SKIN_BITMAP_TGAReadError "Erreur de lecture TGA ( %s )\n"
#define MSGTR_SKIN_BITMAP_PNGReadError "Erreur de lecture PNG ( %s )\n"
#define MSGTR_SKIN_BITMAP_RLENotSupported "tga compact� en RLE non support�s ( %s )\n"
#define MSGTR_SKIN_BITMAP_UnknownFileType "format de fichier inconnu ( %s )\n"
#define MSGTR_SKIN_BITMAP_ConvertError "erreur de conversion de 24 bit � 32 bit ( %s )\n"
#define MSGTR_SKIN_BITMAP_UnknownMessage "Message inconnu: %s\n"
#define MSGTR_SKIN_FONT_NotEnoughtMemory "pas assez de m�moire\n"
#define MSGTR_SKIN_FONT_TooManyFontsDeclared "trop de polices d�clar�es\n"
#define MSGTR_SKIN_FONT_FontFileNotFound "fichier de police introuvable\n"
#define MSGTR_SKIN_FONT_FontImageNotFound "fichier d'image de police introuvable\n"
#define MSGTR_SKIN_FONT_NonExistentFontID "identificateur de fonte inexistant ( %s )\n"
#define MSGTR_SKIN_UnknownParameter "param�tre inconnu ( %s )\n"
#define MSGTR_SKINBROWSER_NotEnoughMemory "[Browser de skins] pas assez de m�moire.\n"
#define MSGTR_SKIN_SKINCFG_SkinNotFound "Skin non trouv� ( %s ).\n"
#define MSGTR_SKIN_SKINCFG_SkinCfgReadError "Erreur de lecture du fichier de configuration du skin ( %s ).\n"
#define MSGTR_SKIN_LABEL "Skins:"

// --- menus gtk
#define MSGTR_MENU_AboutMPlayer "� propos de MPlayer"
#define MSGTR_MENU_Open "Ouvrir ..."
#define MSGTR_MENU_PlayFile "Lire un fichier ..."
#define MSGTR_MENU_PlayVCD "Lire un VCD ..."
#define MSGTR_MENU_PlayDVD "Lire un DVD ..."
#define MSGTR_MENU_PlayURL "Lire une URL ..."
#define MSGTR_MENU_LoadSubtitle "Charger un sous-titre ..."
#define MSGTR_MENU_DropSubtitle "Laisser tomber un sous-titre ..."
#define MSGTR_MENU_LoadExternAudioFile "Chargement d'un fichier audio externe ..."
#define MSGTR_MENU_Playing "En cours de lecture"
#define MSGTR_MENU_Play "Lecture"
#define MSGTR_MENU_Pause "Pause"
#define MSGTR_MENU_Stop "Arr�t"
#define MSGTR_MENU_NextStream "Flux suivant"
#define MSGTR_MENU_PrevStream "Flux pr�c�dent"
#define MSGTR_MENU_Size "Taille"
#define MSGTR_MENU_NormalSize "Taille normale"
#define MSGTR_MENU_DoubleSize "Taille double"
#define MSGTR_MENU_FullScreen "Plein �cran"
#define MSGTR_MENU_DVD "DVD"
#define MSGTR_MENU_VCD "VCD"
#define MSGTR_MENU_PlayDisc "Lire un disque..."
#define MSGTR_MENU_ShowDVDMenu "Afficher le menu DVD"
#define MSGTR_MENU_Titles "Titres"
#define MSGTR_MENU_Title "Titre %2d"
#define MSGTR_MENU_None "(aucun)"
#define MSGTR_MENU_Chapters "Chapitres"
#define MSGTR_MENU_Chapter "Chapitre %2d"
#define MSGTR_MENU_AudioLanguages "Langues (audio)"
#define MSGTR_MENU_SubtitleLanguages "Langues (sous-titres)"
#define MSGTR_MENU_PlayList "Playlist"
#define MSGTR_MENU_SkinBrowser "Browser de skins"
#define MSGTR_MENU_Preferences "Pr�f�rences"
#define MSGTR_MENU_Exit "Quitter ..."

// --- equalizer
#define MSGTR_EQU_Audio "Audio"
#define MSGTR_EQU_Video "Vid�o"
#define MSGTR_EQU_Contrast "Contraste: "
#define MSGTR_EQU_Brightness "Luminosit�: "
#define MSGTR_EQU_Hue "Hue: "
#define MSGTR_EQU_Saturation "Saturation: "
#define MSGTR_EQU_Front_Left "Avant Gauche"
#define MSGTR_EQU_Front_Right "Avant Droit"
#define MSGTR_EQU_Back_Left "C�t� Gauche"
#define MSGTR_EQU_Back_Right "C�t� Droit"
#define MSGTR_EQU_Center "Centre"
#define MSGTR_EQU_Bass "Basses"
#define MSGTR_EQU_All "Tout"

// --- playlist
#define MSGTR_PLAYLIST_Path "Chemin"
#define MSGTR_PLAYLIST_Selected "Fichiers choisis"
#define MSGTR_PLAYLIST_Files "Fichiers"
#define MSGTR_PLAYLIST_DirectoryTree "Hi�rarchie des dossiers"

// --- preferences
#define MSGTR_PREFERENCES_None "Aucun"
#define MSGTR_PREFERENCES_AvailableDrivers "Pilotes disponibles:"
#define MSGTR_PREFERENCES_DoNotPlaySound "Ne pas jouer le son"
#define MSGTR_PREFERENCES_NormalizeSound "Normaliser le son"
#define MSGTR_PREFERENCES_EnEqualizer "Activer l'�qualiseur"
#define MSGTR_PREFERENCES_ExtraStereo "Activer l'extra-st�r�o"
#define MSGTR_PREFERENCES_Coefficient "Coefficient:"
#define MSGTR_PREFERENCES_AudioDelay "Retard audio"
#define MSGTR_PREFERENCES_Audio "Audio"
#define MSGTR_PREFERENCES_DoubleBuffer "Activer le double-buffering"
#define MSGTR_PREFERENCES_DirectRender "Activer le rendu direct"
#define MSGTR_PREFERENCES_FrameDrop "Activer le frame-dropping"
#define MSGTR_PREFERENCES_HFrameDrop "Activer le frame-dropping VIOLENT (dangereux)"
#define MSGTR_PREFERENCES_Flip "Mirroir vertical"
#define MSGTR_PREFERENCES_Panscan "Panscan: "
#define MSGTR_PREFERENCES_Video "Vid�o"
#define MSGTR_PREFERENCES_OSDTimer "Minuteur et indicateurs"
#define MSGTR_PREFERENCES_OSDProgress "Barres de progression seulement"
#define MSGTR_PREFERENCES_Subtitle "Sous-titre:"
#define MSGTR_PREFERENCES_SUB_Delay "Delay: "
#define MSGTR_PREFERENCES_SUB_FPS "FPS:"
#define MSGTR_PREFERENCES_SUB_POS "Position: "
#define MSGTR_PREFERENCES_SUB_AutoLoad "D�sactiver le chargement automatique des sous-titres"
#define MSGTR_PREFERENCES_SUB_Unicode "Sous-titre en Unicode"
#define MSGTR_PREFERENCES_SUB_MPSUB "Convertit le sous-titre dans le format MPlayer"
#define MSGTR_PREFERENCES_SUB_SRT "Convertit le sous-titre vers le format SubViewer (SRT) bas� sur le temps"
#define MSGTR_PREFERENCES_Font "Police:"
#define MSGTR_PREFERENCES_FontFactor "Font factor:"
#define MSGTR_PREFERENCES_PostProcess "Activer le postprocessing"
#define MSGTR_PREFERENCES_AutoQuality "Qualit� auto.: "
#define MSGTR_PREFERENCES_NI "Utiliser le parseur d'AVI mal multiplex�s"
#define MSGTR_PREFERENCES_IDX "Reconstruire l'index, si n�cessaire"
#define MSGTR_PREFERENCES_VideoCodecFamily "Famille de codecs vid�o:"
#define MSGTR_PREFERENCES_AudioCodecFamily "Famille de codecs audio:"
#define MSGTR_PREFERENCES_FRAME_OSD_Level "Niveau OSD"
#define MSGTR_PREFERENCES_FRAME_Subtitle "Sous-titre"
#define MSGTR_PREFERENCES_FRAME_Font "Police"
#define MSGTR_PREFERENCES_FRAME_PostProcess "Postprocessing"
#define MSGTR_PREFERENCES_FRAME_CodecDemuxer "Codec & demuxer"
#define MSGTR_PREFERENCES_OSS_Device "Device:"
#define MSGTR_PREFERENCES_OSS_Mixer "Mixer:"
#define MSGTR_PREFERENCES_Message "ATTENTION: certaines options requi�rent de un red�marrage de la lecture!"
#define MSGTR_PREFERENCES_DXR3_VENC "Encodeur vid�o:"
#define MSGTR_PREFERENCES_DXR3_LAVC "Utiliser LAVC (ffmpeg)"
#define MSGTR_PREFERENCES_DXR3_FAME "Utiliser FAME"
#define MSGTR_PREFERENCES_FontEncoding1 "Unicode"
#define MSGTR_PREFERENCES_FontEncoding2 "Langues Europ�ennes Occidentales (ISO-8859-1)"
#define MSGTR_PREFERENCES_FontEncoding3 "Langues Europ�eenes Occidentales avec Euro (ISO-8859-15)"
#define MSGTR_PREFERENCES_FontEncoding4 "Langues Europ�eenes Slaves/Centrales (ISO-8859-2)"
#define MSGTR_PREFERENCES_FontEncoding5 "Esperanto, Galicien, Maltais, Turc (ISO-8859-3)"
#define MSGTR_PREFERENCES_FontEncoding6 "Caract�res Old Baltic (ISO-8859-4)"
#define MSGTR_PREFERENCES_FontEncoding7 "Cyrillique (ISO-8859-5)"
#define MSGTR_PREFERENCES_FontEncoding8 "Arabe (ISO-8859-6)"
#define MSGTR_PREFERENCES_FontEncoding9 "Grec Moderne (ISO-8859-7)"
#define MSGTR_PREFERENCES_FontEncoding10 "Turc (ISO-8859-9)"
#define MSGTR_PREFERENCES_FontEncoding11 "Balte (ISO-8859-13)"
#define MSGTR_PREFERENCES_FontEncoding12 "Celte (ISO-8859-14)"
#define MSGTR_PREFERENCES_FontEncoding13 "Hebreu (ISO-8859-8)"
#define MSGTR_PREFERENCES_FontEncoding14 "Russe (KOI8-R)"
#define MSGTR_PREFERENCES_FontEncoding15 "Ukrainien, Bi�lorusse (KOI8-U/RU)"
#define MSGTR_PREFERENCES_FontEncoding16 "Chinois Simplifi� (CP936)"
#define MSGTR_PREFERENCES_FontEncoding17 "Chinois Traditionnel (BIG5)"
#define MSGTR_PREFERENCES_FontEncoding18 "Japonais (SHIFT-JIS)"
#define MSGTR_PREFERENCES_FontEncoding19 "Cor�en (CP949)"
#define MSGTR_PREFERENCES_FontEncoding20 "Tha�landais (CP874)"
#define MSGTR_PREFERENCES_FontEncoding21 "Cyrillique Windows (CP1251)"
#define MSGTR_PREFERENCES_FontNoAutoScale "Pas d'agrandissement auto"
#define MSGTR_PREFERENCES_FontPropWidth "Proportionnel � la largeur du film"
#define MSGTR_PREFERENCES_FontPropHeight "Proportionnel � la hauteur du film"
#define MSGTR_PREFERENCES_FontPropDiagonal "Proportionnel � la diagonale du film"
#define MSGTR_PREFERENCES_FontEncoding "Encodage:"
#define MSGTR_PREFERENCES_FontBlur "Flou:"
#define MSGTR_PREFERENCES_FontOutLine "Contour:"
#define MSGTR_PREFERENCES_FontTextScale "Echelle du texte:"
#define MSGTR_PREFERENCES_FontOSDScale "Echelle de l'OSD:"
#define MSGTR_PREFERENCES_SubtitleOSD "Sous-titre & OSD"

// --- messagebox
#define MSGTR_MSGBOX_LABEL_FatalError "Erreur fatale ..."
#define MSGTR_MSGBOX_LABEL_Error "Erreur!"
#define MSGTR_MSGBOX_LABEL_Warning "Attention!" 

#endif

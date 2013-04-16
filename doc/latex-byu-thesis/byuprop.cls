% BYU MS/PhD Proposal LaTeX Class File
%
% Copyright (c) 2008 Daniel P. Delorey
% The latest version of this file may be obtained from
%   http://code.google.com/p/latex-byu-thesis/
%
% License: LaTeX Project Public License (www.latex-project.org/lppl.txt)
%   Executive summary:
%       This software is copyright but you are granted a license which gives
%       you, the "user" of the software, legal permission to copy, distribute,
%       and/or modify the software. However, if you modify the software and
%       then distribute it (even just locally) you must change the name of the
%       software to avoid confusion.
%
% OR (dual-licensed)
%
% License: GNU Lesser General Public License (www.gnu.org/licenses/lgpl.html)
%
% Author Information:
%   Daniel P. Delorey
%   Brigham Young University
%   byuprop@deloreyfamily.org
%
% Please contact the author for change requests.  If you have patches, please
% send those to the author as well so that this class has a single point of
% distribution and all may benefit.
%
% Version: 1.0
%
% Changelog:
%   Dan Delorey (2008-01-30):
%       *   First reasonable release
\NeedsTeXFormat{LaTeX2e}[1995/12/01]
\ProvidesClass{byuprop}[2008/01/29 BYU LaTeX MS/PhD Proposal Class]

% Boolean option creation
\newif\if@thesis % generates \if@thesis, \@thesistrue, and \@thesisfalse
\newif\if@dissertation % generates \if@dissertation, \@dissertation true, and \@dissertationfalse
\newif\if@areaexam % generates \if@areaexam, \@areaexamtrue, and \@areaexamfalse
\newif\if@needdrawing % Need the eso-pic environment?  Drawing something?
\newif\if@layout % This will draw lines showing all the margins
\newif\if@grid % Show a grid

\newcommand{\@@ptsize}{12pt}

% This is an empty no-op command in case pdfbookmark is not defined (hyperref
% not included)
\newcommand{\@@pdfbookmark}[3][1]{%
  \ifx\pdfbookmark\undefined
    \relax
  \else
    \pdfbookmark[#1]{#2}{#3}%
  \fi
}%

% This document can serve as either a PhD dissertation or a Master's thesis proposal
\DeclareOption{ms}{%
  \if@areaexam%
    \ClassError{byuprop}%
      {Choose exactly one of ms, areaexam, and phd}%
      {You used the ms option after using the areaexam option}%
  \fi%
  \if@dissertation%
    \ClassError{byuprop}%
      {Choose exactly one of ms, areaexam, and phd}%
      {You used the ms option after using the phd option}%
  \fi%
  \@thesistrue}
\DeclareOption{areaexam}{%
  \if@thesis%
    \ClassError{byuprop}%
      {Choose exactly one of ms, areaexam, and phd}%
      {You used the areaexam option after using the ms option}%
  \fi%
  \if@dissertation%
    \ClassError{byuprop}%
      {Choose exactly one of ms, areaexam, and phd}%
      {You used the areaexam option after using the phd option}%
  \fi%
  \@areaexamtrue}
\DeclareOption{phd}{%
  \if@thesis%
    \ClassError{byuprop}%
      {Choose exactly one of ms, areaexam, and phd}%
      {You used the phd option after using the ms option}%
  \fi%
  \if@areaexam%
    \ClassError{byuprop}%
      {Choose exactly one of ms, areaexam, and phd}%
      {You used the phd option after using the areaexam option}%
  \fi%
  \@dissertationtrue}
\DeclareOption{layout}{\@needdrawingtrue \@layouttrue}
\DeclareOption{grid}{\@needdrawingtrue \@gridtrue}
\DeclareOption{10pt}{\renewcommand{\@@ptsize}{10pt}}%
\DeclareOption{11pt}{\renewcommand{\@@ptsize}{11pt}}%
\DeclareOption{12pt}{\renewcommand{\@@ptsize}{12pt}}%

\setlength{\unitlength}{1in}

% Initialize all the document type options to false
\@thesisfalse
\@areaexamfalse
\@dissertationfalse

% Don't show the layout, usually
\@needdrawingfalse
\@layoutfalse
\@gridfalse

\ProcessOptions

% We base our work on the article class
\LoadClass[\@@ptsize]{article}

% Rather than fiddle with spacing, we set it up using the setspace package
% Note that even though most of the document is double spaced, we start with
% single spacing because of the following reasons:
%  * setspace likes to *enlarge* the spacing, not shrink it
%  * the minimum style requirements dictate vertical spacing as a number of
%   ``blank lines'', and the size of those lines is single-spaced.
\RequirePackage[singlespacing]{setspace}

% The geometry package is great and we use it rather than fiddling with the
% margins directly.  We do have to employ some margin-fiddling trickery after
% the preamble, however, because the geometry package does not provide a way to
% set the margins in the middle of a document.
\RequirePackage[
    top=1.0in,
    bottom=1.0in,
    inner=1.0in,
    outer=1.0in,
    ]{geometry}

% If we are showing layout grids, then we include the appropriate package and
% draw stuff on every page.
\if@needdrawing
    \RequirePackage[grid=false]{eso-pic}%
    \newcommand{\@vertline}{\line(0,1){11}}
    \newcommand{\@horzline}{\line(1,0){8.5}}
    \newcommand{\@maingrid}{%
        \multiput(1,0)(1,0){8}{\thicklines\@vertline}%
        \multiput(0,1)(0,1){10}{\thicklines\@horzline}%
    }%
    \newcommand{\@smallgrid}{%
        \multiput(0.5,0)(1,0){8}{\thinlines\@vertline}%
        \multiput(0,0.5)(0,1){11}{\thinlines\@horzline}%
    }%
    \newcommand{\@layoutpreamble}{\setlength{\unitlength}{1in}}
    \newcommand{\@rightsidebox}{
        \put (1.5,1){\dashbox{0.03125}(6,9)}%
    }%
    \newcommand{\@leftsidebox}{
        \put (1,1){\dashbox{0.03125}(6,9)}%
    }%
    \newcommand{\@prefaceinnerbox}{
        \put (1.5,1){\dashbox{0.03125}(6,8)}%
    }%
    \AddToShipoutPicture{%
        \@layoutpreamble
        \if@layout
            \@rightsidebox
            \@leftsidebox
            \@prefaceinnerbox
        \fi
        \if@grid
            \@smallgrid
            \@maingrid
        \fi
    }%
\fi

% Name of the degree
\newcommand*{\@degreename}{%
    \if@thesis%
        Master of Science%
    \else%
        Doctor of Philosophy%
    \fi%
}%

% Name of document
\newcommand*{\@documenttype}{%
    \if@thesis%
        thesis proposal%
    \else\if@areaexam%
        research area overview%
    \else\if@dissertation%
        dissertation proposal%
    \fi\fi\fi%
}%

% These are internal variables used throughout the class.  They represent
% default values for their corresponding @-less versions.
\newcommand{\@university}{Brigham Young University}
\newcommand{\@department}{Computer Science}
\newcommand{\@departmentprefix}{Department of}
\newcommand{\@graduatecoordinator}{}
\newcommand{\@committeechair}{}
\newcommand{\@committeemembera}{}
\newcommand{\@committeememberb}{}
\newcommand{\@committeememberc}{}
\newcommand{\@committeememberd}{}
\newcommand{\@monthsubmitted}{}
\newcommand{\@yearsubmitted}{}

% Here are some things that can be set from inside the document.  Most of them
% have suitable defaults.
\newcommand{\university}[1]{\renewcommand{\@university}{#1}}
\newcommand{\department}[1]{\renewcommand{\@department}{#1}}
\newcommand{\departmentprefix}[1]{\renewcommand{\@departmentprefix}{#1}}
\newcommand{\graduatecoordinator}[1]{\renewcommand{\@graduatecoordinator}{#1}}
\newcommand{\committeechair}[1]{\renewcommand{\@committeechair}{#1}}
\newcommand{\committeemembera}[1]{\renewcommand{\@committeemembera}{#1}}
\newcommand{\committeememberb}[1]{\renewcommand{\@committeememberb}{#1}}
\newcommand{\committeememberc}[1]{\renewcommand{\@committeememberc}{#1}}
\newcommand{\committeememberd}[1]{\renewcommand{\@committeememberd}{#1}}
\newcommand{\monthsubmitted}[1]{\renewcommand{\@monthsubmitted}{#1}}
\newcommand{\yearsubmitted}[1]{\renewcommand{\@yearsubmitted}{#1}}

% Internal commands with no external settings
\newlength{\@assumedcharwidth}
\newlength{\@defaultindent}
\newlength{\@sigskip}
\newlength{\@blankline}
\newlength{\@prefacemargingapsingle}
\newlength{\@prefacemargingapdouble}
\setlength{\@assumedcharwidth}{6pt}
\setlength{\@defaultindent}{6\@assumedcharwidth}
\setlength{\@blankline}{\baselineskip}
\setlength{\@sigskip}{2\@blankline} % signature spacing is 2 blank lines

% This is the margin gap between the top of the paper and single-spaced text.  It defines a margin that is a total of 2 inches from the top
\setlength{\@prefacemargingapsingle}{1in}
\setlength{\@prefacemargingapdouble}{\@prefacemargingapsingle}
\addtolength{\@prefacemargingapdouble}{-\baselineskip}

% Definitions of signature primitives, like the size of the date rule and the
% way that signatures are generally formatted.
\newlength{\Datewidth}
\newlength{\Sigwidth}
\setlength{\Datewidth}{1.5in}
\setlength{\Sigwidth}{3.8in}

\providecommand{\Signature}[1]{%
    \noindent
    \parbox[t]{\Datewidth}{%
        \rule{\Datewidth}{0.4pt}\\Date%
    }%
    \hfill
    \parbox[t]{\Sigwidth}{%
        \rule{\Sigwidth}{0.4pt}\\{#1}%
    }%
    \par
}

% Signature page
\newcommand{\signaturepage}{%
    \clearpage
    {\parindent 0pt%
    \vspace*{\@prefacemargingapdouble}%
    {\centering
        \MakeUppercase{\@university}%
        \vspace{3\@blankline}\par
        GRADUATE COMMITTEE APPROVAL%
        \vspace{5\@blankline}\par
        \begin{doublespace}%
        of a {\@documenttype} proposal submitted by\\%
        \@author
        \end{doublespace}%
    \par}% end centering
    \vspace{2\@blankline}\par
    This {\@documenttype} proposal has been read by each member of the following
    graduate committee and by majority vote has been found to be
    satisfactory.
    \vspace{3\@blankline}\par
    \Signature{\@committeechair, Chair}%
    \vspace{\@sigskip}\par
    \Signature{\@committeemembera}%
    \vspace{\@sigskip}\par
    \Signature{\@committeememberb}%
    \if@thesis\else
        \vspace{\@sigskip}\par
        \Signature{\@committeememberc}%
        \vspace{\@sigskip}\par
        \Signature{\@committeememberd}%
    \fi
    \vspace{\@sigskip}\par
    \Signature{\@graduatecoordinator\\Graduate Coordinator}%
    }% end parindent
    \newpage
}%

% Title page
\renewcommand{\titlepage}{%
    \clearpage
    \@@pdfbookmark[1]{Title Page}{title}%
    {\parindent 0pt%
    {\centering
    \vspace*{\@prefacemargingapdouble}%
    \parbox[t]{5in}{\centering
        \begin{doublespace}%
            \MakeUppercase{\@title}%
        \end{doublespace}%
    \par}%
    \vfill
        \begin{doublespace}%
            by\\\@author
        \end{doublespace}%
    \vfill
    \vfill
        \begin{doublespace}%
            A {\@documenttype} submitted to the faculty of\\%
            \@university\\%
            in partial fulfillment of the requirements for the degree of%
        \end{doublespace}%
    \vfill
        \begin{doublespace}%
            \@degreename
        \end{doublespace}%
    \vfill
    \vfill
    \vfill
        \begin{doublespace}%
            {\@departmentprefix} {\@department} \\%
            \@university\\%
            {\@monthsubmitted} {\@yearsubmitted}%
        \end{doublespace}%
    \par}% end centering
    }% end parindent
    \newpage
}%

% Lifted from report.cls and edited to be smaller
% NOTE that the minimum standards document indicates that ALL fonts should be
% 10, 11, or 12 point *including titles and headings*.  This requirement is
% incredibly ugly, but if you want to comply with it, change everything to
% normalsize in this document.
\renewcommand{\section}{\@startsection {section}{1}{\z@}%
                                   {-3.5ex \@plus -1ex \@minus -.2ex}%
                                   {2.3ex \@plus.2ex}%
                                   {\normalfont\large\bfseries}}%
\renewcommand{\subsection}{\@startsection{subsection}{2}{\z@}%
                                     {-3.25ex\@plus -1ex \@minus -.2ex}%
                                     {1.5ex \@plus .2ex}%
                                     {\normalfont\normalsize\bfseries}}%
\renewcommand{\subsubsection}{\@startsection{subsubsection}{3}{\z@}%
                                     {-3.25ex\@plus -1ex \@minus -.2ex}%
                                     {1.5ex \@plus .2ex}%
                                     {\normalfont\normalsize\bfseries}}%

\let\old@bibliography\bibliography
\renewcommand{\bibliography}[1]{%
    \onehalfspace\par
    \old@bibliography{#1}%
}%

\renewcommand{\maketitle}{%
    \begin{singlespace}%
    {%
        \pagestyle{empty}%
        \titlepage
    }%
    \end{singlespace}%
    % Body starts here
    % It is vital that we switch numbering BEFORE clearing to start a new page,
    % since clearing it before numbering is switched may produce an erroneous
    % blank page.  This way that page never gets created.
    \pagenumbering{arabic}%
    \clearpage
}%

\newcommand{\makesignature}{%
    \begin{singlespace}%
    {%
        \pagestyle{empty}%
        \signaturepage
    }%
    \end{singlespace}%
    % Body starts here
    % It is vital that we switch numbering BEFORE clearing to start a new page,
    % since clearing it before numbering is switched may produce an erroneous
    % blank page.  This way that page never gets created.
    \pagenumbering{arabic}%
    \clearpage
}%

% Set up default document settings
\AtBeginDocument{%
    % Check to make sure at least one document type has been set.
    % Previous code in the option declarations above will check that
    % no more than one is set.
    \if@thesis\else%
      \if@areaexam\else%
        \if@dissertation\else%
          \ClassError{byuprop}%
            {You must choose a document type}%
            {Exactly one of the ms, areaexam, and phd options must be selected}%
    \fi\fi\fi%
    \pagestyle{plain}%
    \pagenumbering{arabic}%
    \parindent \@defaultindent
    % Set up double spacing---this is safe because the overall document is
    % single-spaced and we'll set up single spacing as the default in maketitle
    % where spacing matters.
    \doublespace%
}%

\AtEndDocument{%
    \if@thesis%
      \makesignature%
    \fi%
    \if@dissertation%
    \  \makesignature%
    \fi%
}%

//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// *                                                                  *
// * Parts of this code which have been  developed by QinetiQ Ltd     *
// * under contract to the European Space Agency (ESA) are the	      *
// * intellectual property of ESA. Rights to use, copy, modify and    *
// * redistribute this software for general public use are granted    *
// * in compliance with any licensing, distribution and development   *
// * policy adopted by the Geant4 Collaboration. This code has been   *
// * written by QinetiQ Ltd for the European Space Agency, under ESA  *
// * contract 17191/03/NL/LvH (Aurora Programme). 		      *
// *                                                                  *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
#ifndef G4EMDissociationCrossSection_h
#define G4EMDissociationCrossSection_h 1
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//
// MODULE:		G4EMDissociationCrossSection.hh
//
// Version:		B.1
// Date:		15/04/04
// Author:		P R Truscott
// Organisation:	QinetiQ Ltd, UK
// Customer:		ESA/ESTEC, NOORDWIJK
// Contract:		17191/03/NL/LvH
//
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//
// CHANGE HISTORY
// --------------
//
// 17 October 2003, P R Truscott, QinetiQ Ltd, UK
// Created.
//
// 15 March 2004, P R Truscott, QinetiQ Ltd, UK
// Beta release
//
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
////////////////////////////////////////////////////////////////////////////////
//
#include "G4VCrossSectionDataSet.hh"
#include "G4DynamicParticle.hh"
#include "G4Element.hh"
#include "G4ParticleDefinition.hh"
#include "G4EMDissociationSpectrum.hh"
#include "G4PhysicsFreeVector.hh"
#include "globals.hh"
////////////////////////////////////////////////////////////////////////////////
//
class G4EMDissociationCrossSection : public G4VCrossSectionDataSet
{
  public:
    G4EMDissociationCrossSection ();
    ~G4EMDissociationCrossSection ();

    virtual G4bool IsApplicable (const G4DynamicParticle *, const G4Element *);
 
    virtual G4double GetCrossSection (const G4DynamicParticle *,
      const G4Element *, G4double);
      
    G4PhysicsFreeVector *GetCrossSectionForProjectile
      (G4double, G4double, G4double, G4double, G4double, G4double);
    G4PhysicsFreeVector *GetCrossSectionForTarget
      (G4double, G4double, G4double, G4double, G4double, G4double);
    G4double GetWilsonProbabilityForProtonDissociation
      (G4double, G4double);
    virtual void BuildPhysicsTable (const G4ParticleDefinition &)
    {}
    virtual void DumpPhysicsTable (const G4ParticleDefinition &)
    {G4cout << "G4EMDissociationCrossSection: uses formula" <<G4endl;}

  private:

  private:
    G4EMDissociationSpectrum *thePhotonSpectrum;
    G4double                 r0;
    G4double                 J;
    G4double                 Qprime;
    G4double                 epsilon;
    G4double                 xd;
};
////////////////////////////////////////////////////////////////////////////////
//
#endif
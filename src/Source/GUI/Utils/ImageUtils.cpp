//
//  ImageUtils.cpp
//  TDS
//
//  Created by Corentin Comte on 01/12/2016.
//
//

#include "ImageUtils.h"

const juce::Image ImageUtils::BarbecueGC = juce::Image(juce::ImageCache::getFromMemory(BarbecueGc::barbeuc_gc_jpg, BarbecueGc::barbeuc_gc_jpgSize));
const juce::Image ImageUtils::InteGC = juce::Image(juce::ImageCache::getFromMemory(SoireeGc::soiree_gc_jpg, SoireeGc::soiree_gc_jpgSize));
const juce::Image ImageUtils::PapetPhelma = juce::Image(juce::ImageCache::getFromMemory(PapetPhelma::papetphelma_jpg, PapetPhelma::papetphelma_jpgSize));
const juce::Image ImageUtils::KfetIntePhelma = juce::Image(juce::ImageCache::getFromMemory(KfetIntePhelma::kfet_int_phelma_jpg, KfetIntePhelma::kfet_int_phelma_jpgSize));
const juce::Image ImageUtils::SoireeAutomne = juce::Image(juce::ImageCache::getFromMemory(SoireeAutomne::soiree_automne_jpg, SoireeAutomne::soiree_automne_jpgSize));

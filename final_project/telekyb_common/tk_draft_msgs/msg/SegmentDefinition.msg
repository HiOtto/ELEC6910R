#
# Copyright 2012 Authors: Johannes Laechele and Thomas Nestmeyer
#
# This file is part of TeleKyb.
#
# TeleKyb is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# TeleKyb is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with TeleKyb. If not, see <http://www.gnu.org/licenses/>.

Header header

#both form the ID of segment:
#(id1,id2) = (id2,id1)
uint8[] id1
uint8[] id2

# Start point of segment
geometry_msgs/Point[] pointSegStart

# End point of segment
geometry_msgs/Point[] pointSegEnd

